package kr.co.ch04.mapper;

import kr.co.ch04.dto.User1DTO;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.time.LocalDate;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class User1MapperTest {

    @Autowired
    private User1Mapper user1Mapper; //여기선 그냥 필드주입으로 해도 괜찮다함

    private String testUserId = "abc123";
    @Order(1)
    @DisplayName("등록 테스트")
    @Test
    void insert() {

        //Given - 테스트를 실행하기 위한 준비단계
        User1DTO user1DTO = User1DTO.builder()
                            .userId(testUserId)
                            .userName("부부부")
                            .birth(LocalDate.parse("1991-01-21"))
                            .age(33)
                            .build();

        //When - 테스트 수행
        user1Mapper.insert(user1DTO);

        //Then - 테스트 결과를 검증
        User1DTO savedUser = user1Mapper.select(user1DTO.getUserId());
        assertEquals(user1DTO.getUserId(),savedUser.getUserId());
        //실패결과확인
        //assertEquals(user1DTO.getUserId(),"aaa");
    }
    @Order(2)
    @DisplayName("선택 테스트")
    @Test
    void select() {

        //Given
        String userId="a101";

        //When
        User1DTO findUser = user1Mapper.select(testUserId);

        //Then
        System.out.println(findUser);
        assertEquals(findUser.getUserId(),testUserId);
    }
    @Order(4)
    @DisplayName("전체목록테스트")
    @Test
    void selectAll() {

        //Given

        //When
        List<User1DTO> dtoList = user1Mapper.selectAll();

        //Then
        System.out.println(dtoList);
        assertFalse(dtoList.isEmpty()); //비었으면 트루. 폴스가 참이면 트루 라는뜻?


    }
    @Order(5)
    @DisplayName("수정테스트")
    @Test
    void update() {

        //Given
        User1DTO user1DTO = User1DTO.builder()
                .userId(testUserId)
                .userName("부부부에서수정")
                .birth(LocalDate.parse("1991-01-21"))
                .age(44)
                .build();
        //When
        user1Mapper.update(user1DTO);

        //Then
        User1DTO modifiedUser = user1Mapper.select(user1DTO.getUserId());
        assertEquals(user1DTO.getUserName(),modifiedUser.getUserName());

        assertEquals(user1DTO,modifiedUser);//객체로비교 DTO에 @Data어노테이션 선언
        // 문자열 비교 - 날짜 앞 10자리만 체크 > birth가 string인 경우수행 > 지금은 localdate임
        //assertEquals(user1DTO.getBirth().substring(0, 10), modifiedUser.getBirth().substring(0, 10));


    }

    @Order(6)
    @Test
    void delete() {

        //Given
        String userId="abc123";
        //When
        user1Mapper.delete(testUserId);

        //Then
        User1DTO removedUser = user1Mapper.select(testUserId);
        assertNull(removedUser);
    }
}