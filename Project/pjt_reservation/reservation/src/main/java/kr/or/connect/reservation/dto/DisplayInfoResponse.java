package kr.or.connect.reservation.dto;

import java.util.List;

public class DisplayInfoResponse {
	private double averageScore;
	private List<Comment> comments;
	private DisplayInfo displayInfo;
	private DisplayInfoImage displayInfoImage;
	private List<ProductImage> productImages;
	private List<ProductPrice> productPrices;
	public DisplayInfoResponse() {
		super();
		// TODO Auto-generated constructor stub
	}
	public DisplayInfoResponse(double averageScore, List<Comment> comments, DisplayInfo displayInfo,
			DisplayInfoImage displayInfoImage, List<ProductImage> productImages,
			List<ProductPrice> productPrices) {
		super();
		this.averageScore = averageScore;
		this.comments = comments;
		this.displayInfo = displayInfo;
		this.displayInfoImage = displayInfoImage;
		this.productImages = productImages;
		this.productPrices = productPrices;
	}
	public double getAverageScore() {
		return averageScore;
	}
	public void setAverageScore(double averageScore) {
		this.averageScore = averageScore;
	}
	public List<Comment> getComments() {
		return comments;
	}
	public void setComments(List<Comment> comments) {
		this.comments = comments;
	}
	public DisplayInfo getDisplayInfo() {
		return displayInfo;
	}
	public void setDisplayInfo(DisplayInfo displayInfo) {
		this.displayInfo = displayInfo;
	}
	public DisplayInfoImage getDisplayInfoImage() {
		return displayInfoImage;
	}
	public void setDisplayInfoImage(DisplayInfoImage displayInfoImage) {
		this.displayInfoImage = displayInfoImage;
	}
	public List<ProductImage> getProductImages() {
		return productImages;
	}
	public void setProductImages(List<ProductImage> productImages) {
		this.productImages = productImages;
	}
	public List<ProductPrice> getProductPrices() {
		return productPrices;
	}
	public void setProductPrices(List<ProductPrice> productPrices) {
		this.productPrices = productPrices;
	}
	@Override
	public String toString() {
		return "DisplayInfoResponse [averageScore=" + averageScore + ", comments=" + comments + ", displayInfo="
				+ displayInfo + ", displayInfoImage=" + displayInfoImage + ", productImages=" + productImages
				+ ", productPrices=" + productPrices + "]";
	}
	
	
}
