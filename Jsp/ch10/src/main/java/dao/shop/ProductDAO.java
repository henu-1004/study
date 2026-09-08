package dao.shop;

import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import dto.shop.ProductDTO;
import util.DBHelper;

public class ProductDAO extends DBHelper{
	
	//dao는 기본 싱글톤
	private static final ProductDAO instance = new ProductDAO();
	
	public static ProductDAO getInstance() {
		return instance;
	}
	
	private ProductDAO() {}
	
	private final String DBCP = "jdbc/shop";
	
	//로거생성
	private Logger logger = LoggerFactory.getLogger(this.getClass());
	
	public void insertProduct(ProductDTO dto) {
	
	}
	
	public ProductDTO selectProduct(String pno) {
		return null;
	}
	
	public List<ProductDTO> selectAllProduct(){
		return null;
	}
	
	public void updateProduct(ProductDTO dto) {
		
	}
	
	public void deleteProduct(String pno) {
		
	}
}
