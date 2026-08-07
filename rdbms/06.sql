set serveroutput on
-- sql query


create table student_6( roll_no number primary key, name varchar2(50) , marks number);

--before insert trigger

create or replace trigger trg_before_insert_student
before insert on student_6
for each row
begin
	--if mark not given, set to 0
if :new.marks is null then
   :new.marks:=0;
end if;
end;
/

--after insert trigger

create or replace trigger trg_after_insert_student
after insert on student_6
begin 
dbms_output.put_line('a new student was added!!');
end;
/

insert into student_6(roll_no,name) values(1,'john');

select * from student_6;

--before update trigger

create or replace trigger trg_before_update_student
before update on student_6
for each row
begin 
--prevent marks from being moe than 100
if :new.marks>100 then 
:new.marks:=100;
end if;
end;
/

update student_6 set marks=120 where roll_no =1;

select * from student_6;

--after delete trigger

create or replace trigger trg_after_delete_student
after delete on student_6 
begin
dbms_output.put_line('a student record was deletedd!!!!!');
end;
/

delete from student_6 where roll_no=1;
