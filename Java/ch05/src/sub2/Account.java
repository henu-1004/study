package sub2;

public class Account {
		
		public Account(String bank, String id, String name, int balance) {
			this.bank=bank;
			this.id=id;
			this.name=name;
			this.balance=balance;
		}
	
		
		//속성
		private String bank;
		private String id;
		private String name;
		private int balance;
		
		//기능
		public void deposit(int money) {
			this.balance+=money;
		}//입금
		
		public void withdraw(int money) {
			this.balance-=money;
		}//출금
		
		public void show() {
			System.out.println("---------------");
			System.out.println("은행명 :" + this.bank);
			System.out.println("계좌번호 :" + this.id);
			System.out.println("입금주 :" + this.name);
			System.out.println("현재잔액 :" + this.balance);
			System.out.println("---------------");
		}
		
		public void setBalance(int balance) {
			this.balance = balance;
		}
		public void setBank(String bank) {
			this.bank = bank;
		}
		public void setId(String id) {
			this.id = id;
		}
		public void setName(String name) {
			this.name = name;
		}
}
