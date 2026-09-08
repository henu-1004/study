package test5;

import java.util.ArrayList;
import java.util.List;

//객체 리스트 문제

class Member{
	String id;
	String name;
	int age;
	public Member(String id, String name, int age) {
		this.id = id;
		this.name = name;
		this.age = age;
	}
	@Override
	public String toString() {
		return id + ", "+ name + ", " + age;
	}
	
}
public class Test08 {
	public static void main(String[] args) {
		Member m1 = new Member("a101", "김유신",23);
		Member m2 = new Member("a102", "김춘추",21);
		Member m3 = new Member("a103", "장보고",33);
		
		
		List<Member> memberList = new ArrayList<Member>();
		memberList.add(m1);
		memberList.add(m2);
		memberList.add(m3);
		
		for(Member m : memberList) {
			System.out.println(m);
		}
		
	}
}
