package p95;

import java.util.Scanner;

public class SuccessOrFail {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("점수 입력 : ");
		int score = scanner.nextInt();
		if (score>=80) {
			System.out.println("합격입니다.");
		}
		scanner.close();
	}
}
