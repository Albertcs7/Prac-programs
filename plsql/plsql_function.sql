create or replace function get_square(p_num in number)
return number
is
    v_result number;
begin
    v_result := p_num * p_num;
    return v_result;
end;
/
set serveroutput on;

begin
    DBMS_OUTPUT.PUT_LINE('Square of 9 is;'|| get_square(9));
end;
/