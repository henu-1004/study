package p101;

import java.util.Scanner;

public class GradingSwitch {

		public static void main(String[] args) {
			Scanner scanner = new Scanner(System.in);
			
			char grade;
			System.out.print("점수 입력(0~100) : ");
			int score = scanner.nextInt();
			switch(score/10) {
			case 10:
			case 9:
				grade = 'a';
				break;
			case 8:
				grade = 'b';
				break;
			
			case 7:
				grade = 'c';
				break;
			
			case 6:
				grade = 'd';
				break;
			default:
				grade='f';
			}
			
			System.out.println("학점 : "+grade);
			
			scanner.close();
		}
}
