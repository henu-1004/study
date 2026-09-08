package kr.co.ch08.config;

import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.CorsRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

@Configuration
public class CorsConfig implements WebMvcConfigurer {

    @Override
    public void addCorsMappings(CorsRegistry registry) {

        //CORS 설정 : API 요청을 하는 외부 요청 Origin 설정


        registry.addMapping("/**") //모든 엔드포인트에 대해 허용
                .allowedOriginPatterns("http://127.0.0.1:5200") //서버의 요청을 허용할 오리진
                .allowedHeaders("*") //모든 헤더 허용
                .allowedMethods("GET", "POST", "PUT", "DELETE", "OPTIONS") //허용할 메서드
                .allowCredentials(true) //자격증명 허용
                .maxAge(3600); //요청유효시간 3.6초

    }
}
