DECLARE
    name students.sname%type;

BEGIN
    select sname into name from students where sid=1;
    DBMS_OUTPUT.PUT_LINE(name);
end;
/