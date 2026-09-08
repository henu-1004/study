package sub2;
/*
 * 날짜 : 2025/07/07
 * 이름 :서현우
 * 내용 : 자바 변수 자료형 실습하기
 */
public class DataTypeTest {
	public static void main(String[] args) {
		
		//정수형
		byte num1 = 127; //-128~127까지, 1byte
		short num2 = 32767; //2byte
		char num3 = 32767; //2byte (97=a)
		int num4 = 214748367; //4byte
		long num5 = 9_223_372_036_854_775_807L; // '_'로 끊어서 볼수잇고, L은 접미사임
		
		System.out.println("num1 : "+num1);
		System.out.println("num2 : "+num2);
		System.out.println("num3 : "+num3);
		System.out.println("num4 : "+num4);
		System.out.println("num5 : "+num5);
		
		//실수형
		float var1 = 0.123456789f; //f라는 접미사 붙여야함, 소수점 8자리, 4byte
		double var2 = 0.1234567890123456789;//소수점 17자리, 8byte
		
		System.out.println("var1 : " + var1);
		System.out.println("var2 : " + var2);
		
		//논리형
		boolean value1 = true;
		boolean value2 = false;
		
		System.out.println("value1:"+value1);
		System.out.println("value2:"+value2);
		
		//문자형
		char ch1 = 'A';
		char ch2 = '갉';
		
		System.out.println("ch1 : "+ch1);
		System.out.println("ch2 : "+ch2);
		
		int n1 = ch1; //char는 정수형타입이라서 int로 대입가능, 형변환 가능
		System.out.println("n1:"+n1);
		
		//문자열
		String str1 = "abc";
		String str2 = "qqq";
		String str3 = "A"; //문자 하나도 가능하긴함
		String str4 = "가을"; 
		System.out.println("str1:" + str1);
		System.out.println("str2:" + str2);
		System.out.println("str3:" + str3);
		System.out.println("str4:" + str4);
	}
}
