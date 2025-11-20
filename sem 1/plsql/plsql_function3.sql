create or replace function get_salary(p_empid in number)
return number
is
    v_salary number;
begin
   select salary into v_salary
   FROM employees
   WHERE employee_id = p_empid;

   RETURN v_salary;
EXCEPTION
    WHEN NO_DATA_FOUND then
    return NULL;
end;
/
set serveroutput on;

begin
    DBMS_OUTPUT.PUT_LINE('Salary of employee: '|| get_salary(1));
end;
/