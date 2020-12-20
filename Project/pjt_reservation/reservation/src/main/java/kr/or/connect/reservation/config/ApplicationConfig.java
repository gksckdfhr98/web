package kr.or.connect.reservation.config;

import javax.sql.DataSource;

import org.apache.commons.dbcp2.BasicDataSource;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.datasource.DataSourceTransactionManager;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;
import org.springframework.transaction.annotation.TransactionManagementConfigurer;
import org.springframework.web.multipart.MultipartResolver;

@Configuration
@EnableTransactionManagement
@ComponentScan(basePackages = {"kr.or.connect.reservation.dao","kr.or.connect.reservation.service"})
public class ApplicationConfig implements TransactionManagementConfigurer{
	private String driverClassName = "com.mysql.jdbc.Driver";
	private String url = "jdbc:mysql://database-spring.c8dljil33cma.us-east-1.rds.amazonaws.com:3306/reservation?useUnicode=true&characterEncoding=utf8&useSSL=false";
    private String username = "spring";
    private String password = "asdasd5148";
    
    @Bean
    public DataSource dataSource(){
        BasicDataSource dataSource = new BasicDataSource();
        dataSource.setDriverClassName(driverClassName);
        dataSource.setUrl(url);
        dataSource.setUsername(username);
        dataSource.setPassword(password);

        return dataSource;
    }
    
    @Bean
    public PlatformTransactionManager transactionManager(){
        return new DataSourceTransactionManager(dataSource());
    }

    @Override
    public PlatformTransactionManager annotationDrivenTransactionManager() {
        return transactionManager();
    }
    
    @Bean
    public MultipartResolver multipartResolver() {
        org.springframework.web.multipart.commons.CommonsMultipartResolver multipartResolver = new org.springframework.web.multipart.commons.CommonsMultipartResolver();
        multipartResolver.setMaxUploadSize(10485760); // 1024 * 1024 * 10
        return multipartResolver;
    }
}
