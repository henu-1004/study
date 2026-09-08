<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
//전송데이터 수신
	String id = request.getParameter("id");
	String pw = request.getParameter("pw");
	
	
	//프로젝트 컨텍스트 경로 구하기
	String path = application.getContextPath();
	out.print(path);
	
	//아이디가 abc123이고 비밀번호가 1234일때
	if(id.equals("abc123") && pw.equals("1234")){
		//회원이 맞을경우 쿠키 생성
		Cookie cookie = new Cookie("username",id); //키-밸류 쿠기 생성(키는 유저네임, 밸류는 아이디)
		cookie.setMaxAge(60*3);//쿠키수명 3분
		cookie.setPath(path);//쿠키 유효 범위
		
		Cookie cookie2 = new Cookie("userpass", pw);
		cookie2.setMaxAge(60*1);
		cookie2.setPath(path);
		
		//응답객체로 클라이언트 쿠키 전송
		response.addCookie(cookie);
		response.addCookie(cookie2);
		
		//리다이렉트(페이지 이동)
		response.sendRedirect("./resultCooke.jsp");
	}
	else{
		//회원이 아닐경우
		response.sendRedirect("../cookie.jsp");
	}


%>