package kr.co.ch07.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

@Controller
public class UserController {


    @GetMapping("/user/login")
    public String login(){

        return "user/login";
    }


    @GetMapping("/user/register")
    public String register(){


        return "user/register";
    }

    @PostMapping("/user/register")
    public String register(String name){

        return "redirect:/user/login";
    }
}
