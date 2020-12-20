package kr.or.connect.reservation.dao;

public class ReviewDaoSqls {
	public static final String SELECT_RESERVATION_USER_COMMENT_ID = "SELECT id FROM reservation_user_comment ORDER BY id desc limit 1";
	public static final String SELECT_FILE_ID = "SELECT id FROM file_info ORDER BY id desc limit 1";
}
