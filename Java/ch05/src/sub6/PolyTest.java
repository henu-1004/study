package sub6;

/* 날짜 : 2025.07.15
 * 이름 : 서현우
 * 내용 : 다형성 실습하기
 * 
 * 다형성(Polymorphism)
 *  - 상속관계에서 부모클래스의 기능이 자식클래스에서 다양한 형태로 변하는 특징
 *  - 객체 생성할때 타입선언을 부모클래스 타입으로 선언(업캐스팅)
 *  - 다형성을 통해서 프로그래밍의 중복코드 줄이고 유연성 향상
 */

public class PolyTest {
	
	public static void printSound(Pet pet) {
		pet.makeSound();
	}
	
	public static void main(String[] args) {
		/*Animal a = new Animal();
		Eagle e = new Eagle();
		Tiger t = new Tiger();
		Shark s = new Shark();*/
		
		// 다형성 - 자식객체의 타입선언을 부모타입으로 선언
		Animal a = new Animal();
		Animal e = new Eagle(); //업캐스팅
		Animal t = new Tiger(); //업캐스팅
		Animal s = new Shark(); //업캐스팅
		
		a.move();
		
		e.move();
		e.hunt();
		
		t.move();
		t.hunt();
		
		s.move();
		s.hunt();
		
		//다운캐스팅 - 부모타입의 객체를 자식타입으로 캐스팅(형변환)하는것
		System.out.println("다운캐스팅 연습");
		Tiger tiger = (Tiger)t;
		Eagle eagle = (Eagle)e;
		Shark shark = (Shark)s;
		
		t.move();
		t.hunt();
		
		e.move();
		e.hunt();
		
		s.move();
		s.hunt();
		
		System.out.println("객체배열 연습");
		//다형성을 활용한 객체 배열
		Animal arr[] = {t,e,s};
		
		arr[0].move();
		arr[1].move();
		arr[2].move();
		
		//Pet 다형성
		Dog dog = new Dog();
		Cat cat = new Cat();
		//다형성으로 이렇게하면 자식메서드에서 정의했기때문에 잘 실행됨
		printSound(dog); 
		printSound(cat);
		
	}

}
