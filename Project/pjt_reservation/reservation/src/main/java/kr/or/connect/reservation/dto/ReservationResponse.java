package kr.or.connect.reservation.dto;

import java.util.List;

public class ReservationResponse {
	private boolean cancelYn;
	private String createDate;
	private int displayInfoId;
	private String modifyDate;
	private List<ReservationPrice> prices;
	private int productId;
	private String reservationDate;
	private String reservationEmail;
	private int reservationInfoId;
	private String reservationName;
	private String reservationTelephone;
	public ReservationResponse() {
		super();
		// TODO Auto-generated constructor stub
	}
	public ReservationResponse(boolean cancelYn, String createDate, int displayInfoId, String modifyDate,
			List<ReservationPrice> prices, int productId, String reservationDate, String reservationEmail,
			int reservationInfoId, String reservationName, String reservationTelephone) {
		super();
		this.cancelYn = cancelYn;
		this.createDate = createDate;
		this.displayInfoId = displayInfoId;
		this.modifyDate = modifyDate;
		this.prices = prices;
		this.productId = productId;
		this.reservationDate = reservationDate;
		this.reservationEmail = reservationEmail;
		this.reservationInfoId = reservationInfoId;
		this.reservationName = reservationName;
		this.reservationTelephone = reservationTelephone;
	}
	public boolean isCancelYn() {
		return cancelYn;
	}
	public void setCancelYn(boolean cancelYn) {
		this.cancelYn = cancelYn;
	}
	public String getCreateDate() {
		return createDate;
	}
	public void setCreateDate(String createDate) {
		this.createDate = createDate;
	}
	public int getDisplayInfoId() {
		return displayInfoId;
	}
	public void setDisplayInfoId(int displayInfoId) {
		this.displayInfoId = displayInfoId;
	}
	public String getModifyDate() {
		return modifyDate;
	}
	public void setModifyDate(String modifyDate) {
		this.modifyDate = modifyDate;
	}
	public List<ReservationPrice> getPrices() {
		return prices;
	}
	public void setPrices(List<ReservationPrice> prices) {
		this.prices = prices;
	}
	public int getProductId() {
		return productId;
	}
	public void setProductId(int productId) {
		this.productId = productId;
	}
	public String getReservationDate() {
		return reservationDate;
	}
	public void setReservationDate(String reservationDate) {
		this.reservationDate = reservationDate;
	}
	public String getReservationEmail() {
		return reservationEmail;
	}
	public void setReservationEmail(String reservationEmail) {
		this.reservationEmail = reservationEmail;
	}
	public int getReservationInfoId() {
		return reservationInfoId;
	}
	public void setReservationInfoId(int reservationInfoId) {
		this.reservationInfoId = reservationInfoId;
	}
	public String getReservationName() {
		return reservationName;
	}
	public void setReservationName(String reservationName) {
		this.reservationName = reservationName;
	}
	public String getReservationTelephone() {
		return reservationTelephone;
	}
	public void setReservationTelephone(String reservationTelephone) {
		this.reservationTelephone = reservationTelephone;
	}
	@Override
	public String toString() {
		return "ReservationResponse [cancelYn=" + cancelYn + ", createDate=" + createDate + ", displayInfoId="
				+ displayInfoId + ", modifyDate=" + modifyDate + ", prices=" + prices + ", productId=" + productId
				+ ", reservationDate=" + reservationDate + ", reservationEmail=" + reservationEmail
				+ ", reservationInfoId=" + reservationInfoId + ", reservationName=" + reservationName
				+ ", reservationTelephone=" + reservationTelephone + "]";
	}
	
	
}
