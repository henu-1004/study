package sub5;

/* 날짜 : 2025.07.15
 * 이름 : 서현우
 * 내용 : 메서드 오버라이딩 실습하기
 */

class AAA{
	public void method1() {
		System.out.println("AAA:method1...");
	}
	public void method2() {
		System.out.println("AAA:method2...");
	}
	public void method3() {
		System.out.println("AAA:method3...");
	}
}

class BBB extends AAA{
	
	@Override
	public void method2() {
		//부모클래스 method3를 override하기 때문에 어노테이션 @Override표시
		System.out.println("BBB:method2...");
	}
public void method3(int a) {
		System.out.println("BBB:method3...");//오버라이딩 x, 오버로딩임
	}
}

class CCC extends BBB{
	
	@Override
	public void method1() {
		System.out.println("CCC:method1...");
	}
	
	@Override
	public void method2() {
		System.out.println("CCC:method2...");
	}
	
	public void method3(int a, int b) {
		System.out.println("CCC:method3..."); //오버라이딩 x, 오버로딩임
	}
}


public class MethodOverridingTest {
	
	public static void main(String[] args) {
		
		//오버라이드 메서드 실습
		CCC c = new CCC();
		c.method1();
		c.method2();
		c.method3();
		c.method3(1);
		c.method3(1,2);
		
		//Sedan 클래스 오버라이드 메서드 실습
		Sedan sonata = new Sedan("소나타","흰색", 0, 2000);
		sonata.speedUp(2000);
		sonata.show();
		
		
	}
	
}
