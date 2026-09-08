package kr.co.ch04.dto;


import lombok.*;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDate;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class User1DTO {
    private String userId;
    private String userName;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDate birth;

    private int age;

}
