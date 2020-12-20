package kr.or.connect.reservation.dao;

public class CategoryDaoSqls {
	public static final String COUNT = "SELECT count(*) FROM category c "
			+ "left join product p on p.category_id = c.id "
			+ "left join display_info di on di.product_id = p.id "
			+ "where c.id = :id";
	public static final String SELECT_ALL = "SELECT c.id, c.name FROM category c";
	public static final String SELECT_PRODUCT = "SELECT di.id as displayInfoId, di.place_name as placeName, p.content as productContent, "
			+ "p.description as productDescription, p.id as productId, fi.save_file_name as productImageUrl FROM category c "
			+ "left join product p on p.category_id = c.id "
			+ "left join display_info di on di.product_id = p.id "
			+ "left join product_image pi on pi.product_id = p.id "
			+ "left join file_info fi on fi.id = pi.file_id "
			+ "where pi.type='th' and c.id = :id";
	public static final String SELECT_PRODUCT_BY_LIMIT = "SELECT di.id as displayInfoId, di.place_name as placeName, p.content as productContent, "
			+ "p.description as productDescription, p.id as productId, fi.save_file_name as productImageUrl FROM category c "
			+ "left join product p on p.category_id = c.id "
			+ "left join display_info di on di.product_id = p.id "
			+ "left join product_image pi on pi.product_id = p.id "
			+ "left join file_info fi on fi.id = pi.file_id "
			+ "where pi.type='th' and c.id = :id limit :start ,:limit";
	public static final String SELECT_PRODUCT_COUNT = "SELECT count(*) FROM category c "
			+ "left join product p on p.category_id = c.id "
			+ "left join display_info di on di.product_id = p.id "
			+ "left join product_image pi on pi.product_id = p.id "
			+ "left join file_info fi on fi.id = pi.file_id "
			+ "where pi.type='th' and c.id = :id";
}
