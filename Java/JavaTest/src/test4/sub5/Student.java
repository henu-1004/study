package test4.sub5;

public class Student {
	
	private String name;
	private String studentId;
	private Subject[] subjects;
	private int[] scores;
	private int subjectCount;
	
	public Student(String name, String studentId) {
		this.name=name;
		this.studentId=studentId;
		this.subjects=new Subject[10];
		this.scores= new int[10];
		this.subjectCount=0;
	}
	
	public void enrollSubject(Subject sub) {
		this.subjects[subjectCount]=sub;
		subjectCount++;
		sub.addStudent(this);
		System.out.println(this.name+" - " + sub.getName() + "과목 신청 완료");
	}
	
	public void setScore(Subject sub, int score) {
		for (int i = 0; i<10; i++) {
			if(sub==subjects[i]) { //equals쓰는게 좋음
				scores[i]=score;
				System.out.println(this.name+ " - " + sub.getName()+ "점수 입력 완료");
				break;
			}
		}
	}
	
	public void printStudentInfo() {
		System.out.println("학생이름 : "+name);
		System.out.println("학생id : "+studentId);
		System.out.println("성적");
		for(int i=0; i<subjectCount; i++) {
			System.out.printf("- %s : %d\n", subjects[i].getName(), scores[i]);
		}
	}
	
	public String getName() {
		return this.name;
	}
}
