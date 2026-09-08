package sub2;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;


public class SelectTest {
	public static void main(String[] args) {
		//DB정보
		final String host = "jdbc:oracle:thin:@localhost:1521:xe"; //고유한 주소체계임
		final String user = "sho5223";
		final String pass = "1234";
		
		//조회 결과 반환용 리스트 생성
		List<User1Vo> users = new ArrayList<User1Vo>();
		
		try {
			//데이터베이스 접속
			Connection conn = DriverManager.getConnection(host, user, pass);
			
			//sql실행객체 생성
			Statement stmt = conn.createStatement();
			
			//sql 실행
			//select문의 executeQuery()로 실행하고 ResultSet반환!!!
			String sql = "select * from user1";
			ResultSet rs = stmt.executeQuery(sql); //다른건 execute(),executeUpdate()였음
			
			//결과처리(일반적으로 리스트 생성)
			while(rs.next()) {//커서를 다음 row로 이동시킴, 이동할 row가 없으면 false
				
				//커서가 가리키는 Row의 각 컬럼값을 추출해서 VO객체 초기화
				User1Vo vo = new User1Vo();
				vo.setUser_id(rs.getString(1));
				vo.setName(rs.getString(2));
				vo.setHp(rs.getString(3));
				vo.setAge(rs.getInt(4));
				
				users.add(vo);
				
			}
			
			//데이터베이스 종료
			rs.close();
			stmt.close();
			conn.close();
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		
		//리스트 출력
		for(User1Vo user1 : users) {
			System.out.println(user1);
		}
		
		System.out.println("select프로그램 종료...");
	}
}
