package kr.or.connect.reservation.dao;

public class DisplayInfoDaoSqls {
	public static final String SELECT_COMMENT_IMAGE = "SELECT fi.content_type as contentType, fi.create_date as createDate, fi.delete_flag as deleteFlag, "
			+ "fi.id as fileId, fi.file_name as fileName, ruci.id as imageId, fi.modify_date as modifyDate, ri.id as reservationInfoId, "
			+ "ruc.id as reservationUserCommentId, fi.save_file_name as saveFileName FROM reservation_user_comment_image ruci "
			+ "left join reservation_info ri on ri.id = ruci.reservation_info_id "
			+ "left join reservation_user_comment ruc on ruc.id = ruci.reservation_user_comment_id "
			+ "left join file_info fi on fi.id = ruci.file_id "
			+ "where ruci.reservation_user_comment_id = :id";
	public static final String SELECT_COMMENT = "SELECT ruc.comment as Comment, ruc.id as commentId, ruc.create_date as createDate, "
			+ "ruc.modify_date as modifyDate, p.id as productId, ri.reservation_date as reservationDate, ri.reservation_email as reservationEmail, "
			+ "ri.id as reservationInfoId, ri.reservation_name as reservationName, ri.reservation_tel as reservationTelephone, ruc.score as score "
			+ "FROM reservation_user_comment ruc "
			+ "left join product p on p.id = ruc.product_id "
			+ "left join reservation_info ri on ri.id = ruc.reservation_info_id "
			+ "where ri.display_info_id = :id";
	public static final String SELECT_DISPLAY_INFO = "SELECT c.id as categoryId, c.name as categoryName, di.create_date as createDate, "
			+ "di.id as displayInfoId, di.email as email, di.homepage as homepage, di.modify_date as modifyDate, di.opening_hours as openingHours, "
			+ "di.place_lot as placeLot, di.place_name as placeName, di.place_street as placeStreet, p.content as productContent, "
			+ "p.description as productDescription, p.event as productEvent, p.id as productId, di.tel as telephone FROM display_info di "
			+ "left join product p on p.id = di.product_id "
			+ "left join category c on c.id = p.category_id "
			+ "where di.id = :id";
	public static final String SELECT_DISPLAY_INFO_IMAGE = "SELECT fi.content_type as contentType, fi.create_date as createDate, fi.delete_flag as deleteFlag, "
			+ "di.id as displayInfoId, dii.id as displayInfoImageId, fi.id as fileId, fi.file_name as fileName, fi.modify_date as modifyDate, "
			+ "fi.save_file_name as saveFileName FROM display_info_image dii "
			+ "left join display_info di on di.id = dii.display_info_id "
			+ "left join file_info fi on fi.id = dii.file_id "
			+ "where di.id = :id";
	public static final String SELECT_PRODUCT_IMAGE = "SELECT fi.content_type as contentType, fi.create_date as createDate, fi.delete_flag as deleteFlag, "
			+ "fi.id as fileInfoId, fi.file_name as fileName, fi.modify_date as modifyDate, pi.product_id as productId, pi.id as productImageId, "
			+ "fi.save_file_name as saveFileName, pi.type as Type, p.description as description FROM product_image pi "
			+ "left join file_info fi on fi.id = pi.file_id "
			+ "left join product p on p.id = pi.product_id "
			+ "left join display_info di on di.product_id = p.id "
			+ "where (pi.type='ma' or pi.type='et') and di.id = :id limit 2";
	public static final String SELECT_PRODUCT_PRICE = "SELECT pp.create_date as createDate, pp.discount_rate as discountRate, pp.modify_date as modifyDate, "
			+ "pp.price as price, pp.price_type_name as priceTypeName, pp.product_id as productId, pp.id as productPriceId FROM product_price pp "
			+ "left join product p on p.id = pp.product_id "
			+ "left join display_info di on di.product_id = p.id "
			+ "where di.id = :id";
}
