package sub4;

/*
 * 날짜 : 2025.07.15
 * 이름 : 서현우
 * 내용 : 상속(Inheritance) 실습하기
 */


public class InheritTest {
	
	public static void main(String[] args) {
		
		Sedan sonata = new Sedan("소나타", "흰색", 0, 2000);
		sonata.speedUp(80);
		sonata.turbo();
		sonata.speedDown(20);
		sonata.show();
		
		Truck bongo = new Truck("봉고", "남색", 0, 0);
		bongo.load(100);
		bongo.speedUp(80);
		bongo.speedDown(20);
		bongo.show();
		
		//StockAccount 실습
		StockAccount kb = new StockAccount("KB증권", "102-22-0100", "홍길동", 10000, "삼성전자", 10, 100000);
		kb.deposit(1000000);
		kb.withdraw(50000);
		kb.buy(5, 80000);
		kb.show();
		
		kb.sell(5, 90000);
		kb.show();
		
		//Person클래스
		
		Person man = new Person("aaa", 12);
		man.work();
		man.introduce();
		
		//Doctor클래스
		Doctor dr = new Doctor("김유신", 30, "내과");
		dr.work();
		
		//Engineer클래스
		Engineer e = new Engineer("김춘추", 20, "자동차");
		e.work();
	}

}
