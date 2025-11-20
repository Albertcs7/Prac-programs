DECLARE
    var_rows number;
BEGIN
    insert into students values(&SID,&sname,&mark);
    if sql%found then
        var_rows := sql%rowcount;
        DBMS_OUTPUT.PUT_LINE('added '|| var_rows ||' new row');
    end if;
end;
/