package sub3;

import java.io.FileOutputStream;
import java.util.Properties;

/*
 * 프로퍼티스 자료구조 실습
 */

public class PropertiesTest {
	
	public static void main(String[] args) {
		
		//프로퍼티 : 키-값이 모두 문자열인 자료구조 > 맵인데 키벨류 자료형 선언없음
		//Map<String, String> map = new HashMap()랑 같은거
		Properties prop = new Properties();
		prop.setProperty("A", "Apple");
		prop.setProperty("B", "Banana");
		prop.setProperty("C", "Cherry");
		
		System.out.println(prop);
		
		//직렬화 (엄밀히말하면 직렬화는아님)
		String path = "C:\\Users\\GGG\\Desktop\\friut.properties";
		
		try {
			
			FileOutputStream fos = new FileOutputStream(path);
			prop.store(fos,null);
			
			fos.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		System.out.println("프로그램 종료...");
	}
	
}
