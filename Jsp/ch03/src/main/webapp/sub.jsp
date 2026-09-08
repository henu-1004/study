<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
    out.println("[sub.jsp 시작]<br/>");
    out.println("5. sub.jsp pageContext: " + pageContext.hashCode() + "<br/>");
    out.println("6. origin == pageContext? " + (pageContext == pageContext.getAttribute("origin")) + "<br/>");
    out.println("7. msg (서브에서 읽음): " + pageContext.getAttribute("msg") + "<br/>");

    // 메시지 수정
    pageContext.setAttribute("msg", "sub.jsp에서 수정한 메시지");

    out.println("8. msg (수정 후): " + pageContext.getAttribute("msg") + "<br/>");
    out.println("[sub.jsp 끝]<br/>");
%>
