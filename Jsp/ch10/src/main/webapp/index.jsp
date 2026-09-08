<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
	<html>
		<head>
		<meta charset="UTF-8">
		<!-- 
			날짜 : 2025.08.01
			이름 : 서현우
			내용 : 프로젝트 로그와 배포 실습하기
			
			로그
			 - 시스템의 실행과정 및 서비스 개선을 위한 작업
			 - 로그 단계별 기록을 통해 서비스 개선
			 
			라이브러리(Maven 다운로드)
			 - logback-classic-1.5.18.jar
			 - logback-core-1.5.18.jar
			 - slf4j-api-2.0.17.jar
			로그 설정
			 - WEB-INF > classes 폴더 생성 > logback.xml 파일 생성
			 - https://logback.qos.ch/manual/configuration.html 에서 설정 xml 복사
			 
			배포
			 - 이클립스 프로젝트 > export > war 생성
			 -C:\Users\GGG\apache-tomcat-10.1.43\bin\startup.bat 실행 (톰캣서버 이클립스없이 실행하는거)
			 -C:\Users\GGG\apache-tomcat-10.1.43\webapps 폴더에 배포파일(ch10.war) 업로드 후 Deploy(풀리는거) 확인 후 브라우저 확인 
		 -->
	<title>index</title>
	</head>
	<body>
		<h3>프로젝트 로그와 배포</h3>
		
		<h4>Shop</h4>
		<a href="/ch10/shop/customer/list.do">shop/customer crud</a>
		
		<h4>Library</h4>
		<a href = "/ch10/library/book/list.do">book crud</a>
	</body>
</html>