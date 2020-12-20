package kr.or.connect.reservation.controller;

import java.util.List;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import kr.or.connect.reservation.dao.DisplayInfoDao;
import kr.or.connect.reservation.dto.Comment;
import kr.or.connect.reservation.dto.CommentImage;
import kr.or.connect.reservation.dto.DisplayInfo;
import kr.or.connect.reservation.dto.DisplayInfoImage;
import kr.or.connect.reservation.dto.DisplayInfoResponse;
import kr.or.connect.reservation.dto.ProductImage;
import kr.or.connect.reservation.dto.ProductPrice;

@Controller
public class DetailController {
	private final DisplayInfoDao displayInfoDao;
	
	public DetailController(DisplayInfoDao displayInfoDao){
		this.displayInfoDao = displayInfoDao;
	}
	
	@GetMapping("/detail")
	public String detail(@RequestParam(name="id",required = true)int displayInfoId, ModelMap model) {
		DisplayInfoResponse displayInfoResponse = new DisplayInfoResponse();
		List<Comment> comments = displayInfoDao.getComment(displayInfoId);
		double averageScore = 0;
		for(Comment c : comments) {
			int reservationUserCommentId = c.getCommentId();
			List<CommentImage> commentImages = displayInfoDao.getCommentImage(reservationUserCommentId);
			//System.out.println(commentImages);
			c.setCommentImages(commentImages);
			averageScore += c.getScore();
		}
		averageScore /= comments.size();
		//System.out.println(comments);
		//System.out.println(averageScore);
		DisplayInfo displayInfos = displayInfoDao.getDisplayInfo(displayInfoId);
		//System.out.println(displayInfos);
		DisplayInfoImage displayInfoImages = displayInfoDao.getDisplayInfoImage(displayInfoId);
		//System.out.println(displayInfoImages);
		List<ProductImage> productImages = displayInfoDao.getProductImage(displayInfoId);
		//System.out.println(productImages);
		List<ProductPrice> productPrices = displayInfoDao.getProductPrice(displayInfoId);
		//System.out.println(productPrices);
		
		displayInfoResponse.setAverageScore(averageScore);
		displayInfoResponse.setComments(comments);
		displayInfoResponse.setDisplayInfo(displayInfos);
		displayInfoResponse.setDisplayInfoImage(displayInfoImages);
		displayInfoResponse.setProductImages(productImages);
		displayInfoResponse.setProductPrices(productPrices);
		
		model.addAttribute("displayInfoResponse", displayInfoResponse);
		return "detail";
	}
	
	@GetMapping("/api/detail")
	@ResponseBody
	public boolean getDisplayInfoResponse(@RequestParam(name="id",required = true)int displayInfoId) {
		List<ProductImage> productImages = displayInfoDao.getProductImage(displayInfoId);
		if(productImages.size()>=2) return true;
		else return false;
	}
}
