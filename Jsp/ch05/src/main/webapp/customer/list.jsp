<%@page import="java.util.ArrayList"%>
<%@page import="vo.CustomerDTO"%>
<%@page import="java.util.List"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@page import="javax.naming.InitialContext"%>
<%@page import="javax.sql.DataSource"%>
<%@page import="javax.naming.Context"%>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
	List<CustomerDTO> customers = new ArrayList<>();
	try{
		//자바 기본 환경객체 검색(was 환경)
		//lookup("java:comp/env"): 톰캣 등 WAS의 JNDI 환경 영역에 접근
		//lookup("jdbc/sho5223"): 거기에 등록된 이름 "jdbc/sho5223"인 DataSource(커넥션 풀) 을 꺼냄
		//📌 즉, 이미 톰캣이 jdbc/sho5223라는 이름으로 커넥션 풀을 준비해놨다는 전제가 있어야 해요.
		Context ctx = (Context) new InitialContext().lookup("java:comp/env"); //환경객체 생성
		DataSource ds = (DataSource)ctx.lookup("jdbc/sho5223"); //jdbc/sho5223 커넥션 풀 객체 검색 이전에 만든 13개의 커넥션들어있는 커넥션 풀
		
		Connection conn = ds.getConnection();
		Statement stmt=  conn.createStatement();
		
		ResultSet rs = stmt.executeQuery("select * from customer");
		
		while(rs.next()){
			CustomerDTO dto = new CustomerDTO();
			dto.setCid(rs.getString(1));
			dto.setName(rs.getString(2));
			dto.setHp(rs.getString(3));
			dto.setAddress(rs.getString(4));
			dto.setRdate(rs.getString(5));
			
			customers.add(dto);
		}
		
		//커넥션 반납
		rs.close();
		stmt.close();
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
		<title>Customer::list</title>
	</head>
	<body>
		<h3>Customer 목록</h3>
		
		<a href="../dbcp.jsp">처음으로</a>
		<a href="./register.jsp">등록하기</a>
		
		<table border="1">
			<tr>
				<th>아이디</th>
				<th>이름</th>
				<th>휴대폰</th>
				<th>주소</th>
				<th>등록일</th>
				<th>관리</th>
			</tr>
			<% for(CustomerDTO customer : customers){ %>
			<tr>
				<td><%= customer.getCid() %></td>
				<td><%= customer.getName() %></td>
				<td><%= customer.getHp() %></td>
				<td><%= customer.getAddress() %></td>
				<td><%= customer.getRdate().substring(0,10) %></td>
				<td>
					<a href="/ch05/customer/modify.jsp?cid=<%=customer.getCid()%>">수정</a>
					<a href="/ch05/customer/delete.jsp?cid=<%=customer.getCid()%>">삭제</a>
				</td>
			</tr>
			<%} %>			
		</table>		
	</body>
</html>