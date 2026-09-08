from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time
from bs4 import BeautifulSoup
import pandas as pd

# 한국어 컬럼명을 영어로 매핑
column_mapping = {
    '제목': 'Title',
    '지원사항': 'Category',
    '프로그램 기간': 'Period',
    '내용': 'Content'
}

# 지역명 매핑
region_mapping = {
    '서울': '서울특별시',
    '부산': '부산광역시',
    '대구': '대구광역시',
    '인천': '인천광역시',
    '광주': '광주광역시',
    '대전': '대전광역시',
    '울산': '울산광역시',
    '세종': '세종특별자치시',
    '경기': '경기도',
    '경기도': '경기도',
    '강원': '강원도',
    '강원도': '강원도',
    '충북': '충청북도',
    '충청북도': '충청북도',
    '충남': '충청남도',
    '충청남도': '충청남도',
    '전북': '전라북도',
    '전라북도': '전라북도',
    '전남': '전라남도',
    '전라남도': '전라남도',
    '경북': '경상북도',
    '경상북도': '경상북도',
    '경남': '경상남도',
    '경상남도': '경상남도',
    '제주도': '제주특별자치도',
    '제주': '제주특별자치도'
}

def extract_and_format_data_to_dict(html, url):
    soup = BeautifulSoup(html, 'html.parser')
    
    # 데이터를 저장할 두 개의 딕셔너리 초기화
    mapped_columns = {}
    unmapped_columns = {}

    # 'tb04' 클래스의 테이블에서 정보 추출
    table = soup.find('table', {'class': 'tb04'})
    rows = table.find_all('tr') if table else []
    for row in rows:
        th_text = row.find('th').get_text(strip=True) if row.find('th') else None
        td_text = row.find('td').get_text(strip=True) if row.find('td') else None

        # 컬럼명을 영어로 변경하고 딕셔너리에 추가
        if th_text in column_mapping:
            if th_text == '접수 기간' or th_text == '프로그램 기간':
                # 기간 정보를 시작일과 종료일로 분리
                periods = td_text.split(' ~ ')
                if len(periods) == 2:
                    mapped_columns['PeriodS'] = periods[0]
                    mapped_columns['PeriodE'] = periods[1]
                # '접수 기간'이 있다면 바로 처리를 마침
                if th_text == '접수 기간':
                    break
            else:
                mapped_columns[column_mapping[th_text]] = td_text
        else:
            unmapped_columns[th_text] = td_text

    # 'vw_article' 클래스에서 추가 정보 추출
    article = soup.find('div', {'class': 'vw_article'})
    if article:
        article_text = article.get_text(strip=True)
        mapped_columns['Content'] = article_text

    # 지역명 찾기
    location_found = None
    for region, full_region in region_mapping.items():
        if region in mapped_columns.get('Content', ''):
            location_found = full_region
            break
    mapped_columns['Location'] = location_found if location_found else ''

    # 현재 페이지 URL을 Link 값에 할당
    mapped_columns['Link'] = url

    # 매핑된 칼럼과 매핑되지 않은 칼럼을 결합하여 반환
    return {**mapped_columns, **unmapped_columns}


# Chrome 드라이버 초기화 및 페이지 접근
service = Service(ChromeDriverManager().install())
driver = webdriver.Chrome(service=service)
driver.get("https://ccei.creativekorea.or.kr/service/business_list.do?&page=1")
time.sleep(1)

data_list = []

try:
    while True:
        items = driver.find_elements(By.CSS_SELECTOR, "tbody#list_body > tr > td.tb_title > a")
        num_items = len(items)

        for index in range(num_items):
            items = driver.find_elements(By.CSS_SELECTOR, "tbody#list_body > tr > td.tb_title > a")
            item = items[index]

            driver.execute_script(item.get_attribute("onclick"))
            time.sleep(1)

            # 현재 페이지의 URL을 가져옴
            current_url = driver.current_url

            # 페이지 소스 가져오기
            html_content = driver.page_source

            # BeautifulSoup을 사용하여 데이터 추출 및 가공
            extracted_data = extract_and_format_data_to_dict(html_content, current_url)
            data_list.append(extracted_data)  # 리스트에 추가

            driver.back()
            time.sleep(1)

        # 다음 페이지로 이동
        next_button = driver.find_element(By.CSS_SELECTOR, "li > a > img[src='/resources/images/common/btn-next.png']")
        alt_attr = next_button.get_attribute("alt")

        if alt_attr == "맨끝":
            print("마지막 페이지에 도달함")
            break

        next_button.click()
        time.sleep(3)

        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, "tbody#list_body"))
        )

except Exception as e:
    print(f"오류 발생: {e}")

finally:
    driver.quit()

# DataFrame 생성 및 CSV 파일로 저장
# DataFrame 생성 시 명시적으로 칼럼 순서를 지정하고, 누락된 칼럼에 대해 빈 값을 할당
# 명시적으로 정의된 칼럼
explicit_columns = ['Title', 'Category', 'Location', 'PeriodS', 'PeriodE', 'Deadline', 'Hits', 'Link', 'Content']

# DataFrame 생성
df = pd.DataFrame(data_list)

# 명시적으로 정의되지 않은 기타 칼럼들을 찾음
other_columns = [col for col in df.columns if col not in explicit_columns]

# 최종 칼럼 순서: 명시적으로 정의된 칼럼 + 명시적으로 정의되지 않은 기타 칼럼
final_columns_order = explicit_columns + other_columns

# 데드라인(Deadline)과 조회수(Hits) 빈 값으로 설정
df['Deadline'] = ''  # 데드라인 칼럼에 빈 값을 할당
df['Hits'] = ''  # 조회수(Hits) 칼럼에 빈 값을 할당

# 지정된 칼럼 순서대로 DataFrame을 재정렬
df = df.reindex(columns=final_columns_order)

# CSV 파일로 저장
df.to_csv('CCEI_crawl.csv', index=False, encoding='utf-8-sig')