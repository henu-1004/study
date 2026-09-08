package sub1;

public class FruitBox <T>{ // 제네릭 클래스 FruitBox의 치환변수 T를 선언
	public T friut;
	
	public T getFriut() {
		return friut;
	}
	
	public void setFriut(T friut) {
		this.friut = friut;
	}
	
	
}
