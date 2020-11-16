package kr.or.connect.reservation.controller;

import java.io.FileOutputStream;
import java.io.InputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import kr.or.connect.reservation.dao.DisplayInfoDao;
import kr.or.connect.reservation.dao.ReviewDao;
import kr.or.connect.reservation.dto.Comment;
import kr.or.connect.reservation.dto.CommentImage;
import kr.or.connect.reservation.dto.DisplayInfo;
import kr.or.connect.reservation.dto.DisplayInfoImage;
import kr.or.connect.reservation.dto.DisplayInfoResponse;
import kr.or.connect.reservation.dto.FileInfo;
import kr.or.connect.reservation.dto.ProductImage;
import kr.or.connect.reservation.dto.ProductPrice;
import kr.or.connect.reservation.dto.ReservationUserComment;
import kr.or.connect.reservation.dto.ReservationUserCommentImage;

@Controller
public class ReviewController {
	
	private final DisplayInfoDao displayInfoDao;
	private final ReviewDao reviewDao;
	
	public ReviewController(DisplayInfoDao displayInfoDao,ReviewDao reviewDao) {
		this.displayInfoDao = displayInfoDao;
		this.reviewDao=reviewDao;
	}
	
	@GetMapping("/review")
	public String review(@RequestParam(name="id",required = true)int displayInfoId, ModelMap model) {
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
		return "review";
	}
	
	@GetMapping("/reviewWrite")
	public String reviewWrite(@RequestParam(name = "reservationid")int reservationInfoId, @RequestParam(name = "productid")int productId, ModelMap model) {
		model.addAttribute("reservationInfoId", reservationInfoId);
		model.addAttribute("productId", productId);
		return "reviewWrite";
	}
	
	@PostMapping("/reservations/{reservationInfoId}/comments")
	public String comment(@PathVariable("reservationInfoId")int reservationInfoId, @RequestParam(name = "file", required = false)MultipartFile file, HttpServletRequest request) {
		int product_id = Integer.parseInt(request.getParameter("productId"));
		double score = Integer.parseInt(request.getParameter("score"));
		String comment = request.getParameter("comment");
		//System.out.println(comment);
		String file_name = "";
		String content_type = "";
		String save_file_name = "";
		try {
			file_name = file.getOriginalFilename();
			content_type = "image/"+file_name.split("\\.")[1];
			save_file_name = "img/"+file_name;
		}catch(Exception e) {
		}
		
		Date date = new Date();
		SimpleDateFormat smf = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
		String create_date = smf.format(date);
		String modify_date = smf.format(date);
		String rootdir = request.getSession().getServletContext().getRealPath("/");
		
		ReservationUserComment ruc = new ReservationUserComment();
		ruc.setComment(comment);
		ruc.setCreateDate(create_date);
		ruc.setModifyDate(modify_date);
		ruc.setProductId(product_id);
		ruc.setReservationInfoId(reservationInfoId);
		ruc.setScore(score);
		
		if(reviewDao.insert_reservation_user_comment(ruc)>0) {
			int reservation_user_comment_id = reviewDao.getReservationUserCommentId();
			
			FileInfo fileInfo = new FileInfo();
			fileInfo.setContentType(content_type);
			fileInfo.setCreateDate(create_date);
			fileInfo.setDeleteFlag(0);
			fileInfo.setFileName(file_name);
			fileInfo.setModifyDate(modify_date);
			fileInfo.setSaveFileName(save_file_name);
			//insert file_info
			if(reviewDao.insert_file_info(fileInfo)>0) {
				int file_id = reviewDao.getfile_id();
				
				ReservationUserCommentImage ruci = new ReservationUserCommentImage();
				ruci.setFileId(file_id);
				ruci.setReservationInfoId(reservationInfoId);
				ruci.setReservationUserCommentId(reservation_user_comment_id);
				
				if(reviewDao.insert_reservation_user_comment_image(ruci)>0) {
					//file upload
					if(file_name.length()!=0) {
						try(
			                FileOutputStream fos = new FileOutputStream(rootdir+"/resources/img/" + file.getOriginalFilename());
			                InputStream is = file.getInputStream();
				        ){
			        	    int readCount = 0;
			        	    byte[] buffer = new byte[1024];
				            while((readCount = is.read(buffer)) != -1){
				                fos.write(buffer,0,readCount);
				            }
				        }catch(Exception ex){
				            throw new RuntimeException("file Save Error");
				        }
					}
					return "redirect:/main";
				}
				else return "";
			}
			else return "";
		}
		else return "";
	}
}

