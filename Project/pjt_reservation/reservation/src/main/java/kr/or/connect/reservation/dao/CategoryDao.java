package kr.or.connect.reservation.dao;

import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.sql.DataSource;

import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.jdbc.core.namedparam.NamedParameterJdbcTemplate;
import org.springframework.stereotype.Repository;

import kr.or.connect.reservation.dto.Category;
import kr.or.connect.reservation.dto.Product;

@Repository
public class CategoryDao {
	private NamedParameterJdbcTemplate jdbc;
	private RowMapper<Category> category = BeanPropertyRowMapper.newInstance(Category.class);
	private RowMapper<Product> product = BeanPropertyRowMapper.newInstance(Product.class);
	
	public CategoryDao(DataSource dataSource) {
		this.jdbc = new NamedParameterJdbcTemplate(dataSource);
	}
	
	public int getCategoryCount(Integer id) {
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", id);
		return jdbc.queryForObject(CategoryDaoSqls.COUNT, map, Integer.class);
	}
	
	public List<Category> getCategory(){
		return jdbc.query(CategoryDaoSqls.SELECT_ALL, Collections.emptyMap(), category);
	}
	
	public List<Product> getProduct(Integer categoryId){
		Map<String,Integer> map = new HashMap<String,Integer>();
		map.put("id", categoryId);
		return jdbc.query(CategoryDaoSqls.SELECT_PRODUCT, map, product);
	}
	
	public List<Product> getProductByLimit(Integer categoryId, Integer start,Integer limit){
		Map<String,Integer> map = new HashMap<String,Integer>();
		map.put("id", categoryId);
		map.put("start", start);
		map.put("limit", limit);
		return jdbc.query(CategoryDaoSqls.SELECT_PRODUCT_BY_LIMIT, map, product);
	}
	
	public int getProductCount(Integer categoryId) {
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("id", categoryId);
		return jdbc.queryForObject(CategoryDaoSqls.SELECT_PRODUCT_COUNT, map, Integer.class);
	}
}
