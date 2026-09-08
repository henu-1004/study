package dao.shop;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.util.ArrayList;
import java.util.List;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import dto.shop.CustomerDTO;
import util.DBHelper;

public class CustomerDAO extends DBHelper{
	
	private static final CustomerDAO instance = new CustomerDAO();
	
	public static CustomerDAO getInstance() {
		return instance;
	}
	
	private final String DBCP = "jdbc/shop";
	
	private CustomerDAO() {}
	
	//로거 생성
	private Logger logger = LoggerFactory.getLogger(this.getClass());
	
	
	public void insertCumtomer(CustomerDTO dto) {
		
		try {
			conn = getConnection(DBCP);
			
			String sql = "insert into customer values (?,?,?,?,?)";
			psmt = conn.prepareStatement(sql);
			System.out.println("cid" + dto.getCid());
			psmt.setString(1, dto.getCid());
			psmt.setString(2, dto.getName());
			psmt.setString(3, dto.getHp());
			psmt.setString(4, dto.getAddress());
			psmt.setString(5, dto.getRdate());
			psmt.executeUpdate();
			closeAll();
			
			
		}
		catch(Exception e) {
			//e.printStackTrace(); 시스템출력대신 로거로 대체
			logger.error(e.getMessage());
		}
		
		
	}
	public CustomerDTO selectCumtomer(String cid) {
		
		CustomerDTO dto = null;
		
		try {
			conn = getConnection(DBCP);
			
			String sql = "select * from customer where cid=?";
			psmt = conn.prepareStatement(sql);
			psmt.setString(1, cid);
			
			rs= psmt.executeQuery();
			
			if(rs.next()) {
				dto = new CustomerDTO();
				dto.setCid(rs.getString(1));
				dto.setName(rs.getString(2));
				dto.setHp(rs.getString(3));
				dto.setAddress(rs.getString(4));
				dto.setRdate(rs.getString(5));
			}
			
			closeAll();
			
		}catch (Exception e) {
			//e.printStackTrace();
			logger.error(e.getMessage());
		}
		
		
		return dto;
	}
	public List<CustomerDTO> selectAllCumtomer() {
		
		List<CustomerDTO> dtoList = new ArrayList<CustomerDTO>();
		
		try {
			conn = getConnection(DBCP);
			stmt = conn.createStatement();
			
			String sql = "select * from customer";
			rs= stmt.executeQuery(sql);
			
			while(rs.next()) {
				CustomerDTO dto = new CustomerDTO();
				dto.setCid(rs.getString(1));
				dto.setName(rs.getString(2));
				dto.setHp(rs.getString(3));
				dto.setAddress(rs.getString(4));
				dto.setRdate(rs.getString(5));
				
				dtoList.add(dto);
			}
			
			closeAll();
			
		}catch (Exception e) {
			//e.printStackTrace();
			logger.error(e.getMessage());
		}
		return dtoList;
		
	}
	public void updateCumtomer(CustomerDTO dto) {
		
		try {
			
			Context ctx = (Context) new InitialContext().lookup("java:comp/env");
			DataSource ds = (DataSource) ctx.lookup("jdbc/shop");
			
			Connection conn = ds.getConnection();
			
			String sql = "update customer set name=?, hp=?, address=?, rdate=? where cid=?";
			PreparedStatement psmt = conn.prepareStatement(sql);
			psmt.setString(1, dto.getName());
			psmt.setString(2, dto.getHp());
			psmt.setString(3, dto.getAddress());
			psmt.setString(4, dto.getRdate());
			psmt.setString(5, dto.getCid());
			
			psmt.executeUpdate();
			
			psmt.close();
			conn.close();
			
		}
		catch (Exception e) {
			logger.error(e.getMessage());
		}
	}
	public void deleteCumtomer(String cid) {
		try {
			conn = getConnection(DBCP);
			String sql ="delete from customer where cid=?";
			PreparedStatement psmt = conn.prepareStatement(sql);
			psmt.setString(1, cid);
			psmt.executeUpdate();
			
			psmt.close();
			conn.close();
		}
		catch (Exception e) {
			logger.error(e.getMessage());
		}
	}
	
	
}
