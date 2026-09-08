package sub2;

/*
 * 날짜 : 2025/07/07
 * 이름 : 서현우
 * 내용 : Java 다양한 출력 실습
 */
public class PrintTest {
	
	public static void main(String[] args) {
		
		//기본출력
		System.out.println("Hello Java!"); //한줄복사 ctrl+alt+방향키아래(위)
		System.out.println("Hello Korea!"); //한줄삭제 ctrl+d
		System.out.println("Hello Busan!");
		
		//한줄출력
		System.out.print("Welcome");
		System.out.print(" Java!");
		System.out.println();
		
		//개행 출력
		System.out.println(); //줄바꿈
		System.out.print("Welcome\n"); // \n : 개행 이스케이프 특수문자
		System.out.println("Korea!");
		System.out.println("first line \n second line");
	}
	
}
