package kr.or.connect.reservation.controller;

import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import kr.or.connect.reservation.dao.DisplayInfoDao;
import kr.or.connect.reservation.dao.ReservationDao;
import kr.or.connect.reservation.dao.UserDao;
import kr.or.connect.reservation.dto.DisplayInfo;
import kr.or.connect.reservation.dto.ProductImage;
import kr.or.connect.reservation.dto.ProductPrice;
import kr.or.connect.reservation.dto.ReservationInfo;
import kr.or.connect.reservation.dto.ReservationInfoResponse;
import kr.or.connect.reservation.dto.ReservationParam;
import kr.or.connect.reservation.dto.ReservationPrice;
import kr.or.connect.reservation.line.LineNotify;

@Controller
public class ReserveController {
	
	private final DisplayInfoDao displayInfoDao;
	private final ReservationDao reservationDao;
	private final UserDao userDao;
	
	public ReserveController(DisplayInfoDao displayInfoDao, ReservationDao reservationDao, UserDao userDao) {
		this.displayInfoDao = displayInfoDao;
		this.reservationDao = reservationDao;
		this.userDao = userDao;
	}
	
	@GetMapping("/reserve")
	public String reserve(@RequestParam(name = "id")int displayInfoId, ModelMap model) {
		List<ProductPrice> productPrices = displayInfoDao.getProductPrice(displayInfoId);
		List<ProductImage> productImages = displayInfoDao.getProductImage(displayInfoId);
		DisplayInfo displayInfos = displayInfoDao.getDisplayInfo(displayInfoId);
		
		//예매일
		/*
		long time = new Date().getTime();
		int day = (int)(Math.random()*5)+1;
		long daytime = day*24*60*60*1000;
		Date date = new Date(time+daytime);
		*/
		Date date = new Date();
		SimpleDateFormat smf = new SimpleDateFormat("yyyy.MM.dd");
		String reservation_day = smf.format(date);
		
		model.addAttribute("productPrices", productPrices);
		model.addAttribute("productImages", productImages);
		model.addAttribute("displayInfos", displayInfos);
		model.addAttribute("reservation_day", reservation_day);
		
		return "reserve";
	}
	
	@PostMapping("/reservations")
	public String reservation(@RequestParam(name = "id")int displayInfoId, HttpServletRequest request) {
		String reservationName = request.getParameter("name");
		String reservationTelephone = request.getParameter("tel");
		String reservationEmail = request.getParameter("resrv_email");
		String reservationDay = request.getParameter("day");
		int productId = displayInfoDao.getDisplayInfo(displayInfoId).getProductId();
		int size = displayInfoDao.getProductPrice(displayInfoId).size();
		String line_token = userDao.getUserByEmail(reservationEmail).getLineToken();
		List<Integer> prices = new ArrayList<Integer>();
		List<Integer> productPriceIds = new ArrayList<Integer>();
		int totalPrice=0;
		
		for(int i=0;i<size;i++) {
			int price_cnt = Integer.parseInt(request.getParameter("price_"+i));
			int productPriceId = displayInfoDao.getProductPrice(displayInfoId).get(i).getProductPriceId();
			int price = reservationDao.getProductPrice(productPriceId);
			prices.add(price_cnt); 
			productPriceIds.add(productPriceId);
			totalPrice += price_cnt*price;
		}
		
		ReservationParam reservationParam = new ReservationParam();
		reservationParam.setDisplayInfoId(displayInfoId);
		reservationParam.setProductId(productId);
		reservationParam.setReservationEmail(reservationEmail);
		reservationParam.setReservationName(reservationName);
		reservationParam.setReservationTelephone(reservationTelephone);
		reservationParam.setReservationYearMonthDay(reservationDay);
		
		reservationDao.insertReservation_Info(reservationParam);
		int reservationInfoId = reservationDao.getReservationInfoId();
		
		
		ReservationPrice reservationPrice = new ReservationPrice();
		for(int i=0;i<size;i++) {
			reservationPrice.setCount(prices.get(i));
			reservationPrice.setProductPriceId(productPriceIds.get(i));
			reservationPrice.setReservationInfoId(reservationInfoId);
			reservationDao.insertReservation_Info_Price(reservationPrice);
		}
        LineNotify ln = new LineNotify(line_token);
        try{
            ln.notifyMe(" ");
        }catch(IOException ex){
        }
		return "bookinglogin";
	}
	
	@GetMapping("/bookinglogin")
	public String bookinglogin() {
		return "bookinglogin";
	}
	
	@PostMapping("/myreservation")
	public String myreservation(HttpServletRequest request, ModelMap model) {
		String email = request.getParameter("resrv_email");
		ReservationInfoResponse reservationInfoResponse = new ReservationInfoResponse();
		List<ReservationInfo> reservationInfos = reservationDao.getReservationInfo(email);
		
		int cancel_cnt=0; //취소된 예약
		int playing_cnt=0; //이용 예정된 예약
		for(ReservationInfo r : reservationInfos) {
			if(r.isCancelYn()) cancel_cnt++;
			else playing_cnt++;
		}
		
		//set displayInfo
		for(int i=0;i<reservationInfos.size();i++) {
			int displayInfoId = reservationInfos.get(i).getDisplayInfoId();
			DisplayInfo displayInfo = reservationDao.getDisplayInfo(displayInfoId);
			reservationInfos.get(i).setDisplayInfo(displayInfo);
		}
		//set totalPrice
		for(int i=0;i<reservationInfos.size();i++) {
			int totalPrice = 0;
			int reservationInfoId = reservationInfos.get(i).getReservationInfoId();
			List<ReservationPrice> reservationPrices = reservationDao.getReservationPrice(reservationInfoId);
			for(int j=0;j<reservationPrices.size();j++) {
				int productPriceId = reservationPrices.get(j).getProductPriceId();
				int price = reservationDao.getProductPrice(productPriceId);
				totalPrice += price * reservationPrices.get(j).getCount();
			}
			reservationInfos.get(i).setTotalPrice(totalPrice);
		}
		reservationInfoResponse.setReservations(reservationInfos);
		reservationInfoResponse.setSize(reservationInfos.size());
		
		model.addAttribute("cancel_cnt", cancel_cnt);
		model.addAttribute("playing_cnt", playing_cnt);
		model.addAttribute("email", email);
		model.addAttribute("reservationInfoResponse", reservationInfoResponse);
		
		return "myreservation";
	}
	
	@GetMapping("/reservations/{reservationInfoId}")
	@ResponseBody
	public boolean delete(@PathVariable("reservationInfoId")int reservationInfoId) {
		//delete reservation_info_price
		int result = reservationDao.updateReservationInfo(reservationInfoId);
		if(result>0) {
			return true;
		}
		else return false;
	}
}
