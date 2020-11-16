package kr.or.connect.reservation.dao;

public class ReservationDaoSqls {
	public static final String SELECT_ID = "SELECT id FROM reservation_info ORDER BY id desc limit 1";
	public static final String SELECT_RESERVATION_PRICE = "SELECT rip.id, rip.reservation_info_id, rip.product_price_id, rip.count FROM reservation_info_price rip "
			+ "where rip.reservation_info_id = :id";
	public static final String SELECT_PRODUCT_PRICE = "SELECT price FROM product_price where id = :id";
	public static final String SELECT_RESERVATION_INFO = "SELECT ri.cancel_flag as cancelYn, ri.create_date as createDate, ri.display_info_id as displayInfoId, "
			+ "ri.modify_date as modifyDate, ri.product_id as productId, ri.reservation_date as reservationDate, ri.reservation_email as reservationEmail, "
			+ "ri.id as reservationInfoId, ri.reservation_name as reservationName, ri.reservation_tel as reservationTelephone FROM reservation_info ri "
			+ "where ri.reservation_email = :email";
	public static final String SELECT_DISPLAY_INFO = "SELECT c.id as categoryId, c.name as categoryName, di.create_date as createDate, di.id as displayInfoId, "
			+ "di.email as email, di.homepage as homepage, di.modify_date as modifyDate, di.opening_hours as openingHours, di.place_lot as placeLot, "
			+ "di.place_name as placeName, di.place_street as placeStreet, p.content as productContent, p.description as productDescription, p.event as productEvent, "
			+ "p.id as productId, di.tel as telephone FROM display_info di "
			+ "left join product p on p.id = di.product_id "
			+ "left join category c on c.id = p.category_id "
			+ "where di.id = :id";
	public static final String UPDATE_RESERVATION_INFO = "UPDATE reservation_info SET cancel_flag = 1 where id = :id";
	public static final String DELETE_RESERVATION_INFO_PRICE = "DELETE FROM reservation_info_price where reservation_info_id = :id";
	public static final String DELETE_RESERVATION_INFO = "DELETE FROM reservation_info where id = :id";
}
