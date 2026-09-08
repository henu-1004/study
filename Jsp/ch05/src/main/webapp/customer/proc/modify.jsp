<%@page import="javax.naming.InitialContext"%>
<%@page import="javax.sql.DataSource"%>
<%@page import="javax.naming.Context"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@page import="java.sql.DriverManager"%>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
	// 전송 데이터 수신
	String cid = request.getParameter("cid");
	String name = request.getParameter("name");
	String hp = request.getParameter("hp");
	String rdate = request.getParameter("rdate");
	String address = request.getParameter("address");
	
	// 데이터베이스 INSERT
	String host = "jdbc:oracle:thin:@localhost:1521:xe"; 
	String user = "sho5223"; 
	String pass = "1234";
	
	try {
		//자바 기본 환경객체 검색(was 환경)
		Context ctx = (Context) new InitialContext().lookup("java:comp/env"); //환경객체 생성
		DataSource ds = (DataSource)ctx.lookup("jdbc/sho5223"); //jdbc/sho5223 커넥션 풀 객체 검색 이전에 만든 13개의 커넥션들어있는 커넥션 풀
				
		Connection conn = ds.getConnection();
		// SQL 실행 객체 생성
		String sql = "Update customer set name=?, hp=?, rdate=?, address=? where cid=?";
		//만약 stmt였다면 "update user1 set name='"+name+"', hp="+hp+"', age="+" "; 이렇게함 
		PreparedStatement psmt = conn.prepareStatement(sql);
		psmt.setString(1, name);
		psmt.setString(2, hp);
		psmt.setString(3, rdate);
		psmt.setString(4, address);
		psmt.setString(5, cid);
		
		// SQL 실행
		psmt.executeUpdate();
		
		// 데이터베이스 종료
		psmt.close();
		conn.close();
		
	}catch(Exception e){
		e.printStackTrace();
	}
	
	// 목록이동
	response.sendRedirect("../list.jsp");
%>