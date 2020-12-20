package kr.or.connect.todolist.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kr.or.connect.todolist.dao.TodoDao;
import kr.or.connect.todolist.dto.TodoDto;

/**
 * Servlet implementation class MainServlet
 */
@WebServlet("/main")
public class MainServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    /**
     * @see HttpServlet#HttpServlet()
     */
    public MainServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		TodoDao todoDao = new TodoDao();
		
		try {
			Long id = Long.parseLong(request.getParameter("id"));
			String name = request.getParameter("name");
			String regDate = request.getParameter("regDate");
			int sequence = Integer.parseInt(request.getParameter("sequence"));
			String title = request.getParameter("title");
			String type = request.getParameter("type");
			
			if(id != null) {
				TodoDto todoDto = new TodoDto(id,name,regDate,sequence,title,type);
				todoDao.updateTodo(todoDto);
			}
		}catch(Exception e) {}
		
		List<TodoDto> list = todoDao.getTodos();
		request.setAttribute("list", list);
		RequestDispatcher dispatcher = request.getRequestDispatcher("/main.jsp");
		dispatcher.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}

}
