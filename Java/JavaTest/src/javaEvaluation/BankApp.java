package javaEvaluation;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BankApp {
	
	private Scanner scanner = new Scanner(System.in);
	private List<Account> accounts = new ArrayList<Account>();
	
	public static void main(String[] args) {
		BankApp app = new BankApp();
		app.start();
		
		System.out.println("프로그램 종료");
	}
	
	public void start() {
		boolean running = true;
		
		while(running) {
			printMenu();
			System.out.print("선택> ");
			int choice = Integer.parseInt(scanner.nextLine());
			
			switch(choice) {
				case 1 -> createAccount();
				case 2 -> listAccounts();
				case 3 -> depositAccount();
				case 4 -> withdrawAccount();
				case 5 -> {
					running = false;
				}
				default ->System.out.println("올바른 번호를 선택하세요.");
			}
		}
	}
	
	public void printMenu() {
		System.out.println("---------------------------------------------");
		System.out.println("1.계좌생성 | 2.계좌목록 | 3.예금 | 4.출금 | 5.종료");
		System.out.println("---------------------------------------------");
	}
	
	
	
	public void createAccount() {
		System.out.println("---------------계좌 생성---------------");

		System.out.print("계좌번호 : ");
		String ano = scanner.nextLine();
		
		System.out.print("계좌주 : ");
		String owner = scanner.nextLine();
		
		System.out.print("초기입금액 : ");
		int balance = scanner.nextInt();
		scanner.nextLine();
		
		Account ac = new Account(ano,owner,balance);
		accounts.add(ac);
		
		if(ac!=null) {
			System.out.print("결과 : 계좌가 생성되었습니다.\n");
		}
		
	}
	
	public void listAccounts() {
		
		System.out.println("---------------계좌 목록---------------");
		
		for(Account ac : accounts) {
			System.out.printf("%s %s %d\n", ac.getAno(), ac.getOwner(), ac.getBalance());
		}
		
	}
	
	public void depositAccount() {
		System.out.println("--------------- 예금 ---------------");
		
		System.out.print("계좌번호 : ");
		String ano = scanner.nextLine();
		
		System.out.print("예금액 : ");
		int money = scanner.nextInt();
		scanner.nextLine();
		Account ac = this.findAccount(ano);
		int balance;
		if(ac==null) {
			System.out.println("결과 : 계좌가 없습니다.");
		}
		else {
			//find=true;
			balance=ac.getBalance();
			ac.setBalance(balance+money);
			System.out.println("결과 : 예금이 성공되었습니다.");	
		}
	}		
	
	
	public void withdrawAccount() {
		System.out.println("--------------- 출금 ---------------");
		
		System.out.print("계좌번호 : ");
		String ano = scanner.nextLine();
		
		System.out.print("출금액 : ");
		int money = scanner.nextInt();
		scanner.nextLine();
		Account ac = this.findAccount(ano);
		int balance;
		if(ac==null) {
			System.out.println("결과 : 계좌가 존재하지 않습니다.");
		}
		else {
			//find=true;
			balance=ac.getBalance();
			ac.setBalance(balance-money);
			System.out.println("결과 : 출금이 성공되었습니다.");	
		}
	}
	
	public Account findAccount(String ano) {
		Account ac = null;
		for (Account ac1 : accounts) {
			String ano1 = ac1.getAno();
			if(ano1.equals(ano)) {
				ac = ac1;
				break;
			}
		}
		return ac;
	}	

	
	
	
	
}
