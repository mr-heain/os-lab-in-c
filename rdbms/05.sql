--select ( to show what we have)

select * from empl;

--implicit cursor

BEGIN
UPDATE empl SET salary = salary + 1000 WHERE eid = 1201;
IF SQL%ROWCOUNT = 1 THEN
DBMS_OUTPUT.PUT_LINE('1 row updated successfully.');
END IF;
END;
/

--show the updated output

select * from empl; 

--explicit cursor

DECLARE
CURSOR empl_cursor IS SELECT eid, ename FROM empl;
v_id empl.eid%TYPE;
v_name empl.ename%TYPE;
BEGIN
OPEN empl_cursor;
LOOP
FETCH empl_cursor INTO v_id, v_name;
EXIT WHEN empl_cursor%NOTFOUND;
DBMS_OUTPUT.PUT_LINE('ID: ' || v_id || ', Name: ' || v_name);
END LOOP;
CLOSE empl_cursor;
END;
/

--cursor FOR loop

BEGIN
FOR empl_rec IN (SELECT eid, ename FROM empl) LOOP
DBMS_OUTPUT.PUT_LINE('ID: ' || empl_rec.eid || ', Name: ' || empl_rec.ename);
END LOOP;
END;
/

--parameterized cursor

DECLARE
CURSOR empl_cursor(p_dept_id NUMBER) IS
SELECT eid, ename FROM empl WHERE deptid = p_dept_id;
v_id empl.eid%TYPE;
v_name empl.ename%TYPE;
BEGIN
OPEN empl_cursor(104); -- passing department id
LOOP
FETCH empl_cursor INTO v_id, v_name;
EXIT WHEN empl_cursor%NOTFOUND;
DBMS_OUTPUT.PUT_LINE('ID: ' || v_id || ', Name: ' || v_name);
END LOOP;
CLOSE empl_cursor;
END;
/
