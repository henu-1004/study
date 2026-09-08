<%@page import="vo.User1Vo"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
	String user_id = request.getParameter("user_id");
	
	String host = "jdbc:oracle:thin:@localhost:1521:xe"; 
	String user = "sho5223"; 
	String pass = "1234";

	User1Vo vo = null;
	
	try{
		Class.forName("oracle.jdbc.driver.OracleDriver");
		
		Connection conn = DriverManager.getConnection(host,user,pass);
		
		String sql = "select * from user2 where user_id=?";
		PreparedStatement psmt = conn.prepareStatement(sql);
		psmt.setString(1,user_id);
		
		ResultSet rs = psmt.executeQuery();
		if(rs.next()){
			vo = new User1Vo();
			vo.setUser_id(rs.getString(1));
			vo.setName(rs.getString(2));
			vo.setHp(rs.getString(3));
			vo.setAge(rs.getInt(4));
		}
		rs.close();
		psmt.close();
		conn.close();
	}
	catch(Exception e){
		e.printStackTrace();
	}

%>



<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>modify.jsp</title>
	</head>
	<body>
		<h3>Here is Modify Page</h3>
		<a href="../jdbc.jsp">처음으로</a>
		<a href="./list.jsp">목록이동</a>
		
		<form action="#" method="post">
			<table border="1">
				<tr>
					<td>아이디</td>
					<td><input type="text" name = "user_id" readonly value = "<%=vo.getUser_id() %>" placeholder="아이디 입력"/></td>
				</tr>
				<tr>
					<td>이름</td>
					<td><input type="text" name = "name" value="<%=vo.getName() %>" placeholder="이름입력"/></td>
				</tr>	
			
			
			</table>
		
		
		</form>
		
	</body>
</html>