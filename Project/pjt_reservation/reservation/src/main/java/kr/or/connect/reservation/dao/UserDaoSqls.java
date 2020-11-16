package kr.or.connect.reservation.dao;

public class UserDaoSqls {
	public static final String SELECT_ALL_BY_EMAIL = "SELECT id, name, password, email, phone, create_date, modify_date, line_token FROM user WHERE email = :email";
	public static final String SELECT_USER_ID = "SELECT id FROM user ORDER BY id desc limit 1";
}
