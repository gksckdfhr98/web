package kr.or.connect.reservation.dto;

import java.util.Date;

public class User {
    private Long id;
    private String name;
    private String password;
    private String email;
    private String phone;
    private String lineToken;
	private Date createDate;
    private Date modifyDate;

    public User() {
        createDate = new Date();
        modifyDate = new Date();
    }

    public User(Long id, String name, String password, String email, String phone, String lineToken) {
        this();
        this.name = name;
        this.password = password;
        this.email = email;
        this.phone = phone;
        this.lineToken = lineToken;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
    
    public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}
	
	public String getLineToken() {
		return lineToken;
	}

	public void setLineToken(String lineToken) {
		this.lineToken = lineToken;
	}
	
    public Date getCreateDate() {
        return createDate;
    }

    public void setCreateDate(Date createDate) {
        this.createDate = createDate;
    }

    public Date getModifyDate() {
        return modifyDate;
    }

    public void setModifyDate(Date modifyDate) {
        this.modifyDate = modifyDate;
    }
}
