package sub2;

import java.io.ObjectInputStream.GetField;

public class Book {
	
	//속성
	private String title;
	private String author;
	private String isbn;
	private int availableCopies;
	
	//생성자
	public Book(String title, String author, String isbn, int availableCopies) {
		this.title = title;
		this.author = author;
		this.isbn = isbn;
		this.availableCopies=availableCopies;
	}
	
	public boolean borrowBook() {
		if(this.availableCopies>0) {
			availableCopies--;
			return true;
		}
		else {
			return false;
		}
	}
	
	public void returnBook() {
		availableCopies++;
	}
	
	public void show() {
		System.out.println("title : " + title);
		System.out.println("author : " + author);
		System.out.println("isbn : " + isbn);
		System.out.println("availableCopies : " + availableCopies);
	}
	
	
	//getter
	public String getAuthor() {
		return author;
	}
	public String getIsbn() {
		return isbn;
	}
	public String getTitle() {
		return title;
	}
	public int getAvailableCopies() {
		return availableCopies;
	}
	
	
	//setter
	public void setAuthor(String author) {
		this.author = author;
	}
	public void setAvailableCopies(int availableCopies) {
		this.availableCopies = availableCopies;
	}
	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}
	public void setTitle(String title) {
		this.title = title;
	}
}
