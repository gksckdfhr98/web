package kr.or.connect.reservation.dao;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

import javax.sql.DataSource;

import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.namedparam.BeanPropertySqlParameterSource;
import org.springframework.jdbc.core.namedparam.NamedParameterJdbcTemplate;
import org.springframework.jdbc.core.namedparam.SqlParameterSource;
import org.springframework.jdbc.core.simple.SimpleJdbcInsert;
import org.springframework.stereotype.Repository;

import kr.or.connect.reservation.dto.FileInfo;
import kr.or.connect.reservation.dto.ReservationUserComment;
import kr.or.connect.reservation.dto.ReservationUserCommentImage;

@Repository
public class ReviewDao {
	private NamedParameterJdbcTemplate jdbc;
	private SimpleJdbcInsert insertFileInfo;
	private SimpleJdbcInsert insertReservationUserComment;
	private SimpleJdbcInsert insertReservationUserCommentImage;
	
	public ReviewDao(DataSource dataSource) {
		this.jdbc = new NamedParameterJdbcTemplate(dataSource);
		this.insertFileInfo = new SimpleJdbcInsert(dataSource).withTableName("file_info").usingGeneratedKeyColumns("id");
		this.insertReservationUserComment = new SimpleJdbcInsert(dataSource).withTableName("reservation_user_comment").usingGeneratedKeyColumns("id");
		this.insertReservationUserCommentImage = new SimpleJdbcInsert(dataSource).withTableName("reservation_user_comment_image").usingGeneratedKeyColumns("id");
	}
	
	public int insert_reservation_user_comment(ReservationUserComment reservationUserComment) {
		SqlParameterSource params = new BeanPropertySqlParameterSource(reservationUserComment);
		int result = insertReservationUserComment.execute(params);
		return result;
	}
	
	public int getReservationUserCommentId() {
		return jdbc.queryForObject(ReviewDaoSqls.SELECT_RESERVATION_USER_COMMENT_ID, Collections.emptyMap(), Integer.class);
	}
	
	public int insert_file_info(FileInfo fileInfo) {
		SqlParameterSource params = new BeanPropertySqlParameterSource(fileInfo);
		int result = insertFileInfo.execute(params);
		return result;
	}
	
	public int getfile_id() {
		return jdbc.queryForObject(ReviewDaoSqls.SELECT_FILE_ID, Collections.emptyMap(), Integer.class);
	}
	
	public int insert_reservation_user_comment_image(ReservationUserCommentImage reservationUserCommentImage) {
		SqlParameterSource params = new BeanPropertySqlParameterSource(reservationUserCommentImage);
		int result = insertReservationUserCommentImage.execute(params);
		return result;
	}
}
