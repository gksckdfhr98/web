package kr.or.connect.reservation.controller;

import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import kr.or.connect.reservation.dao.UserDao;
import kr.or.connect.reservation.dao.UserRoleDao;
import kr.or.connect.reservation.dto.User;
import kr.or.connect.reservation.dto.UserRole;
import kr.or.connect.reservation.service.MemberService;
import kr.or.connect.reservation.service.UserEntity;

@Controller
public class LoginController {
	
	@Autowired
    PasswordEncoder passwordEncoder;
	
	private final MemberService memberService;
	private final UserDao userDao;
	private final UserRoleDao userRoleDao;
	
	public LoginController(MemberService memberService, UserDao userDao, UserRoleDao userRoleDao) {
		this.memberService = memberService;
		this.userDao = userDao;
		this.userRoleDao = userRoleDao;
	}
	@GetMapping("/loginform")
	public String loginform() {
		return "loginform";
	}
	
	@PostMapping("/loginerror")
	public String loginerror() {
		return "loginerror";
	}
	
	@GetMapping("/signuppage")
	public String signup() {
		return "signuppage";
	}
	
	@PostMapping("/signup")
	public String signup_post(HttpServletRequest request, ModelMap model) {
		String id = request.getParameter("resrv_id");
		String password = request.getParameter("resrv_password");
		String conserve_password = passwordEncoder.encode(password);
		String name = request.getParameter("resrv_name");
		String tel = request.getParameter("resrv_tel");
		String line_token = request.getParameter("resrv_line");
		String msg="";
		
		User user = new User();
		user.setEmail(id);
		user.setPassword(conserve_password);
		user.setName(name);
		user.setPhone(tel);
		user.setLineToken(line_token);
		
		int result = userDao.insertUser(user);
		if(result < 1) {
			msg = "회원가입오류: 이미 회원입니다.";
			model.addAttribute("msg", msg);
			return "signuperror";
		}
		
		UserRole userRole = new UserRole();
		Long userId = new Long(userDao.getUserId());
		userRole.setUserId(userId);
		userRole.setRoleName("ROLE_USER");
		
		result = userRoleDao.insertUserRole(userRole);
		if(result < 1) {
			msg = "회원가입오류: 이미 회원입니다.";
			model.addAttribute("msg", msg);
			return "signuperror";
		}
		
		// 정상적으로 회원가입 완료
		return "loginform";
	}
	
	@ResponseBody
	@PostMapping("/api/signup")
	public boolean signup_post(HttpServletRequest request, @RequestBody Map<String,Object> params) {
		String loginUserId = (String)params.get("id");
		try {
			UserEntity user = memberService.getUser(loginUserId);
			if(user != null) return false;
		}catch(Exception e) {
		}
		return true;
	}
}
