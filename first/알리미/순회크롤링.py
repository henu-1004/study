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
    '시행기관': 'Agency',
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
    '강원': '강원특별자치도',
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

def extract_and_format_data_to_dict(html):
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
            mapped_columns[column_mapping[th_text]] = td_text
        else:
            unmapped_columns[th_text] = td_text

    # 'Category' 다음에 'Agency' 칼럼을 빈 값으로 추가
    if 'Category' in mapped_columns:
        mapped_columns['Agency'] = ''

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

    # 링크는 현재 설정하지 않음
    mapped_columns['Link'] = ''

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

            # 페이지 소스 가져오기
            html_content = driver.page_source

            # BeautifulSoup을 사용하여 데이터 추출 및 가공
            extracted_data = extract_and_format_data_to_dict(html_content)
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
df = pd.DataFrame(data_list)
df.to_csv('CCEI_crawl.csv', index=False, encoding='utf-8-sig')
