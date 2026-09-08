package sub2;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.stream.Stream;


/*
 * 날짜 :  205.07.24
 * 이름 : 서현우
 * 내용 : 자바 컬렉션 스트림 실습하기
 */

class Person{
	private String name;
	private int age;
	
	public Person(String name, int age) {
		super();
		this.name = name;
		this.age = age;
	}
	
	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}
	
}

public class CollcetionStreamTest {

	public static void main(String[] args) {
		
		List<String> persons = new ArrayList<>();
		
		persons.add("김유신");
		persons.add("김춘추");
		persons.add("장보고");
		persons.add("강감찬");
		persons.add("이순신");
		
		//외부 반복자를 이용한 출력
		System.out.println("외부반복자");
		Iterator<String> it = persons.iterator();
		while(it.hasNext()) {
			System.out.println(it.next());
		}
		
		for(String person : persons) {
			System.out.println(person);
		}
		
		//내부 반복자를 이용한 출력
		System.out.println("내부반복자");
		
		Stream<String> stream = persons.stream();
		stream.forEach((person) ->{
			System.out.println(person);
		});
		
		//내부반복자는 아래 형식으로 더 많이쓰임
		persons.stream().forEach((person) -> {
			System.out.println(person);
		});
		
		List<Person> people = new ArrayList<Person>();
		people.add(new Person("김유신",23));
		people.add(new Person("김춘추",21));
		people.add(new Person("장보고",33));
		people.add(new Person("강감찬",43));
		people.add(new Person("이순신",53));
		
		
		people.stream().forEach((p) ->{
			System.out.println(p);
		});
		
		people.stream().forEach(System.out::println);
	}
}
