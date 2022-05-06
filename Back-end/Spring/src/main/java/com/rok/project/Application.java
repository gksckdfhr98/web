package com.rok.project;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.data.jpa.repository.config.EnableJpaAuditing;

//@EnableJpaAuditing // JPA Auditing 활성화
// 스프링 부트의 자동 설정,스프링 Bean 읽기와 생성을 모두 자동으로 설정.
@SpringBootApplication
public class Application {
    public static void main(String[] args){
        // 내장 WAS로 애플리케이션을 실행.
        // 서버에 톰캣을 설치할 필요가 없게 되고, 스프링 부트로 만들어진 Jar 파일로 실행.
        SpringApplication.run(Application.class,args);
    }
}
