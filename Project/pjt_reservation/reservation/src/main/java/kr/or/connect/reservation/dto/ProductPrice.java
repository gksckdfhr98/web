package kr.or.connect.reservation.dto;

public class ProductPrice {
	private String createDate;
	private double discountRate;
	private String modifyDate;
	private int price;
	private String priceTypeName;
	private int productId;
	private int productPriceId;
	public ProductPrice() {
		super();
		// TODO Auto-generated constructor stub
	}
	public ProductPrice(String createDate, double discountRate, String modifyDate, int price, String priceTypeName,
			int productId, int productPriceId) {
		super();
		this.createDate = createDate;
		this.discountRate = discountRate;
		this.modifyDate = modifyDate;
		this.price = price;
		this.priceTypeName = priceTypeName;
		this.productId = productId;
		this.productPriceId = productPriceId;
	}
	public String getCreateDate() {
		return createDate;
	}
	public void setCreateDate(String createDate) {
		this.createDate = createDate;
	}
	public double getDiscountRate() {
		return discountRate;
	}
	public void setDiscountRate(double discountRate) {
		this.discountRate = discountRate;
	}
	public String getModifyDate() {
		return modifyDate;
	}
	public void setModifyDate(String modifyDate) {
		this.modifyDate = modifyDate;
	}
	public int getPrice() {
		return price;
	}
	public void setPrice(int price) {
		this.price = price;
	}
	public String getPriceTypeName() {
		return priceTypeName;
	}
	public void setPriceTypeName(String priceTypeName) {
		this.priceTypeName = priceTypeName;
	}
	public int getProductId() {
		return productId;
	}
	public void setProductId(int productId) {
		this.productId = productId;
	}
	public int getProductPriceId() {
		return productPriceId;
	}
	public void setProductPriceId(int productPriceId) {
		this.productPriceId = productPriceId;
	}
	@Override
	public String toString() {
		return "ProductPrice [createDate=" + createDate + ", discountRate=" + discountRate + ", modifyDate="
				+ modifyDate + ", price=" + price + ", priceTypeName=" + priceTypeName + ", productId=" + productId
				+ ", productPriceId=" + productPriceId + "]";
	}
	
	
}
