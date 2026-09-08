<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>내장객체 스코프</title>
		<!-- 
			내장객체 scope 실습하기
		 -->
	</head>
	<body>
		<h3>내장 객체 scope 실습하기</h3>
		<%
			//내장객체 값 설정
			pageContext.setAttribute("name","김유신");		
			request.setAttribute("name","김춘추");		
			session.setAttribute("name","장보고");		
			application.setAttribute("name","강감찬");		
		%>
		<h4>내장객체 값 확인</h4>
		<p>
			pageContext 값 : <%=pageContext.getAttribute("name") %><br/>
			request 값 : <%=request.getAttribute("name") %><br/>
			session 값 : <%=session.getAttribute("name") %><br/>
			application 값 : <%=application.getAttribute("name") %><br/>
		</p>
		
		<%
			//포워드 페이지에서 내장객체 값 확인
			pageContext.forward("./proc/resultScope.jsp");
		
		%>	
	</body>
</html>