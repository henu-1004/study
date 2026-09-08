package sub1;

/*
 * 날짜 : 2025/07/07
 * 이름 : 서현우
 * 내용 : 변수 실습하기 
 */
public class VariableTest {
	
	public static void main(String[] args) {
		//변수(Variable)
		int a = 3; //변수 선언 및 초기화
		int b = 7;
		System.out.println("a:"+a);
		System.out.println("b:"+b);
		System.out.printf("%d, %d\n", a, b);
		System.out.println(a+b);
		//재할당
		a=5;
		System.out.println("재할당 a:"+a);
			
		//상수(Constant) > 한번 초기화된 값으로 고정하는것 > final키워드 사용, 대문자 표기
		final int NUM = 10;
		//num = 11; 상수는 초기화 된 값으로 고정 되기 때문에 재할당 안됨
		System.out.println("NUM:"+NUM);

	}

}
