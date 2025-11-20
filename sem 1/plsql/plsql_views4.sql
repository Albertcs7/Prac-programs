CREATE VIEW emp_view AS
SELECT emp_id, emp_name
FROM employees;

CREATE OR REPLACE TRIGGER trg_emp_in
INSTEAD OF INSERT ON emp_view
FOR EACH ROW
BEGIN 
    INSERT INTO employees(emp_id,emp_name)
    VALUES(:NEW.emp,:NEW.emp_name);
END;
/
