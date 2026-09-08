package sub1;

//클래스 설계(정의)
public class Car {
	
	//속성(멤버 변수)
	String name;
	String color;
	int speed;
	
	//기능(멤버 메서드)
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

}
