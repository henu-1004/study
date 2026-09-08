package dto.shop;

public class ProductDTO {
	private String pno;
	private String pName;
	private int stock;
	private int price;
	private String company;
	public String getPno() {
		return pno;
	}
	public void setPno(String pno) {
		this.pno = pno;
	}
	public String getpName() {
		return pName;
	}
	public void setpName(String pName) {
		this.pName = pName;
	}
	public int getStock() {
		return stock;
	}
	public void setStock(int stock) {
		this.stock = stock;
	}
	public int getPrice() {
		return price;
	}
	public void setPrice(int price) {
		this.price = price;
	}
	public String getCompany() {
		return company;
	}
	public void setCompany(String company) {
		this.company = company;
	}
	@Override
	public String toString() {
		return "ProductDTO [pno=" + pno + ", pName=" + pName + ", stock=" + stock + ", price=" + price + ", company="
				+ company + "]";
	}
	
}
