-- @block

CREATE TABLE Customer (
    CustomerID INT PRIMARY KEY,
    CustomerName VARCHAR(50),
    LastName VARCHAR(50),
    Country VARCHAR(50),
    Age int(2),
    Phone int(10)
);
DESCRIBE TABLE Customer;

-- CREATE TABLE new_table_name AS
-- SELECT COLUMN1, COLUMN2
-- FROM existing_table_name

CREATE TABLE subtable_customer1
SELECT CustomerID, CustomerName
FROM Customer;

-- insert specific number of records from old table
-- CREATE TABLE new_table_name
-- AS SELECT * FROM old_table_name
-- LIMIT <no_value>


CREATE TABLE subtable_customer2
AS SELECT * FROM Customer LIMIT 4;

--@block
ALTER TABLE CustomerID
CustomerName TO your_name

--@block
DROP TABLE customer
DROP TABLE subtable_customer1;
DROP TABLE subtable_customer2;