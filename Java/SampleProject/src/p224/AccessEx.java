package p224;

class Sample{
	public int a;
	private int b;
	int c;
	protected int d;
}


class Sub extends Sample{
	public void method() {
		this.d = 10;
	}
	
}

public class AccessEx {
	public static void main(String[] args) {
		Sample sample = new Sample();
		sample.a=10;
		//sample.b=10;//private라 에러발생
		sample.c=10;
	}
}
