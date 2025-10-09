DECLARE
    cursor c1 is select sname,mark from students where mark>=70;
    rec1 c1%rowtype;

BEGIN
    for rec1 in c1 loop
        DBMS_OUTPUT.PUT_LINE(rec1.sname||' '||rec1.mark);
    en  d loop;
end;
/