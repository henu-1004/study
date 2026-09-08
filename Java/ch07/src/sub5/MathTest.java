package sub5;


/*
 * 날짜 : 2025.07.22
 * 이름 : 서현우
 * 내용 : 자바 Math 실습
 */


public class MathTest {
	
	public static void main(String[] args) {
		//Math 클래스는 static 메서드로 기능제공
		//Math math = new Math(); 
		System.out.println("절대값 : " + Math.abs(-5));
		System.out.println("절대값 : " + Math.abs(5));
		System.out.println("제곱근 : " + Math.sqrt(9));
		System.out.println("제곱근 : " + Math.sqrt(16));
		System.out.println("올림값 : " + Math.ceil(1.2));
		System.out.println("올림값 : " + Math.ceil(1.8));
		System.out.println("내림값 : " + Math.floor(1.2));
		System.out.println("내림값 : " + Math.floor(1.8));
		System.out.println("반올림 : " + Math.round(1.2));
		System.out.println("반올림: " + Math.round(1.8));
		
		
		//random : 임의의 수
		double num1 = Math.random();
		System.out.println("num1 : " + num1); //0~1사이의 실수
		double num2 = num1*10;
		System.out.println("num2 : " + num2); //0~10 사이의 실수
		
		double num3 = Math.ceil(num2);
		System.out.println(("num3 : " + num3)); // 1~10사이의 정수
		
		//위의 과정을 압축
		double rand=Math.ceil(Math.random()*10);
		System.out.println("rand : " + rand);
		
		//1~46까지 임의의 정수
		double rand2=Math.ceil(Math.random()*46);
		System.out.println("rand2 : " + rand2);
		
	}
	
	
	
	
}
