SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE sa(emp_id NUMBER)
IS
    emp_salary NUMBER;
BEGIN
    SELECT salary INTO emp_salary
    FROM emp
    WHERE empid = emp_id;   
    DBMS_OUTPUT.PUT_LINE('Salary: ' || emp_salary);
END;
/
begin 
    sa(3);
end;
/