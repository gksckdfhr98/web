package kr.or.connect.reservation.dto;

import java.util.List;

public class ReservationInfo {
	private boolean cancelYn;
	private String createDate;
	private DisplayInfo displayInfo;
	private int displayInfoId;
	private String modifyDate;
	private int productId;
	private String reservationDate;
	private String reservationEmail;
	private int reservationInfoId;
	private String reservationName;
	private String reservationTelephone;
	private int totalPrice;
	public ReservationInfo() {
		super();
		// TODO Auto-generated constructor stub
	}
	public ReservationInfo(boolean cancelYn, String createDate, DisplayInfo displayInfo, int displayInfoId,
			String modifyDate, int productId, String reservationDate, String reservationEmail, int reservationInfoId,
			String reservationName, String reservationTelephone, int totalPrice) {
		super();
		this.cancelYn = cancelYn;
		this.createDate = createDate;
		this.displayInfo = displayInfo;
		this.displayInfoId = displayInfoId;
		this.modifyDate = modifyDate;
		this.productId = productId;
		this.reservationDate = reservationDate;
		this.reservationEmail = reservationEmail;
		this.reservationInfoId = reservationInfoId;
		this.reservationName = reservationName;
		this.reservationTelephone = reservationTelephone;
		this.totalPrice = totalPrice;
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
	public DisplayInfo getDisplayInfo() {
		return displayInfo;
	}
	public void setDisplayInfo(DisplayInfo displayInfo) {
		this.displayInfo = displayInfo;
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
	public int getTotalPrice() {
		return totalPrice;
	}
	public void setTotalPrice(int totalPrice) {
		this.totalPrice = totalPrice;
	}
	@Override
	public String toString() {
		return "ReservationInfo [cancelYn=" + cancelYn + ", createDate=" + createDate + ", displayInfo=" + displayInfo
				+ ", displayInfoId=" + displayInfoId + ", modifyDate=" + modifyDate + ", productId=" + productId
				+ ", reservationDate=" + reservationDate + ", reservationEmail=" + reservationEmail
				+ ", reservationInfoId=" + reservationInfoId + ", reservationName=" + reservationName
				+ ", reservationTelephone=" + reservationTelephone + ", totalPrice=" + totalPrice + "]";
	}
	
	
}
