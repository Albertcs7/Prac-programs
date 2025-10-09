DECLARE
    v_total NUMBER;

BEGIN
    SELECT COUNT(*)
    INTO v_total
    FROM student
    WHERE Dep_ID = (SELECT Dep_ID  FROM Departments WHERE Dept_Name = 'Computer Science');

    DBMS_OUTPUT.PUT_LINE('Total students in comupter science= '||v_total);

END;
/    