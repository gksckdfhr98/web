package kr.or.connect.reservation.dao;

import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.sql.DataSource;

import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.jdbc.core.namedparam.NamedParameterJdbcTemplate;
import org.springframework.jdbc.core.simple.SimpleJdbcInsert;
import org.springframework.stereotype.Repository;

import kr.or.connect.reservation.dto.DisplayInfo;
import kr.or.connect.reservation.dto.ReservationInfo;
import kr.or.connect.reservation.dto.ReservationParam;
import kr.or.connect.reservation.dto.ReservationPrice;

@Repository
public class ReservationDao {
	private NamedParameterJdbcTemplate jdbc;
	private SimpleJdbcInsert insert_reservation_info;
	private SimpleJdbcInsert insert_reservation_info_price;
	private RowMapper<ReservationParam> reservationParam = BeanPropertyRowMapper.newInstance(ReservationParam.class);
	private RowMapper<ReservationPrice> reservationPrice = BeanPropertyRowMapper.newInstance(ReservationPrice.class);
	private RowMapper<ReservationInfo> reservationInfo = BeanPropertyRowMapper.newInstance(ReservationInfo.class);
	private RowMapper<DisplayInfo> displayInfo = BeanPropertyRowMapper.newInstance(DisplayInfo.class);
	
	public ReservationDao(DataSource dataSource) {
		this.jdbc = new NamedParameterJdbcTemplate(dataSource);
		this.insert_reservation_info = new SimpleJdbcInsert(dataSource).withTableName("reservation_info").usingGeneratedKeyColumns("id");
		this.insert_reservation_info_price = new SimpleJdbcInsert(dataSource).withTableName("reservation_info_price").usingGeneratedKeyColumns("id");
	}
	
	public int insertReservation_Info(ReservationParam reservationParam) {
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("display_info_id", reservationParam.getDisplayInfoId());
		map.put("product_id", reservationParam.getProductId());
		map.put("reservation_email", reservationParam.getReservationEmail());
		map.put("reservation_name", reservationParam.getReservationName());
		map.put("reservation_tel", reservationParam.getReservationTelephone());
		map.put("reservation_date", reservationParam.getReservationYearMonthDay());
		map.put("cancel_flag", 0);
		map.put("create_date", reservationParam.getReservationYearMonthDay());
		map.put("modify_date", reservationParam.getReservationYearMonthDay());
		
		int result = insert_reservation_info.execute(map);
		return result;
	}
	
	public int insertReservation_Info_Price(ReservationPrice reservationPrice) {
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("count", reservationPrice.getCount());
		map.put("product_price_id", reservationPrice.getProductPriceId());
		map.put("reservation_info_id", reservationPrice.getReservationInfoId());
		map.put("reservation_info_price_id", reservationPrice.getReservationInfoPriceId());
		
		int result = insert_reservation_info_price.execute(map);
		return result;
	}
	
	public int getReservationInfoId() {
		return jdbc.queryForObject(ReservationDaoSqls.SELECT_ID, Collections.emptyMap(), Integer.class);
	}
	
	public List<ReservationPrice> getReservationPrice(Integer reservationInfoId){
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id", reservationInfoId);
		return jdbc.query(ReservationDaoSqls.SELECT_RESERVATION_PRICE, map, reservationPrice);
	}
	
	public int getProductPrice(Integer productPriceId) {
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", productPriceId);
		return jdbc.queryForObject(ReservationDaoSqls.SELECT_PRODUCT_PRICE, map, Integer.class);
	}
	
	public List<ReservationInfo> getReservationInfo(String email){
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("email", email);
		return jdbc.query(ReservationDaoSqls.SELECT_RESERVATION_INFO, map, reservationInfo);
	}
	
	public DisplayInfo getDisplayInfo(Integer displayInfoId) {
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", displayInfoId);
		return jdbc.queryForObject(ReservationDaoSqls.SELECT_DISPLAY_INFO, map, displayInfo);
	}
	
	public int updateReservationInfo(Integer reservationInfoId) {
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id", reservationInfoId);
		return jdbc.update(ReservationDaoSqls.UPDATE_RESERVATION_INFO, map);
	}
	
	public int deleteReservationInfoPrice(Integer reservationInfoId) {
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id", reservationInfoId);
		return jdbc.update(ReservationDaoSqls.DELETE_RESERVATION_INFO_PRICE, map);
	}
	
	public int deleteReservationInfo(Integer reservationInfoId) {
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id", reservationInfoId);
		return jdbc.update(ReservationDaoSqls.DELETE_RESERVATION_INFO, map);
	}
}
