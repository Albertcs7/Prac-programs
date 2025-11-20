create or replace function format_name(p_name in varchar2)
return varchar2
is
begin
   return upper(p_name);
end;
/
set serveroutput on;

begin
    DBMS_OUTPUT.PUT_LINE('Formatted name: '|| format_name('John Doe'));
end;
/