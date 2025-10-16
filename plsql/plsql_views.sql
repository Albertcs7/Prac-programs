CREATE TABLE employees(
    emp_id NUMBER,
    emp_name VARCHAR2(15),
    dept_id number,
    salary NUMBER
);

INSERT INTO employees VALUES(1,'Amit',10,40000);
-- INSERT INTO employees VALUES(1,'Amit',10,40000);
INSERT INTO employees VALUES(2,'Neha',20,50000);
INSERT INTO employees VALUES(3,'Ravi',10,45000);

CREATE VIEW dept4_view AS 
SELECT emp_id , emp_name , salary
FROM employees WHERE dept_id=10;

SET SERVEROUTPUT ON;
BEGIN
    FOR rec IN (SELECT * FROM dept4_view) LOOP
        DBMS_OUTPUT.PUT_LINE(rec.emp_name || ' EARNS ' || rec.salary);
    END LOOP;
END;
/