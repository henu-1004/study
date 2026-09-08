package service.shop;

import java.util.List;

import dao.shop.ProductDAO;
import dto.shop.ProductDTO;

public enum ProductService {
	
	Instance;
	
	private ProductDAO dao = ProductDAO.getInstance();
	
	public void register(ProductDTO dto) {
		dao.insertProduct(dto);
	}
	
	public ProductDTO findById(String pno) {
		return dao.selectProduct(pno);
	}
	
	public List<ProductDTO> findAll(){
		return dao.selectAllProduct();
	}
	
	public void modify(ProductDTO dto) {
		dao.updateProduct(dto);
	}
	
	public void delete(String pno) {
		dao.deleteProduct(pno);
	}
	
}
