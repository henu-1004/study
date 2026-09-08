<%@page import="vo.UserVO"%>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
	//자동로그인여부 확인
	Cookie[] cookies = request.getCookies();
	if(cookies != null){
		for(Cookie cookie : cookies){
			
			if(cookie.getName().equals("auto")){//getname은 key를 반환
				
				String id = cookie.getValue();
	
				//사용자 객체 생성
				UserVO vo = new UserVO();
				vo.setId(id);
				
				//세션 처리
				session.setAttribute("sessUser", vo);
				
				//로그인 성공 페이지 이동
				response.sendRedirect("./proc/sessionSuccess.jsp");
				return;
				
			}
		}
	}
	//쿠키로 auto로그인을 지정했고, 껐다켜도 쿠키로 인해서
	//새로운 세션으로 기존의 id를 통해로그인하는거(사용자 로그인 상태를 복원하는거)
	/*
	✔ 페이지를 열면서 요청이 발생하고,
	✔ 요청에는 쿠키가 자동 포함되며,
	✔ 서버는 쿠키를 통해 자동 로그인 여부 확인 후,
	✔ 세션에 사용자 정보 저장하고,
	✔ 로그인 완료 페이지로 리디렉션하는 구조입니다.
	*/
%>


<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>session</title>
        <%--
        날짜: 2025/07/29
        이름: 서현우
        내용 : jsp 세션 실습하기

        --%>
    </head>
    <body>
    <h3>session 실습</h3>
	
	<h4>session ID 확인</h4>
	<p>
		session : <%= session.getId() %><br/>
		request session : <%=request.getSession().getId() %>
	</p>
	
	<h4>session 로그인</h4>
    <form action ="./proc/sessionLogin.jsp" method="post">
        <input type ="text" name ="id" placeholder ="아이디 입력"/><br/>
        <input type ="password" name ="pw" placeholder ="비밀번호 입력"/><br/>
        <label><input type = "checkbox" name="auto" value="true"/>자동로그인</label>
        <input type ="submit" value ="로그인"/>
    </form>

    </body>
</html>