package kr.or.connect.todolist.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import kr.or.connect.todolist.dto.TodoDto;

public class TodoDao {
	private String driverClassName = "com.mysql.jdbc.Driver";
	private String url = "jdbc:mysql://localhost:3306/connectdb?useUnicode=true&characterEncoding=utf8&serverTimezone=UTC";
    private String username = "connectuser";
    private String password = "connect123!@#";
    
    Connection conn = null;
    PreparedStatement ps=null;
    ResultSet rs = null;
    
    public List<TodoDto> getTodos(){
    	List<TodoDto> list = new ArrayList<TodoDto>();
    	
    	try {
    		Class.forName(driverClassName);
    	}catch(ClassNotFoundException e) {
    		e.printStackTrace();
    	}
    	
    	String sql = "SELECT id,name,date_format(regdate,'%Y.%m.%d') as regDate,sequence,title,type "
    			+ "FROM todo order by id asc";
    	try(Connection conn = DriverManager.getConnection(url, username, password);
    			PreparedStatement ps = conn.prepareStatement(sql)){
    		try(ResultSet rs = ps.executeQuery()){
    			while(rs.next()) {
    				Long id = rs.getLong("id");
    				String name = rs.getString("name");
    				String regDate = rs.getString("regDate");
    				int sequence = rs.getInt("sequence");
    				String title = rs.getString("title");
    				String type = rs.getString("type");
    				TodoDto todoDto = new TodoDto(id,name,regDate,sequence,title,type);
    				list.add(todoDto);
    			}
    		}catch(Exception e) {
    			e.printStackTrace();
    		}
    	}catch(Exception ex) {
    		ex.printStackTrace();
    	}
    	return list;
    }
    
    public int addTodo(TodoDto todoDto) {
    	int insertCount = 0;
    	
    	try {
    		Class.forName(driverClassName);
    	}catch(ClassNotFoundException e) {
    		e.printStackTrace();
    	}
    	String sql = "INSERT INTO todo (name,sequence,title) VALUES (?,?,?)";
    	
    	try(Connection conn = DriverManager.getConnection(url, username, password);
    			PreparedStatement ps = conn.prepareStatement(sql)){
    		ps.setString(1, todoDto.getName());
    		ps.setInt(2, todoDto.getSequence());
    		ps.setString(3, todoDto.getTitle());
    		insertCount = ps.executeUpdate();
    	}catch(Exception e) {
    		e.printStackTrace();
    	}
    	return insertCount;
    }
    
    public int updateTodo(TodoDto todoDto) {
    	int updateCount = 0;
    	
    	String type = todoDto.getType();
    	if(type.equals("TODO")) type = "DOING";
    	else if(type.equals("DOING")) type = "DONE";
    	try {
    		Class.forName(driverClassName);
    		conn = DriverManager.getConnection(url, username, password);
    		
    		String sql = "UPDATE todo set type = ? where id = ?";
    		
    		ps = conn.prepareStatement(sql);
    		
    		ps.setString(1, type);
    		ps.setLong(2, todoDto.getId());
    		
    		updateCount = ps.executeUpdate();
    	}catch(Exception e) {
    		e.printStackTrace();
    	}finally {
    		if(ps != null) {
    			try {
    				ps.close();
    			}catch(Exception e) {}
    		}
    		
    		if(conn != null) {
    			try {
    				conn.close();
    			}catch(Exception e) {}
    		}
    	}
    	
    	return updateCount;
    }
}
