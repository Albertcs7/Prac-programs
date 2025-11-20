-- Corrected table creation
CREATE TABLE students (
    rollno NUMBER,
    name VARCHAR2(30),
    marks NUMBER
);

-- Corrected trigger
CREATE OR REPLACE TRIGGER trg_check_mark
BEFORE INSERT ON students
FOR EACH ROW
BEGIN
    IF :NEW.marks < 35 THEN
        RAISE_APPLICATION_ERROR(-20001, 'Marks must be at least 35');
    END IF;
END;
/

                                        