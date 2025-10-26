set SERVEROUTPUT on;
DECLARE 
    cursor c2 is
        select empname,salary from emp;
    rec c2%rowtype;
BEGIN      
    for rec in c2 loop   
        DBMS_OUTPUT.PUT_LINE('Empname:'||rec.empname||' Salary:'||rec.salary);
    end loop;
end;
/
