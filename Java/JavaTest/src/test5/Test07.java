package test5;

//로또번호 연습문제

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Test07 {
	public static void main(String[] args) {
		
		for(int count = 1; count <=5; count++) {
			System.out.println(makeLotto());
		}
	}
	
	public static Set makeLotto() {
		Set lottoSet = new HashSet<>();
		
		for(;;) {
			int num = (int) Math.ceil(Math.random()*100);
			lottoSet.add(num);
			
			if((int)lottoSet.size()==6) {
				break;
			}
		}
		//정렬을 위해 TreeSet사용
		Set<Integer> treeSet = new TreeSet<Integer>(lottoSet);
		
		return treeSet;
	}
}
