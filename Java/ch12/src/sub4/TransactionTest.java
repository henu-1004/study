package sub4;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Scanner;

//Transaction실습하기
public class TransactionTest {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.print("에러를 발생 시키겠습니까?");
		
		int answer =sc.nextInt();
		
		//DB정보
		String host = "jdbc:oracle:thin:@localhost:1521:xe"; //고유한 주소체계임
		String user = "bank";
		String pass = "1234";
		
		Connection conn =null;
		
		try {
			conn = DriverManager.getConnection(host, user, pass);
			
			//자동커밋 해제(트랜잭션 시작)
			conn.setAutoCommit(false);
			
			
			String sql1 = "update account set acc_balance= acc_balance - 10000 where acc_cid=?";
			String sql2 = "update account set acc_balance= acc_balance + 10000 where acc_cid=?";
			
			PreparedStatement psmt1 = conn.prepareStatement(sql1);
			psmt1.setString(1, "730423-1000001");
			
			PreparedStatement psmt2 = conn.prepareStatement(sql2);
			psmt2.setString(1, "830513-2000003");
			
			psmt1.executeUpdate();
			
			if(answer==1) {
				throw new Exception("에러가 발생했습니다.");
			}
			
			psmt2.executeUpdate();
			
			conn.commit();//트랜잭션 작업 확정 (트랜잭션 실행)
			
			psmt1.close();
			psmt2.close();
			conn.close();
		} 
		catch (Exception e) {
			e.printStackTrace();
			
			try {
				//트랜잭션 작업 취소
				conn.rollback();
			} 
			catch (SQLException e1) {
				e1.printStackTrace();
			}
			
		}
		
		System.out.println("프로그램 종료...");
	}
	
}
