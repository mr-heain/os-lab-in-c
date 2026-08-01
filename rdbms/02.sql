-- its for insert into table

insert into stu values ( 1,'aaa','m');
insert into stu values ( 2,'bbb','f');
insert into stu values ( 3,'ccc','m');
insert into stu values ( 4,'ddd','f');

--select query

select * from stu;
select sname from stu;
select * from stu where gender='f';

--update 

update stu set sname='anu' where stid = 1;
update stu set sname='thameem' , gender='m' where stid =2;
select * from stu;

--delete query

delete from stu where stid=3;
select * from stu;
delete from stu;
select * from stu;
