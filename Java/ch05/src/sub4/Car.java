package sub4;

//클래스 설계(정의)
public class Car {
	
	//속성(멤버 변수) - 속성은 무조건 private 선언한다고 생각하자, 상속관계에서 부모클래스이면 protected로 선언
	private String name;
	private String color;
	protected int speed; // 상속관계에서 자식클래스에서 참조가능하게 접근권한을 protected로 변경
	
	//생성자(Constructor) - 속성을 초기화하는 반환타입이 없고 클래스 명인 메서드
	public Car(String name, String color, int speed) {
		this.name=name;
		this.color=color;
		this.speed=speed;
	}
	
	//기능(멤버 메서드) - 메서드는 무조건 public으로 선언한다고 생각하자(지금은)
	//매개변수랑 멤버변수의 이름이 같으면 this로 구분해줘야함
	public void speedUp(int speed) {
		//this는 자기참조 키워드, 클래스의 멤버변수 참조
		this.speed +=speed;
	}
	
	public void speedDown(int speed) {
		this.speed -=speed;
	}
	
	public void show() {
		System.out.println("차량명 : "+name);
		System.out.println("색깔 : "+color);
		System.out.println("속도 : "+speed);
	}
	
	//Getter,Setter 정의 - 은닉딘 속성을 안전하게 처리하기 위한 메서드
	
	public String getColor() {
		return color;
	}
	
	public void setColor(String color) {
		this.color = color;
	}

}
