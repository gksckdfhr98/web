package kr.or.connect.reservation.dto;

import java.util.List;

public class ProductResponse {
	private List<Product> items;
	private int totalCount;
	public ProductResponse() {
		super();
		// TODO Auto-generated constructor stub
	}
	public ProductResponse(List<Product> items, int totalCount) {
		super();
		this.items = items;
		this.totalCount = totalCount;
	}
	public List<Product> getItems() {
		return items;
	}
	public void setItems(List<Product> items) {
		this.items = items;
	}
	public int getTotalCount() {
		return totalCount;
	}
	public void setTotalCount(int totalCount) {
		this.totalCount = totalCount;
	}
	@Override
	public String toString() {
		return "ProductResponse [items=" + items + ", totalCount=" + totalCount + "]";
	}
	
	
}
