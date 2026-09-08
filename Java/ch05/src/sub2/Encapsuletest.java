package sub2;

/*
 * 날짜 : 2025.07.14
 * 이름 : 서현우
 * 내용 : 캡슐화 실습하기
 * 
 * 캡슐화(정보은닉, Encapsulation)
 * - 캡슐화는 객체의 속성을외부에서 참조하지 못하게 객체의 속성을 은닉하는 특성
 * - 클래스의 속성을 반드시 private 으로 선언
 * - private 선언을 하면 생성자(Constructor)로 속성을 초기화
 * - 은닉된 정보(속성)를 안전하게 사용하기 위해 Getter, Setter 사용
 */

public class Encapsuletest {
	
	public static void main(String[] args) {
		
		//객체생성
		//초기화 - 은닉된 속성(멤버변수)은 생성자(constructor)로 초기화
		Car sonata = new Car("소나타", "흰색", 0); //생성자호출
		
		sonata.speedUp(80);
		sonata.speedDown(20);
		sonata.show();
		
		//객체 생성과 초기화
		Car avante = new Car("아반테", "검정색", 0);
		avante.speedUp(60);
		avante.speedDown(20);
		avante.show();
		
		//개별 속성이 은닉되어 있기 때문에 속성수정 불가, Setter로 수정
		avante.setColor("남색");
		
		avante.show();
		
		//Account 객체 생성과 초기화
		
		Account kb = new Account("국민은행", "101-11-1001", "김유신", 10000);
		kb.deposit(20000);
		kb.show();
		kb.setName("김유진");
		kb.show();
		
		Account wr = new Account("우리은행", "101-21-2001", "김춘추", 30000);
		wr.deposit(20000);
		wr.show();
		wr.setBank("너희은행");
		wr.show();
		
		
		Book book1 = new Book("삼국지", "나관중", "10001", 10);
		book1.show();
		
		boolean isOk=book1.borrowBook();
		
		if(isOk) {
			System.out.println(book1.getTitle()+"도서대출 성공");
		}
		else {
			System.out.println(book1.getTitle()+"도서 대출 실패");
		}
		
		book1.show();
		
		Book book2 = new Book("명품 Java", "황기태", "10002", 1);
		
		boolean isOk1 = book2.borrowBook();
		boolean isOk2 = book2.borrowBook();
		
		if(isOk2) {
			System.out.println(book2.getTitle()+"도서대출 성공");
		}
		else {
			System.out.println(book2.getTitle()+"도서 대출 실패");
		}
		
		book2.show();
		
		
	}
}
