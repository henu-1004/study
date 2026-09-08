<%@page import="java.util.ArrayList"%>
<%@page import="vo.User1Vo"%>
<%@page import="java.util.List"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.Connection"%>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
	String host = "jdbc:oracle:thin:@localhost:1521:xe";
	String user = "sho5223";
	String pass = "1234";
	
	List<User1Vo> users = new ArrayList<User1Vo>();
	try{
		Class.forName("oracle.jdbc.driver.OracleDriver");
		Connection conn = DriverManager.getConnection(host, user, pass);
		
		String sql="select * from user2";
		PreparedStatement psmt = conn.prepareStatement(sql);
		Statement stmt = conn.createStatement();
		ResultSet rs = stmt.executeQuery(sql);
		
		while(rs.next()){
			User1Vo vo = new User1Vo();
			vo.setUser_id(rs.getString(1));
			vo.setName(rs.getString(2));
			vo.setHp(rs.getString(3));
			vo.setAge(rs.getInt(4));
			
			users.add(vo);
		}
		rs.close();
		stmt.close();
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
<title>user2List</title>
</head>
<body>
	<h3>User2 목록</h3>
	
	<a href="../jdbc.jsp">처음으로</a>
	<a href="./register.jsp">등록하기</a>
	
	<table border="1">
		<tr>
			<th>아이디</th>
			<th>이름</th>
			<th>휴대폰</th>
			<th>나이</th>
			<th>관리</th>
		</tr>
		<tr>
			<td>예시데이터</td>
			<td>서현우</td>
			<td>010-2</td>
			<td>26</td>
			<td>
				<a href="./modify.jsp">수정띠</a>
				<a href="./delete.jsp">삭제띠</a>
			</td>
		</tr>
		<%for(User1Vo user1 : users){ %>
			<tr>
				<td><%=user1.getUser_id() %></td>
				<td><%=user1.getName() %></td>
				<td><%=user1.getHp() %></td>
				<td><%=user1.getAge() %></td>
				<td>
					<a href="./modify.jsp?user_id=<%=user1.getUser_id()%>">수정띠</a>
					<a href="./delete.jsp?user_id=<%=user1.getUser_id()%>">삭제띠</a>
				</td>
			</tr>
			
		<%} %>
	</table>
</body>
</html>