package test4.sub5;

public class Subject {
	
	private String subName; 
	private Student[] students;
	private int studentCount;
	
	public Subject(String subName) {
		this.subName=subName;
		this.students = new Student[10];
		this.studentCount=0;
	}
	
	public void addStudent(Student student) {
		studentCount++;
		for(int i=0; i<studentCount; i++) {
			if(this.students[i]==null) {
				this.students[i]=student;
			}
		}
	}
	
	public void printSubjectInfo() {
		System.out.println("과목명 : " +this.subName);
		System.out.printf("수강생 : ");

		for(int i=0; i<studentCount; i++) {
			System.out.printf("%s ",  this.students[i].getName());
		}
		System.out.println("");
	}
	
	public String getName() {
		return this.subName;
	}
	
	
}
