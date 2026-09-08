package sub2;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

//자바 Insert 실습하기
public class InsertTest {
	public static void main(String[] args) {

		//DB정보
		String host = "jdbc:oracle:thin:@localhost:1521:xe"; //고유한 주소체계임
		String user = "sho5223";
		String pass = "1234";
		
		Connection conn =null;
		
		try {
			//데이터베이스 접속
			conn = DriverManager.getConnection(host,user,pass);
		
			//SQL실행 객체 생성(Statement, PreparedStatement) 두가지가 있음
			Statement stmt = conn.createStatement();
		
			//SQL 실행
			String sql = "Insert Into User1 Values ('J102','김춘추','010-1212-2222','30')";
			stmt.executeUpdate(sql); //인서트문임
		
			//결과 처리(SELECT문일 경우)
			
			
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		finally {
			//데이터베이스 종료
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
			
		}
		System.out.println("Insert 완료...");
		
		
	}
}
