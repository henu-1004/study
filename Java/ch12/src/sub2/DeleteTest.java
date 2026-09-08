package sub2;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class DeleteTest {
	
	public static void main(String[] args) {
		//DB정보
		String host = "jdbc:oracle:thin:@localhost:1521:xe"; //고유한 주소체계임
		String user = "sho5223";
		String pass = "1234";
		
		
		try {
			//데이터베이스 연결
			Connection conn =DriverManager.getConnection(host,user,pass);
			
			//sql 실행 객체 생성
			Statement stmt = conn.createStatement();
			
			//sql 실행
			String sql = "DELETE from user1 where user_id='J101'";
			stmt.executeUpdate(sql);
			
			//결과처리(select일때)
			
			
			//데이터베이스 종료
			stmt.close();
			conn.close();
			
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("delete완료...");
	}
}
