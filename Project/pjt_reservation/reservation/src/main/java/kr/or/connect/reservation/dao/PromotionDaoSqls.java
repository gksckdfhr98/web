package kr.or.connect.reservation.dao;

public class PromotionDaoSqls {
	public static final String SELECT_ALL = "SELECT pm.id, pm.product_id, fi.save_file_name as productImageUrl FROM promotion pm "
			+ "left join product p on p.id = pm.product_id "
			+ "left join product_image pi on pi.product_id = p.id "
			+ "left join file_info fi on fi.id = pi.file_id "
			+ "where pi.type='th'";
}
