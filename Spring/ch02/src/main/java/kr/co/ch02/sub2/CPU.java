package kr.co.ch02.sub2;

import org.springframework.stereotype.Component;

@Component //Cpu BEAN 스프링컨테이너 등록
public class CPU {
    public void show(){
        System.out.println("CPU : Intel i9");
    }
}
