package kr.co.ch04.controller;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.web.servlet.MockMvc;

import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;

@SpringBootTest
@AutoConfigureMockMvc
class User1ControllerTest {

    @Autowired
    private MockMvc mockMvc;

    @Test
    void register() throws Exception {
        for(int i=0 ; i<10 ; i++) { // 100개 대신 10개만 예시
            mockMvc.perform(
                            post("/user1/register")
                                    .param("userId", "a200" + i)   // DTO 필드명과 일치
                                    .param("userName", "홍길동")
                                    .param("birth", "1992-10-02")   // LocalDate 자동 변환
                                    .param("age", "21")
                    )
                    .andExpect(status().is3xxRedirection())
                    .andExpect(redirectedUrl("/user1/list"))
                    .andDo(print());
        }
    }

    @Test
    void list() throws Exception {
        mockMvc.perform(get("/user1/list"))
                .andExpect(status().isOk())
                .andExpect(view().name("/user1/list"))
                .andDo(print());
    }

    @Test
    void modify() throws Exception {
        mockMvc.perform(
                        post("/user1/modify")
                                .param("userId", "a2001")          // userId 맞춤
                                .param("userName", "홍길동수정")
                                .param("birth", "1993-05-12")      // LocalDate
                                .param("age", "30")
                )
                .andExpect(status().is3xxRedirection())
                .andExpect(redirectedUrl("/user1/list"))
                .andDo(print());
    }

    @Test
    void delete() throws Exception {
        mockMvc.perform(get("/user1/delete").param("userId", "a2001"))
                .andExpect(redirectedUrl("/user1/list"))
                .andDo(print());
    }
}
