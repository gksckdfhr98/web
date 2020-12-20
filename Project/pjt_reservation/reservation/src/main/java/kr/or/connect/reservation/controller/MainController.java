package kr.or.connect.reservation.controller;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import kr.or.connect.reservation.dao.CategoryDao;
import kr.or.connect.reservation.dao.PromotionDao;
import kr.or.connect.reservation.dto.Category;
import kr.or.connect.reservation.dto.CategoryResponse;
import kr.or.connect.reservation.dto.Product;
import kr.or.connect.reservation.dto.ProductResponse;
import kr.or.connect.reservation.dto.Promotion;
import kr.or.connect.reservation.dto.PromotionResponse;

@Controller
public class MainController {
	
	private final CategoryDao categoryDao;
	private final PromotionDao promotionDao;
	
	public MainController(CategoryDao categoryDao,PromotionDao promotionDao) {
		this.categoryDao=categoryDao;
		this.promotionDao=promotionDao;
	}
	
	@GetMapping("/main")
	public String main(ModelMap model) {
		//카테고리
		CategoryResponse categoryResponse = new CategoryResponse();
		List<Category> categories = categoryDao.getCategory();
		
		for(int i=0;i<categories.size();i++) {
			int count = categoryDao.getCategoryCount(i+1);
			categories.get(i).setCount(count);
		}
		categoryResponse.setItems(categories);
		//카테고리 전체리스트 총 개수
		int totalCount=0;
		for(int i=0;i<=categories.size();i++) {
			totalCount+=categoryDao.getCategoryCount(i);
		}
		
		//프로모션
		PromotionResponse promotionResponse = new PromotionResponse();
		List<Promotion> promotions = promotionDao.getPromotion();
		promotionResponse.setItems(promotions);
		
		model.addAttribute("totalCount", totalCount);
		model.addAttribute("categoryResponse", categoryResponse);
		model.addAttribute("promotion", promotionResponse);
		
		return "main";
	}
	
	@GetMapping("/api/category")
	@ResponseBody
	public  Map<String, Integer> getcategory(HttpServletRequest request) {
		int id = Integer.parseInt(request.getParameter("id"));
		Map<String, Integer> map = new HashMap<String, Integer>();
		List<Category> categories = categoryDao.getCategory();
		int totalCount=0;
		if(id==0) {
			for(int i=1;i<=categories.size();i++) {
				totalCount+=categoryDao.getCategoryCount(i);
			}
			map.put("count", totalCount);
			return map;
		}
		
		int count = categoryDao.getCategoryCount(id);
		map.put("count", count);
		
		return map;
	}
	
	@GetMapping("/api/product")
	@ResponseBody
	public ProductResponse getProduct(@RequestParam(name="categoryId")int categoryId,@RequestParam(name="start", defaultValue = "0")int start) {
		ProductResponse productResponse = new ProductResponse();
		int limit = 4;
		int totalCount=0;
		List<Product> products = new ArrayList<Product>();
		
		
		if(categoryId==0) { //전체리스트
			List<Product> new_product = new ArrayList<Product>();
			int categorySize = categoryDao.getCategory().size();
			int end = start+limit;
			for(int i=1;i<=categorySize;i++) {
				products.addAll(categoryDao.getProduct(i));
				totalCount += categoryDao.getProductCount(i);
			}
			if(start>totalCount) return productResponse;
			if(end>totalCount) end = totalCount; 
			for(int i=start;i<end;i++) {
				new_product.add(products.get(i));
			}
			productResponse.setItems(new_product);
			productResponse.setTotalCount(totalCount);
		}
		else {
			products = categoryDao.getProductByLimit(categoryId, start, limit);
			totalCount = categoryDao.getProductCount(categoryId);
			productResponse.setItems(products);
			productResponse.setTotalCount(totalCount);
		}
		return productResponse;
	}
}
