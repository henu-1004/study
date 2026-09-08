package kr.co.ch04.controller;

import kr.co.ch04.dto.User1DTO;
import kr.co.ch04.service.User1Service;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

@Slf4j
@RequiredArgsConstructor
@Controller
public class User1Controller {

    private final User1Service service;

    @GetMapping("/user1/register")
    public String register(){
        return "/user1/register";
    }

    @PostMapping("/user1/register")
    public String register(User1DTO user1DTO){
        log.debug(user1DTO.toString());
        log.info("log info...");
        log.warn("log warn...");
        log.error("log error...");

        service.save(user1DTO);

        return "redirect:/user1/list";
    }

    @GetMapping("/user1/list")
    public String list(Model model){

        List<User1DTO> dtoList = service.getUsers();
        log.debug(dtoList.toString());

        model.addAttribute("dtoList",dtoList);

        return "/user1/list";
    }

    @GetMapping("/user1/modify")
    public String modify(@RequestParam("userId") String userId, Model model){

        //서비스에서 해당 사용자 조회
        User1DTO user = service.getUser(userId);

        //뷰에서 쓸수있도록 모델에 담기
        model.addAttribute("user1DTO",user);

        return "/user1/modify";
    }

    @PostMapping("/user1/modify")
    public String modify(User1DTO user1DTO) {
        // 수정된 값 저장
        service.update(user1DTO);

        // 수정 후 목록으로 이동
        return "redirect:/user1/list";
    }

    @GetMapping("/user1/delete")
    public String delete(@RequestParam("userId") String userId) {
        service.delete(userId); // 여기서 mapper.delete(userId) 호출됨
        return "redirect:/user1/list";
    }

}
