<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="jakarta.tags.core" %>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>library/book::list</title>
	</head>
	<body>
		<h3>library/book 목록</h3>
		
		<a href="/ch10">처음으로</a>
		<a href="/ch10/library/book/register.do">등록하기</a>
		
		<table border="1">
			<tr>
				<th>아이디</th>
				<th>제목</th>
				<th>저자</th>
				<th>출판사</th>
				<th>대출가능여부</th>
				<th>등록일</th>
			</tr>
			<tr>
		</table>		
	</body>
</html>