package util;

public class Sql {
	

	// customer
	public final static String SELECT_CUSTOMER_BY_NO_AND_NAME = "SELECT * FROM BANK_CUSTOMER WHERE C_NO=? AND C_NAME=?";
	
	public final static String SELECT_CUSTOMER_WITH_ACCOUNT_NO="select c.*,a.a_no "
			+ "from bank_customer c join bank_account a on c.c_no = a.a_c_no "
			+ "where c_no = ?";
	
	
	// account
	public final static String SELECT_ALL_ACCOUNT_WITH_NAME = "select a.*, c.c_name "// 마지막띄어쓰기
															+ "from bank_account a " // 마지막띄어쓰기
															+ "join bank_customer c on a.a_c_no = c.c_no";
	
	public final static String UPDATE_ACCOUNT_PLUS = "update bank_account set a_balance = a_balance+? where a_no = ?";
	public final static String UPDATE_ACCOUNT_MINUS ="update bank_account set a_balance = a_balance-? where a_no = ?";
	
	
	
	//transaction
	public final static String INSERT_TRANSACTION = "insert into bank_transaction (T_a_no, t_dist, t_amount, t_datetime) values(?,?,?,sysdate)";
	
}
