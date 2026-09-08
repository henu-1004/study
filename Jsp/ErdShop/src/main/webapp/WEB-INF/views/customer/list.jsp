<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="jakarta.tags.core" %>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>shop/customer::list</title>
	</head>
	<body>
		<h3>회원 목록</h3>
		
		<a href="/shopApp">처음으로</a>
		<a href="/shopApp/customer/register.do">등록하기</a>
		
		<table border="1">
			<tr>
				<th>아이디</th>
				<th>이름</th>
				<th>휴대폰</th>
				<th>주소</th>
				<th>가입일</th>
				<th>관리</th>
				
			</tr>
			<!--<c:forEach var = "customer" items="${dtoList }">
			<tr>
				<!--<td>${customer.cid }</td>
				<td>${customer.name }</td>
				<td>${customer.hp }</td>
				<td>${customer.address }</td><!--  표현언어에서 getter 호출안하고 직접 속성 참조해서 출력가능 -->
				<!--<td>${customer.rdate}</td>
				<td>
					<!--  수정하고자 하는 사용자 아이디를 modify.jsp로 전송 -->
					<!--<a href="/ch10/shop/customer/modify.do?cid=${customer.cid }">수정</a>
					<a href="/ch10/shop/customer/delete.do?cid=${customer.cid }">삭제</a>
				</td>-->
			<!--</tr>
			</c:forEach>-->
			<tr>
				<td>111</td>
				<td>111</td>
				<td>111</td>
				<td>111</td>
				<td>111</td>
				<td>					
					<a href="">수정</a>					
					<a href="">삭제</a>
				</td>
			</tr>
		</table>		
	</body>
</html>