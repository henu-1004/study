package test4.sub4;

public class Book {
	
	private String title; 
	private String author;
	private String isbn;
	private boolean isBorrowd;
	
	public Book(String title, String author,String isbn) {
		this.isBorrowd=false;
		this.title=title;
		this.author=author;
		this.isbn=isbn;
	}
	
	public void borrowBook() {
		if(!isBorrowd) {
			System.out.println("도서 대출 : " + title);
			this.isBorrowd=true;
		}
		else {
			System.out.println(this.title+"이미대출됨");
		}
			
		
	}
	
	public void returnBook() {
		if(isBorrowd) {
			System.out.println("도서 반납 : " + title);
		}
	}
	
	public void getBookInfo() {
		System.out.println("제목 : " + title);
		System.out.println("저자 : " + author);
		System.out.println("ISBN : " + isbn);
		System.out.println("대출여부 : " + (isBorrowd ? "불가능" : "가능"));
	}
	
	public String getTitle() {
		return title;
	}
	
	
}
