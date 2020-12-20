package kr.or.connect.reservation.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpMethod;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.builders.WebSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

import kr.or.connect.reservation.service.CustomUserDetailsService;

@Configuration
@EnableWebSecurity
public class SecurityConfig extends WebSecurityConfigurerAdapter {
	@Autowired
	CustomUserDetailsService customUserDetailsService;

    @Override
    public void configure(WebSecurity web) throws Exception {
        web.ignoring().antMatchers(
                "/webjars/**","/resources/**");
    }

    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth.userDetailsService(customUserDetailsService);
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
                .csrf().disable()
                .authorizeRequests()
                .antMatchers(HttpMethod.GET,"/","/loginform","/loginerror","/signuppage").permitAll()
                .antMatchers(HttpMethod.POST,"/api/signup","/signup").permitAll()
                .antMatchers("/main","/api/category","/api/product"
                		,"/detail","/api/detail"
                		,"/reserve","/reservations","/bookinglogin","/myreservation","/reservations/{reservationInfoId}"
                		,"/review","/reviewWrite","/reservations/{reservationInfoId}/comments").hasRole("USER")
                .anyRequest().authenticated()
                .and()
                    .formLogin()
                    .loginPage("/loginform")
                    .usernameParameter("resrvId")
                    .passwordParameter("resrvPasswd")
                    .loginProcessingUrl("/authenticate")
                    .failureForwardUrl("/loginerror")
                    .defaultSuccessUrl("/main",true)
                    .permitAll()
                .and()
                    .logout()
                    .logoutUrl("/logout")
                    .logoutSuccessUrl("/");
    }

    @Bean
    public PasswordEncoder encoder() {
        return new BCryptPasswordEncoder();
    }	
}
