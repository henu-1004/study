package kr.co.ch04.service;

import kr.co.ch04.dto.User1DTO;
import kr.co.ch04.mapper.User1Mapper;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;


@RequiredArgsConstructor
@Service
public class User1Service {

//    private User1Mapper mapper;
//    @Autowired
//    public User1Service(User1Mapper mapper) {
//        this.mapper = mapper;
//    } 를 아래 로 대체 > @RequiredArgsConstructor 어노테이션주면서
    private final User1Mapper mapper;

    public List<User1DTO> getUsers(){
        return mapper.selectAll();
    }

    public User1DTO getUser(String uid){
        return mapper.select(uid);
    }

    public void save(User1DTO user1DTO){
        mapper.insert(user1DTO);
    }

    public void update(User1DTO user){
        mapper.update(user);
    }

    public void delete(String uid){
        mapper.delete(uid);
    }

}
