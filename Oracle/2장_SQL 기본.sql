--날짜 : 2025.07.14
--이름 : 서현우
--내용 : 2장 SQL 기본

--실습 1-2. Number 자료형 이해
Drop TABLE TYpe_test_number;
CREATE TABLE TYPE_TEST_NUMBER(
    
    num1 NUMBER,
    num2 NUMBER(2),
    num3 NUMBER(3,1),
    num4 NUMBER(4,2),
    num5 NUMBER(5,6),
    num6 NUMBER(6,-1),
    num7 NUMBER(6,7),
    num8 NUMBER(2,5)
);


--num1 NUMBER
insert into TYPE_TEST_NUMBER (num1) values (1);
insert into TYPE_TEST_NUMBER (num1) values (123);
insert into TYPE_TEST_NUMBER (num1) values (123.74);
insert into TYPE_TEST_NUMBER (num1) values (123.12345);

--num2 NUMBER(2)
insert into TYPE_TEST_NUMBER (num2) values (12);
insert into TYPE_TEST_NUMBER (num2) values (123);
insert into TYPE_TEST_NUMBER (num2) values (1.23);
insert into TYPE_TEST_NUMBER (num2) values (12.34567);
insert into TYPE_TEST_NUMBER (num2) values (12.56789);
insert into TYPE_TEST_NUMBER (num2) values (123.56789);
insert into type_test_number (num2) values (99.99);
--num3 NUMBER(3,1)

insert into TYPE_TEST_NUMBER (num3) values (12);
insert into TYPE_TEST_NUMBER (num3) values (123);
insert into TYPE_TEST_NUMBER (num3) values (12.1);
insert into TYPE_TEST_NUMBER (num3) values (12.1234);
insert into TYPE_TEST_NUMBER (num3) values (12.56789);
insert into TYPE_TEST_NUMBER (num3) values (123.56789);

--num4 NUMBER(4,2)
insert into type_test_number (num4) values (90.99);
insert into type_test_number (num4) values (80.999999);
insert into type_test_number (num4) values (70.55555);
--num5 NUMBER(5,6)
insert into type_test_number (num5) values (0.01234567);
insert into type_test_number (num5) values (0.01234567890123);
--num6 NUMBER(6,-1)
insert into type_test_number (num6) values (129.4);
--num7 NUMBER(6,7)
insert into type_test_number (num7) values (0.01234567);
insert into type_test_number (num7) values (0.01234567890123);
--num8 NUMBER(2,5)
insert into type_test_number (num8) values (0.0001234567);
insert into type_test_number (num8) values (0.0001234567890123);

--실습하기 1-3. 문자형 자료형 이해
CREATE TABLE TYPE_TEST_CHAR(
    char1 CHAR(1),
    char2 CHAR(2),
    char3 CHAR(3),
    vchar1 VARCHAR2(1),
    vchar2 VARCHAR2(2),
    vchar3 VARCHAR(3),
    nvchar1 NVARCHAR2(1),
    nvchar2 NVARCHAR2(2),
    nvchar3 NVARCHAR2(3)
);

//char1(1)
insert into type_test_char (char1) values ('A');
insert into type_test_char (char1) values ('가');

//VARCHAR2
insert into type_test_char (vchar1) values ('A');
insert into type_test_char (vchar2) values ('AB');
insert into type_test_char (vchar3) values ('가');

//nvarchar2
insert into type_test_char (nvchar1) values ('A');
insert into type_test_char (nvchar2) values ('AB');
insert into type_test_char (nvchar3) values ('가나다');


--실습하기 1-4. 테이블 생성
CREATE TABLE USER1 (
    USER_ID VARCHAR2(20),
    NAME VARCHAR2(20),
    HP CHAR(13),
    AGE NUMBER
);

DROP TABLE USER1;

--실습하기 1-5
INSERT INTO USER1 VALUES ('A101', '김유신', '010-1234-1111', 25);
INSERT INTO USER1 VALUES ('A102', '김춘추', '010-1234-2222', 23);
INSERT INTO USER1 VALUES ('A103', '장보고', '010-1234-3333', 32);
INSERT INTO USER1 (user_id, name, age) VALUES ('A104', '강감찬', 45);
INSERT INTO USER1 (user_id,name, hp) VALUES ('A105','이순신','010-1234-5555');

--실습하기 1-6
select * from user1;

select *
from user1
where user_id='A101';

select *
from user1
where name = '김춘추';

select user_id, name, age FROM user1;

--실습하기 1-7
UPDATE USER1
SET HP = '010-1234-4444'
WHERE user_id = 'A104';

UPDATE USER1
SET age = 51
WHERE user_id = 'A105';

UPDATE USER1 
SET HP = '010-1234-1001',AGE=27
WHERE user_id ='A101';

--실습하기 1-8
DELETE FROM USER1
WHERE USER_ID = 'A101';

DELETE FROM USER1
WHERE user_id = 'A102' AND age=25;

DELETE From USER1 WHERE age>=30;


----------------------------------------
--2.제약조건
----------------------------------------

--실습하기 2-1
CREATE TABLE USER2(
    USER_ID VARCHAR2(20) Primary Key,
    NAME VARCHAR2(20),
    HP CHAR(13),
    AGE NUMBER(2)
);

INSERT INTO USER2 VALUES ('A101', '김유신', '010-1234-1111', 23);
INSERT INTO USER2 VAlues ('A102','김춘추','010-1234-2222',21);


--실습하기 2-2
CREATE TABLE USER3(
    USER_ID VARCHAR2(20) Primary Key,
    NAME varchar2(20),
    HP char(13) unique,
    AGE NUMBER(3)
);

insert into user3 values ('a101', '김유신', '010-1234-1111', 23);
insert into user3 values ('a102', '김춘추', '010-1234-2222', 21);

--실습하기 2-3
CREATE TABLE PARENT(
    pid varchar2(20) primary key,
    name varchar2(20),
    hp char(13) unique
);

create table child(
    CID VARCHAR2(20) Primary key,
    NAME varchar2(20),
    HP char(13) unique,
    PARENT VARCHAR2(20),
    FOREIGN KEY (PARENT) REFERENCES PARENT (PID)
);

INSERT INTO PARENT VALUES ('p101', '김서현', '010-1234-1001');
INSERT INTO PARENT VALUES ('p102', '이성계', '010-1234-1002');
INSERT INTO PARENT VALUES ('p103', '신사임당', '010-1234-1003');

INSERT INTO CHILD  VALUES ('c101', '김유신', '010-1234-2001', 'p101');
INSERT INTO CHILD  VALUES ('c102', '이방우', '010-1234-2002','p102');
INSERT INTO CHILD  VALUES ('c103', '이방원', '010-1234-2003','p102');
INSERT INTO CHILD VALUES ('c104', '이이', '010-1234-2004','p103');
--부모 테이블에 p105에 해당하는 값이 없기때문에 참조무결성 제약조건 위배
INSERT INTO CHILD VALUES ('c105', '김철수', '010-1234-2005','p105');

--실습하기 2-4
CREATE TABLE USER4(
    NAME VARCHAR2(20) NOT NULL,
    GENDER CHAR(1) NOT NULL,
    AGE NUMBER(2) DEFAULT 1,
    ADDR VARCHAR2(255)
    );
    
INSERT INTO USER4 VALUES ('김유신', 'M', 23, '김해시');    
INSERT INTO USER4 VALUES ('김춘추', 'M', 21, '경주시');
INSERT INTO USER4 (NAME, GENDER, ADDR) VALUES ('신사임당', 'F', '강릉시');
INSERT INTO USER4 (NAME, GENDER) VALUES ('이순신', 'M');
--정약용은 gender값이 없어서 안들어감
INSERT INTO USER4 (NAME, AGE) VALUES ('정약용', 33);

--실습하기 2-4
CREATE TABLE USER5 (
    NAME VARCHAR2(20) NOT NULL,
    GENDER CHAR(1) NOT NULL CHECK(GENDER IN('M','F')),
    AGE NUMBER(2) DEFAULT 1 CHECK(AGE>0 AND AGE <100),
    ADDR VARCHAR2(255)
);

INSERT INTO USER5 VALUES('김유신', 'M', 23, '김해시');
INSERT INTO USER5 VALUES('김춘추', 'M', 21, '경주시');
INSERT INTO USER5 (NAME, GENDER, ADDR) VALUES ('신사임당', 'F','강릉시');
INSERT INTO USER5 (NAME, GENDER) VALUES ('이순신', 'M');
--정약용 또 gender 설정안해서 삽입 x
INSERT INTO USER5 (NAME, AGE) VALUES ('정약용', 33);

--실습하기 2-5 : IDENTITY
CREATE table USER7(
    id number generated by default as identity primary key,
    name varchar2(20),
    age number,
    email varchar2(100)
);

insert into user7 (name, age, email) values ('김유신',25,'kim@gmail.com');
insert into user7 (name, age, email) values ('장보고',35,'jang@gmail.com');
insert into user7 (name, age, email) values ('이순신',45,'lee@gmail.com');

select * from user7;