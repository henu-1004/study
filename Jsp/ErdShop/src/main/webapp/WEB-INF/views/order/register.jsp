<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>shop/customer::register</title>
	</head>
	<body>
		<h3>shop/order 등록</h3>
		
		<a href="/shopApp">처음으로</a>
		<a href="/shopApp/order/list.do">목록이동</a>
		
		<form action="/shopApp/order/register.do" method="post">
			<table border="1">
				<tr>
					<td>주문번호</td>
					<td><input type="text" name="orderno" placeholder="주문번호 입력"/></td>
				</tr>
				<tr>
					<td>주문id</td>
					<td><input type="text" name="name" placeholder="주문 id 입력"/></td>
				</tr>
				<tr>
					<td>주문개수</td>
					<td><input type="text" name="hp" placeholder="휴대폰 입력(- 포함)"/></td>
				</tr>
				<tr>
					<td>나이</td>
					<td><input type="text" name="address" placeholder="주소 입력"/></td>
				</tr>
				<tr>
					<td>등록일</td>
					<td><input type="date" name="rdate"/></td>
				</tr>
				<tr>					
					<td colspan="2" align="right">
						<input type="submit" value="등록하기"/>
					</td>
				</tr>			
			</table>
			
		
		
		</form>		
				
	</body>
</html>