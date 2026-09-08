insert into customer values ('760121-1234567','정우성','서울','1976-01-21',null, '010-1101-7601','배우');
insert into customer values ('750611-1234567','이정재','서울','1975-06-11',null, '010-1102-7506', '배우');
insert into customer values ('890530-1234567','전지현','대전','1989-05-30','jjh@naver.com','010-1103-8905', '자영업');
insert into customer values ('790413-1234567','이나영','대전','1979-04-13','lee@naver.com', '010-2101-7904','회사원');
insert into customer values ('660912-1234567','원빈','대전','1966-09-12','one@daum.net','010-2104-6609','배우');

drop table customer;
drop table card;
drop table account;
drop table transaction;
commit;


INSERT INTO card values('2111-1001-1001', '760121-1234567', '1011-1001-1001', '2020-01-21', 1000000, '2020-02-10', 'check');
INSERT INTO card values('2041-1001-1002', '890530-1234567', '1011-1001-1002', '2020-06-11', 3000000, '2020-06-15', 'check');
INSERT INTO card values('2011-1001-1003', '790413-1234567', '1011-1001-1003', '2020-05-30', 5000000, '2020-06-25', 'check');
INSERT INTO card values('2611-1001-1005', '750611-1234567', '1011-1002-1005', '2020-09-12', 1500000, '2020-10-10', 'check');


INSERT INTO account VALUES ('1011-1001-1001', '760121-1234567', '자유입출금', 4160000, 'Y', '2020-01-21 13:00:02');
INSERT INTO account VALUES ('1011-1001-1002', '890530-1234567', '자유입출금', 376000, 'Y', '2020-06-11 13:00:02');
INSERT INTO account values ('1011-2001-1004', '790413-1234567', '자유입출금', 1200000, 'Y', '2020-05-30 13:00:02');
INSERT INTO account VALUES ('1011-1001-1003', '660912-1234567', '정기적금', 1000000, 'N', '2020-04-13 13:00:02');
INSERT INTO account VALUES ('1011-1002-1005', '750611-1234567', '자유입출금', 820000, 'Y', '2020-09-12 13:00:02');


INSERT INTO transaction (trans_acc_id, trans_type, trans_message, trans_money, trans_date) VALUES ('1011-1001-1001', '입금', '2월 정기급여', 3500000, '2020-02-10 12:36:12');
INSERT INTO transaction (trans_acc_id, trans_type, trans_message, trans_money, trans_date) VALUES ('1011-1001-1003', '출금', 'ATM 출금', 300000, '2020-02-10 12:37:21');
INSERT INTO transaction (trans_acc_id, trans_type, trans_message, trans_money, trans_date) VALUES ('1011-1001-1002', '입금', '2월 급여', 2800000, '2020-02-10 12:38:21');
INSERT INTO transaction (trans_acc_id, trans_type, trans_message, trans_money, trans_date) VALUES ('1011-1001-1001', '출금', '2월 공과금', 116200, '2020-02-10 12:39:21');
INSERT INTO transaction (trans_acc_id, trans_type, trans_message, trans_money, trans_date) VALUES ('1011-1002-1005', '출금', 'ATM 출금', 50000, '2020-02-10 12:40:21');

--1.모든고객정보를 조회하시오.
select * from customer;

--2.모든 카드 정보를 조회하시오.
select * from card;

--3.모든 예금계좌 정보를 조회하시오.
select * from account;

--4.가장 최근 거래내역 3건 조회하시오.
select *
from transaction
order by trans_date desc
fetch first 3 rows only;

--5.카드 한도 금액이 200만원 이상인 고객의 이름과 카드 종류를 조회하시오.
select a.name, b.card_limit
from customer a join card b on a.cust_jumin = b.cust_jumin
where b.card_limit >=2000000;


--6.예금계좌별 거래 건수를 조회하시오.
select a.acc_id, count(trans_acc_id) as 거래건수
from account a join transaction b on a.acc_id = b.trans_acc_id
group by a.acc_id;

--7.거래금액이 100만원 이상인 거래내역 조회(최근거래순)
select *
from transaction
where trans_money >=1000000
order by trans_money desc;

--8.계좌와 연결된 카드 정보 조회(계좌id, 카드id, 카드종류)하시오.
select a.acc_id 계좌id, nvl(b.card_no, '연결카드 없음') 카드id, nvl(b.card_type, '연결카드 없음') 카드종류
from account a left join card b on  a.acc_id = b.acc_id;


--9.예금 구분이 입금인 거래의 총합 조회하시오.
select sum(trans_money) as "입금거래 총합"
from transaction
where trans_type = '입금';

--10.예금잔고가 400만원 이상 고객에 대한 고객명, 주민번호, 전화번호, 주소를 조회하시오.
select a.name, a.cust_jumin, a.hp, a.address
from customer a join account b on a.cust_jumin = b.cust_jumin
join transaction c on b.acc_id = c.trans_acc_id
GROUP BY a.name, a.cust_jumin, a.hp, a.address
HAVING (max(b.acc_balance) + SUM(
           CASE 
               WHEN c.trans_type = '입금' THEN c.trans_money
               WHEN c.trans_type = '출금' THEN -c.trans_money
               ELSE 0
           END
       ) >= 4000000);


