<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>error</title>
	</head>
	<body>
		<h3>에러 발생 페이지</h3>
		<%
			int num1 = 2;
			int num2 = 1;
			int num3 = 0;
			
			int result = num1/num2;
			int result2 = num1/num3;
		%>
		<p>
			결과1 : <%= result %>
			결과2 : <%= result2 %>
		</p>
	</body>
</html>