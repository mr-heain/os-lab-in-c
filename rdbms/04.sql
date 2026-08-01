--predefines exceptions

declare
num1 number := 10;
num2 number := 0;
result number;
begin
result := num1/num2;
DBMS_OUTPUT.PUT_LINE('Result: '||result);
exception
when ZERO_DIVIDE then 
DBMS_OUTPUT.PUT_LINE('cannot divide by zero.');
end;
/


--user defines exception 

declare
insufficient_bal exception;
bal number := 500;
begin
if bal < 1000 then raise insufficient_bal;
end if;
exception 
when insufficient_bal then 
DBMS_OUTPUT.PUT_LINE('Balance is low');
end;
/

--named system exception 

declare
ename empl.ename%type;
begin
select ename into ename from empl where eid = 1001; --its a wrong data data starts from 1201
DBMS_OUTPUT.PUT_LINE('Employee name: ' || ename);
exception
when no_data_found then 
DBMS_OUTPUT.PUT_LINE('no data found with that id ');
end;
/

--unhandled (other) exception

begin
execute immediate 'DROP TABLE nonexistent_table';
exception
when others then 
DBMS_OUTPUT.PUT_LINE('some unecpected error occurred: ' || SQLERRM);
END;
/




