CREATE OR REPLACE FUNCTION square(numb NUMBER)
RETURN NUMBER
IS
    sqr NUMBER;
BEGIN
    sqr := numb * numb;
    RETURN sqr;
END;
/

SET SERVEROUTPUT ON;

DECLARE 
    numb NUMBER;
    i NUMBER;
BEGIN
    FOR i IN 1..10 LOOP
        SELECT num INTO numb
        FROM val
        WHERE num = i;

        DBMS_OUTPUT.PUT_LINE('Square of ' || numb || ' is: ' || square(numb));
    END LOOP;
END;
/



