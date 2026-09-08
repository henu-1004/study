package test4.sub4;

public class Member {
	
	protected String name;
	protected String memberId;
	protected Book borrowedBook;

	public Member(String name, String memberId) {
		this.name=name;
		this.memberId=memberId;
		this.borrowedBook=null;
	}
	
	public void borrowBook(Book book) {
		book.borrowBook();
		this.borrowedBook=book;
	}
	
	public void returnBook(Book book) {
		book.returnBook();
		this.borrowedBook=null;
	}
	
	public void getMemberInfo() {
		System.out.println("이름 : " +  name);
		System.out.println("아이디 : " +  memberId);
		if(this.borrowedBook!=null) {
			System.out.println("대출한 도서 : " +  this.borrowedBook.getTitle());
		}
		else {
			System.out.println("대출한 도서 : 없음");
		}
	}
	
}
