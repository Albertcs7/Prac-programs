CREATE TABLE student_lo (
    rollno NUMBER,
    action_date date
);


CREATE OR REPLACE TRIGGER trg_check_mark
AFTER INSERT ON students
FOR EACH ROW
BEGIN
    INSERT INTO student_lo VALUES(:NEW.rollno,SYSDATE);
END;
/

                                        