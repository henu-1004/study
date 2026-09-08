package sub3;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import sub2.User1Vo;

//PreparedStatement 실습
public class PreparedSelectTest {
	
	public static void main(String[] args) {
	
		//DB정보
		final String host = "jdbc:oracle:thin:@localhost:1521:xe"; //고유한 주소체계임
		final String user = "sho5223";
		final String pass = "1234";
		
		//조회결과 반환용 리스트 생성
		List<User1Vo> users = new ArrayList<User1Vo>() ;
		
		try {
			//db접속
			Connection conn = DriverManager.getConnection(host, user, pass);
			
			//sql실행객체 생성(PreparedStatement)
			String sql = "select * from user1 where age >= ?";
			PreparedStatement psmt = conn.prepareStatement(sql);
			psmt.setInt(1, 20); //1번째 쿼리 파라미터 (?)에 나이 숫자 20 바인딩
			
			//SQL실행
			ResultSet rs =psmt.executeQuery(); //select실행하기 때문에 executeQuery()로 실행해야 ResultSet반환됨
			
			//결과처리(셀렉의경우)
			while(rs.next()) {
				
				//Vo 객체생성 : VO객체(Value Object)는 데이터베이스에서 조회된 결과로 초기화 된 읽기 전용 객체
				User1Vo vo = new User1Vo();
				vo.setUser_id(rs.getString(1));
				vo.setName(rs.getString(2));
				vo.setHp(rs.getString(3));
				vo.setAge(rs.getInt(4));
				
				users.add(vo);
			}
			
			//데이터베이스종료
			rs.close();
			psmt.close();
			conn.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		for( User1Vo user1 : users) {
			System.out.println(user1);
		}
		
		
		System.out.println("select 완료...");
	}
	
}
