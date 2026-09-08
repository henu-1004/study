package sub4;

public class Person {
	protected String name;
	protected int age;
	
	public Person(String name, int age) {
		this.name=name;
		this.age=age;
	}
	
	public void work() {
		System.out.println("Person is working");
	}
	
	public void introduce() {
		System.out.printf("제 이름은 [%s] 이고 나이는 [%d]세입니다.\n", name, age);
	}
	
	
}
