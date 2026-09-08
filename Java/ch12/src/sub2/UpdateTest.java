package sub2;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class UpdateTest {
	
	public static void main(String[] args) {
		//DB정보
		String host = "jdbc:oracle:thin:@localhost:1521:xe"; //고유한 주소체계임
		String user = "sho5223";
		String pass = "1234";
		
		try {
			
			//db접속
			Connection conn =DriverManager.getConnection(host,user,pass);
			
			//sql실행객체생성
			Statement stmt = conn.createStatement();
			
			//sql실행
			String sql = "update user1 set age=35 where user_id='J101'";
			stmt.executeUpdate(sql);
			
			//결과처리(셀렉문일때) 지금은 x
			 
			//db종료
			stmt.close();
			conn.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		System.out.println("update 완료...");
	}
	
	
	
}
