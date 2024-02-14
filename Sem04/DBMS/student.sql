-- create
CREATE TABLE STUDENT (
  serial INT,
  enrollment VARCHAR(20),
  name VARCHAR(20),
  age INT,
  mobile_no VARCHAR(20),
  email VARCHAR(20),
  branch VARCHAR(20)
);

-- insert
INSERT INTO STUDENT VALUES (1, 75, 'Anurag Verma', 19, 8224, 'anurag@gmail.com', 'Engineering');
INSERT INTO STUDENT VALUES (2, 75, 'Anurag Verma', 19, 8224, 'anurag@gmail.com', 'Engineering');
INSERT INTO STUDENT VALUES (3, 75, 'Anurag Verma', 19, 8224, 'anurag@gmail.com', 'Engineering');
INSERT INTO STUDENT VALUES (4, 75, 'Anurag Verma', 19, 8224, 'anurag@gmail.com', 'Engineering');
INSERT INTO STUDENT VALUES (5, 75, 'Anurag Verma', 19, 8224, 'anurag@gmail.com', 'Business');

INSERT INTO STUDENT(serial, name) VALUES(6, 'Tony Stark');


-- fetch 
SELECT * FROM STUDENT WHERE serial>0;