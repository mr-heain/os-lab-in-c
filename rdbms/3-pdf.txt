--basic queries

create table empl(eid number primary key, ename varchar2(20) , deptid number , deptname varchar2(20), salary number);
insert into empl values(1201,'adhi',104,'cs',50000);
insert into empl values(1202,'bala',104,'cs',60000);
insert into empl values(1203,'chandru',105,'commerce',40000);
insert into empl values(1204,'dilip',104,'cs',45000);
insert into empl values(1205,'dhana',106,'tamil',30000);
insert into empl values(1206,'ansu',106,'tamil',38000);
insert into empl values (1207,'hari',105,'commerce',58000);

--select query

select * from empl;
select eid, ename,salary from empl;
select * from empl where salary >= 50000;


--aggregate function

select count(*) as totemp from empl;
select sum(salary) as totsalary from empl;
select avg(salary) as avgsalary from empl;
select max(salary) as maxsalary from empl;
select min(salary) as minsalary from empl;
select eid,salary from empl order by salary desc;
select deptid, sum(salary) as sal from empl group by deptid;

--sub queries

select * from empl where salary > (select avg(salary) from empl);
create table dept (deptid number , deptname varchar2(20));
insert into dept values(104,'cs');
insert into dept values(105,'commerce');
insert into dept values(106,'tamil');
insert into dept values(107,'english');
select * from dept;

-- -- -- list department wise employee count

select d.deptname,e.empcount from dept d join(select deptid,count(*) as empcount from empl group by deptid ) e on d.deptid = e.deptid;


--Join Query

select e.eid , e.ename , e.salary , d.deptid,d.deptname from empl e join dept d on e.deptid = d.deptid;
select e.eid , e.ename , e.salary , d.deptid,d.deptname from empl e left join dept d on e.deptid = d.deptid;
select e.eid , e.ename , e.salary , d.deptid,d.deptname from empl e right join dept d on e.deptid = d.deptid;
select e.eid , e.ename , e.salary , d.deptid,d.deptname from empl e cross join dept d ;
