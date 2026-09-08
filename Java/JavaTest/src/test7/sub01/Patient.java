package test7.sub01;

public class Patient {
	private String name;
	private String id;
	private int age;
	private String diagnosis;
	
	public Patient(String name, String id, int age, String diagnosis) {
		super();
		this.name = name;
		this.id = id;
		this.age = age;
		this.diagnosis = diagnosis;
	}

	@Override
	public String toString() {
		return "- Patient [name=" + name + ", id=" + id + ", age=" + age + ", diagnosis=" + diagnosis + "]";
	}
	

}
