package kr.or.connect.reservation.dto;

public class ReservationUserCommentImage {
	int id;
	int reservationInfoId;
	int reservationUserCommentId;
	int FileId;
	public ReservationUserCommentImage() {
		super();
		// TODO Auto-generated constructor stub
	}
	public ReservationUserCommentImage(int id, int reservationInfoId, int reservationUserCommentId, int fileId) {
		super();
		this.id = id;
		this.reservationInfoId = reservationInfoId;
		this.reservationUserCommentId = reservationUserCommentId;
		FileId = fileId;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getReservationInfoId() {
		return reservationInfoId;
	}
	public void setReservationInfoId(int reservationInfoId) {
		this.reservationInfoId = reservationInfoId;
	}
	public int getReservationUserCommentId() {
		return reservationUserCommentId;
	}
	public void setReservationUserCommentId(int reservationUserCommentId) {
		this.reservationUserCommentId = reservationUserCommentId;
	}
	public int getFileId() {
		return FileId;
	}
	public void setFileId(int fileId) {
		FileId = fileId;
	}
	@Override
	public String toString() {
		return "ReservationUserCommentImage [id=" + id + ", reservationInfoId=" + reservationInfoId
				+ ", reservationUserCommentId=" + reservationUserCommentId + ", FileId=" + FileId + "]";
	}
	
}
