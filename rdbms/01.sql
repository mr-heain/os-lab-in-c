--create table

create table student_wo(stid number , sname varchar2(20) , score number);
desc student_wo;
create table stu(sid number primary key, sname varchar2(20) not null, email varchar2(20) unique, age number(10,2) check(age>=18));
desc stu;

--alter table

alter table student_wo drop column score;
alter table stu add gender varchar2(6);
alter table stu drop column age;
alter table stu drop column email;

--rename table 

rename student_wo to student;
desc student;
alter table stu rename column sid to stid;
desc stu;


--truncate & drop 

truncate table stu;
--drop table student;
--drop table stu;
desc student;
desc stu;
