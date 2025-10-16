DECLARE
    v_count NUMBER;

BEGIN
    SELECT COUNT(*)
    INTO v_count
    FROM DEPARTMENTS
    WHERE Dept_name = 'Biotech';

    IF v_count = 0 THEN
        INSERT INTO Departments(Dept_ID,Dept_Name,Building,NUMBER_OF_CLASSROOMS)
        VALUES('D05','Biotech','Bio Block',5);

        DBMS_OUTPUT.PUT_LINE('Departments Biotech inserted.');

    else 
        DBMS_OUTPUT.PUT_LINE('Department biotech already exist.');
    END IF;
END;
/        

