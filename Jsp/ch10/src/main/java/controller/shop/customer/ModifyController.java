package controller.shop.customer;

import java.io.IOException;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import dto.shop.CustomerDTO;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import service.shop.CustomerService;

@WebServlet("/shop/customer/modify.do")
public class ModifyController extends HttpServlet{
	
	private static final long serialVersionUID = 1L;
	
	//서비스 객체를 가져오기
	private CustomerService service = CustomerService.INSTANCE;
	
	//로거 생성
	private Logger logger = LoggerFactory.getLogger(this.getClass()) ;
	
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		
		//전송데이터 수신
		String cid = req.getParameter("cid");
		
		//수정데이터 조회
		CustomerDTO dto = service.findById(cid);
		logger.info("수정 고객 정보:{}", dto);

		//request객체로 조회 데이터 공유
		req.setAttribute("customer", dto);
		
		RequestDispatcher dispatcher = req.getRequestDispatcher("/WEB-INF/views/shop/customer/modify.jsp");
		dispatcher.forward(req, resp);
		
	}
	
	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		
		//전송데이터 수신
		String cid = req.getParameter("cid");
		String name = req.getParameter("name");
		String hp = req.getParameter("hp");
		String address = req.getParameter("address");
		String rdate = req.getParameter("rdate");
		
		//서비스 전달을 위한 dto생성
		CustomerDTO dto = new CustomerDTO();
		dto.setCid(cid);
		dto.setName(name);
		dto.setHp(hp);
		dto.setAddress(address);
		dto.setRdate(rdate);
		
		//서비스 호출
		service.modify(dto);
		
		//이동
		resp.sendRedirect("/ch10/shop/customer/list.do");
	}
}
