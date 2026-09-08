package step03;

import java.util.Scanner;

/*
 * 날짜 : 2025.07.10
 * 이름 : 서현우
문제
n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n (1 ≤ n ≤ 10,000)이 주어진다.

출력
1부터 n까지 합을 출력한다.
 */
public class Main03 {

	public static void main(String[] args) {
		int n ,sum = 0;
		Scanner sc = new Scanner(System.in);
		n=sc.nextInt();
		for(int i=1; i<=n; i++) {
			sum+=i;
		}
		System.out.println(sum);
		sc.close();


	}

}
