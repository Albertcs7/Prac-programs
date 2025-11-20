DECLARE
    cursor c1 is 
        select name,marks from students where marks>=70;
        rec1 c1%rowtype;

BEGIN
    for rec1 in c1 loop
        DBMS_OUTPUT.PUT_LINE(rec1.name||' '||rec1.marks);
    end loop;
end;
/