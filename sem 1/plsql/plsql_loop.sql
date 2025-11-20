-- database: :memory:
DECLARE
    i NUMBER;
    v NUMBER;
    s varchar(6);
    
BEGIN
    for i in 1..4 LOOP
        SELECT id,name 
        INTO v,s
        FROM person
        WHERE id = i ;
        DBMS_OUTPUT.PUT_LINE('ID '||v||' name: '||s);
    END LOOP;

END;
/        
