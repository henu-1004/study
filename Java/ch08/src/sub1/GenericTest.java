package sub1;

public class GenericTest {
	public static void main(String[] args) {
		
		Apple apple = new Apple("한국", 3000);
		Banana banana = new Banana("대만", 2000);
		
		//치환 변수 t를 apple로 치환
		FruitBox<Apple> box1 = new FruitBox<Apple>(); 
		box1.setFriut(apple);
		
		
		FruitBox<Banana> box2 = new FruitBox<Banana>();
		box2.setFriut(banana);
		
		System.out.println(box1.getFriut());
		System.out.println(box2.getFriut());
		
	}
}
