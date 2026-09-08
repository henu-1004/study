package test4.sub3;

public class MovieTicket {
	
	private String movieTitle; 
	private String screenTime;
	private String seatNumber;
	private boolean isBooked;
	
	public MovieTicket(String movieTitle, String screenTime,String seatNumber) {
		this.isBooked=false;
		this.movieTitle=movieTitle;
		this.screenTime=screenTime;
		this.seatNumber=seatNumber;
	}
	
	public void bookTicket() {
		if(!isBooked) {
			System.out.printf("%s, %s, %s, 예매 완료\n", movieTitle,screenTime, seatNumber);
			isBooked=true;
		}
		else
			System.out.println("이미 예매 됨");
	}
	
	public void cancelBook() {
		if(isBooked) {
			System.out.printf("%s, %s, %s, 취소 완료\n", movieTitle,screenTime, seatNumber);
			isBooked=false;
		}
		else {
			System.out.println("티켓이 예약안되어 있음");
		}
	}
	
	public void printTicketnInfo(){
		System.out.printf("영화제목 : %s\n 상영시간 : %s\n 좌석번호 : %s\n 예약여부 : %s\n", movieTitle, screenTime, seatNumber, isBooked ? "Yes" : "No");
	}
	
	
	
	
	
}
