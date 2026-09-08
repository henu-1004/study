--교재

--p26
select * from emp;

--p28
desc dept;

--p29
select * from tab;
select empno, ename from emp;

select * from tab;
--p32
--select name, 'good morning~~!' "Good Morning"
--from professor;

--p33
select dname, ',it''s deptno : ', deptno "DNAME AND DEPTNO"
from dept;

--p35
select deptno from emp;
select distinct deptno from emp;

--p36
select job, ename
from emp
order by 1,2;

select distinct job, ename 
from emp
order by 1,2;

--p37
select ename, job from emp;
select ename || job from emp;
select ename||'-'||job from emp;
select ename||' ''s job is '|| job "NAME AND JOB"
from emp;

--p39
select ename||'('||job||'), '||ename||''''||job||'''' "NAME AND JOB"
from emp;

--p40
select ename||'''s sal is $'||sal "Name And Sal"
from emp;

--p41
select empno, ename
from emp
where empno=7900;

select ename, sal
from emp
where sal <900;

select empno, ename, sal
from emp
where ename = 'SMITH';

SELECT ename, hiredate
from emp
where ename = 'SMITH';

select empno, ename, sal
from emp
where hiredate = '80/12/17';

--p45
select empno, ename, sal
from emp
where sal >=4000;

select empno, ename, sal
from emp
where ename >= 'W';

select ename, hiredate from emp;
select ename, hiredate
from emp
where hiredate >= '81/12/25';

select empno, ename, sal
from emp
where sal between 2000 and 3000;

select empno, ename, sal
from emp
where sal >=2000
and sal <=3000;

select ename from emp order by ename;

select ename from emp
where ename between 'JAMES' and 'MARTIN'
order by ename;

--p49
select empno, ename, deptno
from emp
where deptno in (10,20);

select empno, ename, sal
from emp
where sal LIKE '1%';

select empno, ename, sal
from emp
where ename LIKE 'A%';

--p50
SELECT empno, ename, hiredate
from emp
where hiredate like '80%';

select empno, ename, hiredate
from emp
where hiredate like '___12%';

--p52
select empno, ename, comm
from emp
where deptno in (20,30);

select empno, ename, comm
from emp 
where comm is null;

select empno, ename, comm
from emp 
where comm is not null;

--p54
select ename, hiredate, sal
from emp
where hiredate > '82/01/01'
or sal >=1300;

select empno, ename, sal
from emp
where empno = &empno;

select empno , ename
from &table
where sal = 3000;

--p57
select ename, sal, hiredate
from emp;

select ename, sal, hiredate
from emp
order by ename;

00p58
select ename, sal, hiredate
from emp
where sal >1000
order by 2, 1;

--p59
select studno, name, deptno1, 1
from student
where deptno1=101
union all
select profno, name, deptno, 2
from professor
where deptno = 101;


select studno, name, deptno1, 1
from student
where deptno1=101
union
select profno, name, deptno, 2
from professor
where deptno = 101;

--p61
select studno, name
from student
where deptno1 =101
union
select studno, name
from student
where deptno2 = 201;

select studno, name
from student
where deptno1 =101
union all
select studno, name
from student
where deptno2 = 201;

select studno studno, name
from student
where deptno1 = 101
intersect
select studno, name
from student
where deptno2 = 201;

select empno, ename, sal
from emp
minus
select empno, ename, sal
from emp
where sal>2500;

