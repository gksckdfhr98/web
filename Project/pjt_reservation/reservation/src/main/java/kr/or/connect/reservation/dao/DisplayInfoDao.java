package kr.or.connect.reservation.dao;


import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.sql.DataSource;

import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.jdbc.core.namedparam.NamedParameterJdbcTemplate;
import org.springframework.stereotype.Repository;

import kr.or.connect.reservation.dto.Comment;
import kr.or.connect.reservation.dto.CommentImage;
import kr.or.connect.reservation.dto.DisplayInfo;
import kr.or.connect.reservation.dto.DisplayInfoImage;
import kr.or.connect.reservation.dto.ProductImage;
import kr.or.connect.reservation.dto.ProductPrice;

@Repository
public class DisplayInfoDao {
	private NamedParameterJdbcTemplate jdbc;
	private RowMapper<Comment> comment = BeanPropertyRowMapper.newInstance(Comment.class);
	private RowMapper<CommentImage> commentImage = BeanPropertyRowMapper.newInstance(CommentImage.class);
	private RowMapper<DisplayInfo> displayInfo = BeanPropertyRowMapper.newInstance(DisplayInfo.class);
	private RowMapper<DisplayInfoImage> displayInfoImage = BeanPropertyRowMapper.newInstance(DisplayInfoImage.class);
	private RowMapper<ProductImage> productImage = BeanPropertyRowMapper.newInstance(ProductImage.class);
	private RowMapper<ProductPrice> productPrice = BeanPropertyRowMapper.newInstance(ProductPrice.class);
	
	public DisplayInfoDao(DataSource dataSource) {
		this.jdbc = new NamedParameterJdbcTemplate(dataSource);
	}
	
	public List<CommentImage> getCommentImage(Integer reservationUserCommentId){
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", reservationUserCommentId);
		return jdbc.query(DisplayInfoDaoSqls.SELECT_COMMENT_IMAGE, map, commentImage);
	}
	
	public List<Comment> getComment(Integer displayInfoId){
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", displayInfoId);
		return jdbc.query(DisplayInfoDaoSqls.SELECT_COMMENT, map, comment);
	}
	
	public DisplayInfo getDisplayInfo(Integer displayInfoId){
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", displayInfoId);
		return jdbc.queryForObject(DisplayInfoDaoSqls.SELECT_DISPLAY_INFO, map, displayInfo);
	}
	
	public DisplayInfoImage getDisplayInfoImage(Integer displayInfoId){
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", displayInfoId);
		return jdbc.queryForObject(DisplayInfoDaoSqls.SELECT_DISPLAY_INFO_IMAGE, map, displayInfoImage);
	}
	
	public List<ProductImage> getProductImage(Integer displayInfoId){
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", displayInfoId);
		return jdbc.query(DisplayInfoDaoSqls.SELECT_PRODUCT_IMAGE, map, productImage);
	}
	
	public List<ProductPrice> getProductPrice(Integer displayInfoId){
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", displayInfoId);
		return jdbc.query(DisplayInfoDaoSqls.SELECT_PRODUCT_PRICE, map, productPrice);
	}
}
