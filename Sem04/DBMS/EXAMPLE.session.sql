CREATE TABLE Student (
  id INT PRIMARY KEY,
  name VARCHAR(50),
  age INT,
  email VARCHAR(50),
  phone VARCHAR(20)
);

--@block
UPDATE Student 
SET name = "Peter" WHERE AGE = 18

--@block
SELECT * FROM Student

--@block
INSERT INTO Student
VALUES (1, 'Amit', 20, 'amit@gmail.com', '9999999999')

--@block
SELECT * FROM Student


--@Block
UPDATE Student 
SET name = 'Peter' WHERE AGE = 18;

SELECT * FROM Student