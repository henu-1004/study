package service.shop;

import java.util.List;

import dao.shop.CustomerDAO;
import dto.shop.CustomerDTO;

//열거형으로 싱글톤 객체 생성
public enum CustomerService {
	
	INSTANCE;
	
	private CustomerDAO dao = CustomerDAO.getInstance();
	
	public void register(CustomerDTO dto) {
		dao.insertCumtomer(dto);
	}
	public CustomerDTO findById(String cid) {
		return dao.selectCumtomer(cid);
	}
	public List<CustomerDTO> findAll() {
		return dao.selectAllCumtomer();
	}
	public void modify(CustomerDTO dto) {
		dao.updateCumtomer(dto);
	}
	public void delete(String cid) {
		dao.deleteCumtomer(cid);
	}
	
}
