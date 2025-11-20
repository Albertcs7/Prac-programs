create view skjfsb5 AS
select * from students;

begin
    for rec in 1..8 loop
        DBMS_OUTPUT.PUT_LINE('hello');
    end loop;
end;
/
select * from skjfsb5;