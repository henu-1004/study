package service;

import java.util.List;

import dao.User1DAO;
import dto.User1DTO;

/*service
 *  - Controller의 부가적인 비즈니스 처리를 담당 
 *  - Controller의 요청을 받아 DAO를 호출, controller와 dao의 중간 매개 컴포턴트
 
 */
public class User1Service {
	
	//싱글톤
	private static User1Service instance =new User1Service();
	public static User1Service getInstance() {
		return instance;
	}
	private User1Service() {}
	
	private User1DAO dao = User1DAO.getInstance();
	
	//DAO 메서드 호출 - Service에 맞게 네이밍 이것도 json하면서 리턴값 int로 수정 
	public int register(User1DTO dto) {
		return dao.insertUser1(dto);
		
	}
	public User1DTO findById(String user_id) {
		return dao.selectUser1(user_id);
	}
	public List<User1DTO> findAll() {
		return dao.selectAllUser1();
	}
	public int modify(User1DTO dto) {
		return dao.updateUser1(dto);
	}
	public int delete(String user_id) {
		return dao.deleteUser1(user_id);
	}
	
}
