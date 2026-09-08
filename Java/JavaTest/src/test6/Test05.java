package test6;
/*
* 원주율
* - ∏ = 4 x (1/1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ...)
* - 항수가 늘어날수록 정확도가 높아진다. 
*/
public class Test05 {
	public static void main(String[] args) {
		boolean sign = false;
		double pi =0;
		
		for(int i =1 ; i<=10000000; i+=2) {
			
			if(!sign) {
				pi+=1.0/i;
				sign=true;
			}
			else {
				pi-=1.0/i;
				sign=false;
			}
			System.out.printf("i=%d,Pi=%f\n", i, 4*pi);
		}
	}
}
