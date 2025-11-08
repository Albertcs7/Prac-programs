DECLARE
  v_course_id  varchar2(10):='CSE101';
  v_count     NUMBER ;
BEGIN
  SELECT COUNT(*) 
  INTO v_count
  FROM Enrollments
  WHERE Course_ID = v_course_id;

  DBMS_OUTPUT.PUT_LINE('Course '|| v_course_id || ' has ' ||v_count||' students enrolled.');
  END;
/