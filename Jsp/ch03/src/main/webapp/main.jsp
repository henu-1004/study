<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
    pageContext.setAttribute("msg", "main.jsp에서 저장한 메시지");
    pageContext.setAttribute("origin", pageContext);  // 자신 저장

    out.println("<hr/>[main.jsp 시작]<br/>");
    out.println("1. main.jsp pageContext: " + pageContext.hashCode() + "<br/>");
    out.println("2. msg: " + pageContext.getAttribute("msg") + "<br/><br/>");
%>

<jsp:include page="sub.jsp" />

<%
    out.println("<br/><br/>3. [main.jsp 계속 실행 중]<br/>");
    out.println("4. msg (서브 포함 후): " + pageContext.getAttribute("msg") + "<br/>");
    out.println("[main.jsp 끝]<hr/>");
%>
