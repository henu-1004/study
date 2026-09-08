/*
날짜 : 2025.07.17
이름 : 서현우
내용 : 6장 pl/sql
*/

--1.pl/sql 구조
--실습 1-1
set SERVEROUTPUT on;

begin
    dbms_output.put_line('hello, oracle!');
end;

--1-2
declare
    no number(4) :=1001;
    name varchar2(10) :='홍길동';
    hp char(13) := '010-1000-1001';
    addr varchar2(100) := '부산광역시';
begin
    --dbms_output.put_line('번호 : ' || no);
    dbms_output.put_line('이름 : ' || name);
    dbms_output.put_line('전화 : ' || hp);
    dbms_output.put_line('주소 : ' || addr);
end;
/

--2.변수와 상수
--2-1.변수선언 및 변수값 출력

DECLARE
    NO CONSTANT NUMBER(4) := 1001;
    NAME VARCHAR2(10);
    HP CHAR(13) := '000-0000-0000';
    AGE NUMBER(2) DEFAULT 1;
    ADDR VARCHAR2(10) NOT NULL := '부산';
BEGIN
    NAME := '김유신';
    HP := '010-1000-1001';
    DBMS_OUTPUT.PUT_LINE('번호 : ' || NO);
    DBMS_OUTPUT.PUT_LINE('이름 : ' || NAME);
    DBMS_OUTPUT.PUT_LINE('전화 : ' || HP);
    DBMS_OUTPUT.PUT_LINE('나이 : ' || AGE);
    DBMS_OUTPUT.PUT_LINE('주소 : ' || ADDR);
END;
/

--2-2.열참조형 변수
DEclare
    no dept.deptno%type; -- no number(4)  이런느낌이랑 비슷한거 dept테이블의 컬럼참조함
    name dept.dname%type;
    dtel dept.dtel%type;
begin
    select DEPTNO ,DNAME ,DTEL  
    into no, name, dtel
    from dept
    where deptno=30;
    
    dbms_output.put_line('부서번호 : ' || no);
    dbms_output.put_line('부서명 : ' || name);
    dbms_output.put_line('전화번호 : ' || dtel);
end;
/

--2-3. 행참조형 변수
DECLARE
    -- 선언
    ROW_DEPT DEPT%ROWTYPE;
BEGIN
    -- 처리
    SELECT *
    INTO ROW_DEPT
    FROM DEPT
    WHERE DEPTNO = 40;
    -- 출력
    DBMS_OUTPUT.PUT_LINE('부서번호 : ' || ROW_DEPT.DEPTNO);
    DBMS_OUTPUT.PUT_LINE('부서명 : ' || ROW_DEPT.DNAME);
    DBMS_OUTPUT.PUT_LINE('전화번호 : ' || ROW_DEPT.dtel);
END;
/

--2-4
declare
    type rec_dept is record(
        deptno number(2),
        dname dept.dname%type,
        dtel dept.dtel%type
    );
    
    dept_rec rec_dept;
begin
    dept_rec.deptno := 10;
    dept_rec.dname := '개발부';
    dept_rec.dtel := '051-512-1010';

    dbms_output.put_line('deptno : ' || dept_rec.deptno);
    dbms_output.put_line('dname : ' || dept_rec.dname);
    dbms_output.put_line('dtel : ' || dept_rec.dtel);
end;
/

--2-7.테이블(연관배열) 기본 실습

declare
    type arr_city is table of varchar2(20) index by pls_integer;
    arrcity arr_city;
begin
    arrcity(1) := '서울';
    arrcity(2) := '대전';
    arrcity(3) := '대구';
    
    DBMS_OUTPUT.PUT_LINE('arrCity(1) : ' || arrCity(1));
    DBMS_OUTPUT.PUT_LINE('arrCity(2) : ' || arrCity(2));
    DBMS_OUTPUT.PUT_LINE('arrCity(3) : ' || arrCity(3));
    DBMS_OUTPUT.PUT_LINE('PL/SQL 종료...');
end;
/

--4.커서와 예외처리
--실습 4-1
declare
    --커서 데이터를 저장할 변수 선언
    v_dept_row dept%rowtype;
    
    --커서선언    
    cursor c1 is select * from dept where deptno=40;
begin
    --커서열기
    open c1;
    
    --커서 데이터 입력
    fetch c1 into v_dept_row;
    
    --커서데이터 출력
    DBMS_OUTPUT.PUT_LINE('DEPTNO : ' || V_DEPT_ROW.DEPTNO);
    DBMS_OUTPUT.PUT_LINE('DNAME : ' || V_DEPT_ROW.DNAME);
    DBMS_OUTPUT.PUT_LINE('DTEL : ' || V_DEPT_ROW.dtel);
    
    --커서 종료
    close c1;
end;
/

--실습4-2 여러행결과를처리하는커서사용 Loop사용
declare
    v_emp_row emp%rowtype;
    cursor emp_cursor is select * from emp;
begin
    open emp_cursor;
    Loop
        fetch emp_cursor into v_emp_row;
        exit when emp_cursor%notfound;
        
        DBMS_OUTPUT.PUT_LINE('------------------------------');
        DBMS_OUTPUT.PUT_LINE('empno : ' || V_emp_ROW.empno);
        DBMS_OUTPUT.PUT_LINE('empno : ' || V_emp_ROW.name);
        DBMS_OUTPUT.PUT_LINE('empno : ' || V_emp_ROW.regdate);
    end Loop;
    
    close emp_cursor;
end;
/

--실습4-3 > 여러행결과를 처리하는 커서 for사용
declare
    cursor c1 is select * from dept;
begin
    
    for c1_rec in c1 loop
        dbms_output.put_line('---------------------');
        dbms_output.put_line('deptno : ' || c1_rec.deptno);
        dbms_output.put_line('dname : ' || c1_rec.dname);
        dbms_output.put_line('dtel : ' || c1_rec.dtel);
    
    end loop;

end;
/

--실습 5-1
create procedure hello_procedure(p_name IN VARCHAR2)
IS
BEGIN
    dbms_output.put_line('안녕하세요,' || p_name || '님!');
    dbms_output.put_line('환영합니다.');
end;
/

--프로시저 실행1
execute hello_procedure('홍길동');

drop procedure hello_procedure;


--실습 5-2
create function get_emp_name (p_empno number) return varchar2
is
    v_ename varchar2(20);
begin
    select name into v_ename from emp where empno=p_empno;
    return v_ename;
end;
/

drop function get_emp_name;

select get_emp_name(1001) from dual;

--실습 5-3 트리거
create table emp_log(
    log_date date,
    empno number,
    action varchar(10)
);

--트리거 생성
create trigger trgg_emp_insert
after insert on emp
for each row
begin
    insert into emp_log (log_date, empno, action)
    values(sysdate, :new.empno, 'insert');
end;
/


--insert테스트
insert into emp values(2001,'김유신','M', '사원', 10, sysdate);
insert into emp values(2002,'김춘추','M', '사원', 20, sysdate);

--로그확인
select * from emp_log;





