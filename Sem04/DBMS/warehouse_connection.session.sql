

--@block
CREATE TABLE products(
    product_name VARCHAR(255),
    company VARCHAR(255),
    quantity INT,
    rate DECIMAL(10, 2),
    cost DECIMAL(10, 2)
)


--@block
INSERT INTO products(product_name, company, quantity, rate, cost)
VALUES
    ("Gear Box", "Maruti", 1, 10000, 10000),
    ("Side Mirror", "Maruti", 1, 1500, 1500),
    ("Headlight", "Ferrari", 2, 7000, 7000),
    ("Seat Cover", "Tesla", 4, 5000, 20000)


--@block
-- count all
-- SELECT COUNT * FROM table_name;
SELECT COUNT(*) FROM products;

-- count rate>5k
-- SELECT COUNT * FROM table_name WHERE rate>=20000;
SELECT COUNT(*) FROM products WHERE rate>=5000;

-- group company
-- SELECT column_name, COUNT(*) FROM table_name GROUP BY column_name;
SELECT company, COUNT(*) FROM products GROUP BY company;

-- company count>1
-- SELECT company, COUNT(*) FROM products GROUP BY column_name HAVING COUNT(*) >5 ;
SELECT company, COUNT(*) FROM products GROUP BY company HAVING COUNT(*) >1 ;

-- @block
-- -------- SUM ------------
-- SUM(column_name)

-- SELECT SUM(cost) FROM table_name;
SELECT SUM(cost) FROM products;

-- SELECT SUM(cost) FROM table_name WHERE quantity > 3;
SELECT SUM(cost) FROM products WHERE quantity > 3;

-- SELECT SUM(cost) FROM table_name WHERE quantity > 2 GROUP BY company;
SELECT SUM(cost) FROM products WHERE quantity > 2 GROUP BY company;

-- SELECT company, SUM(cost) FROM table_name GROUP BY company HAVING SUM(count) >= 20000;
SELECT company, SUM(cost) FROM products GROUP BY company HAVING SUM(cost) >= 20000;

-- @block
-- -------- AVG ------------
-- SELECT AVG(cost) FROM table_name;
SELECT AVG(cost) FROM products;

--@block
-- -------- MIN ------------
-- -------- MAX ------------
SELECT MAX(rate) FROM products;
SELECT MAX(rate) FROM products;

--@Block
-- -------- DATE function -----
CREATE TABLE employees(
    id INT PRIMARY KEY,
    name VARCHAR(255),
    birth_time DATETIME
);

--@block
INSERT INTO employees(id, name, birth_time)
VALUES
    (42, "Tony Stark", '1970-05-29 12:00:00');
--@block
SELECT * FROM employees;

--@block
-- DATETIME (DD-MM-YYY HH:MI:SS)
-- DATESTAMP (YYYY-MM-DD HH:MI:SS)
-- YEAR

-- NOW
-- CURDATE
-- CURTIME
-- DATE
-- EXTRACT  
SELECT name, EXTRACT(DAY) FROM birth_time AS birth_day FROM employees;

SELECT name, EXTRACT(YEAR) FROM birth_time AS birth_year FROM employees;

SELECT name, EXTRACT(SECOND) FROM birth_time AS birth_second FROM employees;

-- DATE
-- DATE_ADD(DATE_INTERVAL TYPE)
SELECT name, DATE_ADD(birth_time) interval 1 year AS birth_time modified from employees;
--@block
SELECT name, DATE_ADD(birth_time, interval 30 DAY AS birth_day) modified from employees;

--@block
-- DATE_DIFF()
-- DATE_DIFF(date1, date2);
SELECT DATE_DIFF('2024-02-01', '2024-02-02') AS date_difference;

--@block
DATE_FORMAT(date, format)

--@BLOCK
-- DROP TABLE products;


--@BLOCK
SELECT * FROM products;