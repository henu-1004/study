<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="jakarta.tags.core" %>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>user1::list</title>
		
		<script>
			document.addEventListener('DOMContentLoaded', function(){
				
				const table = document.getElementsByTagName('table')[0];
				
				// 목록 데이터 요청
				fetch('/ch09/js/user1/getUser1All.do')
					.then(res => res.json())
					.then(data => {						
						console.log(data);
						
						for(const user of data){
							
							const tr = `<tr>
											<td>\${user.user_id}</td>
											<td>\${user.name}</td>
											<td>\${user.hp}</td>
											<td>\${user.age}</td>
											<td>
												<a href='#' class='modify' data-uid='\${user.user_id}'>수정</a>
												<a href='#' class='remove' data-uid='\${user.user_id}'>삭제</a>
											</td>
										</tr>`;									
							
							table.insertAdjacentHTML('beforeEnd', tr);							
						}
					})
					.catch(err => {
						console.log(err);
					});
				
				/*동적 이벤트 처리
				- 동적으로 생성되는 태그는 이벤트 처리를 할 수 없음
				- 동적이벤트 처리를 위해 document 문서객체로 이벤트 구현
				-특정문서객체를 대상으로 이벤트 처리
				const modifies = document.getElementsByClassName('modify');
				console.log(modifies);
				
				modifies[0].addEventListener('click', function(e){
					e.preventDefault();
				})alert('click!!!');
				
				*/
				//그래서 아래처럼 수행
				document.addEventListener('click',function(e){
					e.preventDefault();
					
					//수정클릭
					if(e.target.classList == 'modify'){
						alert('modify click!');
						
						//사용자 정의 속성(data-로 시작하는)으로 수정 아이디 가져오기
						const uid = e.target.dataset.uid;
						
						
						//수정페이지 이동
						location.href = '/ch09/js/user1/modify.do?uid='+uid;
					}
					//alert('document click!');
					
					
					//삭제클릭
					if(e.target.classList == 'remove'){
						
						//삭제에정 문서객체
						const tr = e.target.closest('tr'); //가장 가까운 상위 tr태그 > this > 는 이벤트가 발생한 a태그일것 > remove가 클릭된 녀석의 가장 가까운 tr을 삭제할것이다.
						
						//삭제아이디 가져오기
						const uid = e.target.dataset.uid;
						
						//삭제요청하기
						fetch('/ch09/js/user1/delete.do?uid='+uid)
							.then(res=>res.json())
							.then(data=>{
								console.log(data);
								
								if(data.result>0){
									alert('삭제 완료');
								}
								else{
									alert('삭제 실패');
								}
								
								//새로고침 -> 불필요한 요청이 발생
								//location.reload();
								
								//삭제한 문서객체 제거
								tr.remove();		
								
								
							})
							.catch(err=>{
								console.log(err)
							});
					}
				});
				
			});		//domcontentloaded 끝
			
		</script>		
	</head>
	<body>
		<h3>JS/User1 목록</h3>
		
		<a href="/ch09">처음으로</a>
		<a href="/ch09/js/user1/register.do">등록하기</a>
		
		<table border="1">
			<tr>
				<th>아이디</th>
				<th>이름</th>
				<th>휴대폰</th>
				<th>나이</th>
				<th>관리</th>
			</tr>			
		</table>		
	</body>
</html>