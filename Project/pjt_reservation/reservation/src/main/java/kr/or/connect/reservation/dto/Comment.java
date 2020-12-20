package kr.or.connect.reservation.dto;

import java.util.List;

public class Comment {
	private String comment;
	private int commentId;
	private List<CommentImage> commentImages;
	private String createDate;
	private String modifyDate;
	private int productId;
	private String reservationDate;
	private String reservationEmail;
	private int ReservationInfoId;
	private String reservationName;
	private String reservationTelephone;
	private double score;
	public Comment() {
	}
	public Comment(String comment, int commentId, List<CommentImage> commentImages, String createDate,
			String modifyDate, int productId, String reservationDate, String reservationEmail, int reservationInfoId,
			String reservationName, String reservationTelephone, double score) {
		super();
		this.comment = comment;
		this.commentId = commentId;
		this.commentImages = commentImages;
		this.createDate = createDate;
		this.modifyDate = modifyDate;
		this.productId = productId;
		this.reservationDate = reservationDate;
		this.reservationEmail = reservationEmail;
		ReservationInfoId = reservationInfoId;
		this.reservationName = reservationName;
		this.reservationTelephone = reservationTelephone;
		this.score = score;
	}
	@Override
	public String toString() {
		return "Comment [comment=" + comment + ", commentId=" + commentId + ", commentImages=" + commentImages
				+ ", createDate=" + createDate + ", modifyDate=" + modifyDate + ", productId=" + productId
				+ ", reservationDate=" + reservationDate + ", reservationEmail=" + reservationEmail
				+ ", ReservationInfoId=" + ReservationInfoId + ", reservationName=" + reservationName
				+ ", reservationTelephone=" + reservationTelephone + ", score=" + score + "]";
	}
	public String getComment() {
		return comment;
	}
	public void setComment(String comment) {
		this.comment = comment;
	}
	public int getCommentId() {
		return commentId;
	}
	public void setCommentId(int commentId) {
		this.commentId = commentId;
	}
	public List<CommentImage> getCommentImages() {
		return commentImages;
	}
	public void setCommentImages(List<CommentImage> commentImages) {
		this.commentImages = commentImages;
	}
	public String getCreateDate() {
		return createDate;
	}
	public void setCreateDate(String createDate) {
		this.createDate = createDate;
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
		return ReservationInfoId;
	}
	public void setReservationInfoId(int reservationInfoId) {
		ReservationInfoId = reservationInfoId;
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
	public double getScore() {
		return score;
	}
	public void setScore(double score) {
		this.score = score;
	}
}
