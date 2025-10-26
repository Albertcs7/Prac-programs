SET SERVEROUTPUT ON;
Declare
    val varchar2(20);
BEGIN
    for i in 1..2 loop
        select empname 
        into val
        from employee
        where empid = i;
        DBMS_OUTPUT.PUT_LINE(val);
        end loop;
END;
/
