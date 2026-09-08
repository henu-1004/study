package test6;

public class Test02 {
	public static void main(String[] args) {
		int count = 0;
		for(int i = 0 ; i < 7 ; i ++) {
			
			if(i<=3) {
				count++;
			}
			else {
				count --;
			}
			
			for(int j = 1; j < 5 - count; j++) {
				System.out.print("☆");
			}
			
			for(int k = 1; k<=(i<=3?count+i :count*2-1) ; k++) {
				System.out.print("★");
			}
			
			for(int j=1; j<5-count; j++) {
				System.out.print("☆");
			}
			System.out.println();
		}
		System.out.println();
	}
}
//1 3 5 7 5 3 1 >> i=0,cnt1, i=1 cnt2, i=2 cnt3, i3 cnt4, i4 cnt3, i5 cnt2, i6 cnt1)
//4 > 5
//5 > 3
//6 > 1