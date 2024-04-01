

CREATE TABLE car_insurance.customer (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    email VARCHAR(100),
    phone_number VARCHAR(15),
    address VARCHAR(255)
);


CREATE TABLE car_insurance.car (
    license_no VARCHAR(20) PRIMARY KEY,
    model VARCHAR(100)
);



CREATE TABLE car_insurance.owns (
    customer_id INT,
    license_no VARCHAR(20),
    PRIMARY KEY (customer_id, license_no),
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id),
    FOREIGN KEY (license_no) REFERENCES car(license_no)
);



CREATE TABLE car_insurance.policy (
    policy_id INT PRIMARY KEY AUTO_INCREMENT
);


CREATE TABLE car_insurance.covers (
    license_no VARCHAR(20),
    policy_id INT,
    PRIMARY KEY (license_no, policy_id),
    FOREIGN KEY (license_no) REFERENCES car(license_no),
    FOREIGN KEY (policy_id) REFERENCES policy(policy_id)
);


CREATE TABLE car_insurance.accident (
    report_id INT PRIMARY KEY AUTO_INCREMENT,
    date DATE,
    place VARCHAR(255)
);





CREATE TABLE car_insurance.participated (
    license_no VARCHAR(20),
    accident_report_id INT,
    PRIMARY KEY (license_no, accident_report_id),
    FOREIGN KEY (license_no) REFERENCES car(license_no),
    FOREIGN KEY (accident_report_id) REFERENCES accident(report_id)
);



CREATE TABLE car_insurance.premium_payment (
    payment_no INT PRIMARY KEY AUTO_INCREMENT,
    due_date DATE,
    amount DECIMAL(10, 2),
    received_on DATE
);




CREATE TABLE car_insurance.payment (
    policy_id INT,
    payment_no INT,
    PRIMARY KEY (policy_id, payment_no),
    FOREIGN KEY (policy_id) REFERENCES policy(policy_id),
    FOREIGN KEY (payment_no) REFERENCES premium_payment(payment_no)
);



-- inserting details in customer table
INSERT INTO car_insurance.customer (first_name, last_name, email, phone_number, address)
VALUES 
    ('Iron', 'Man', 'ironman@example.com', '+1234567890', 'Stark Tower, New York'),
    ('Bat', 'Man', 'batman@example.com', '+1234567891', 'Wayne Manor, Gotham City'),
    ('Spider', 'Man', 'spiderman@example.com', '+1234567892', 'Queens, New York'),
    ('Super', 'Man', 'superman@example.com', '+1234567893', 'Metropolis'),
    ('Bruce', 'Banner', 'hulk@example.com', NULL, 'New York');

 
-- Insert cars for Ironman, Batman, Spiderman, and Superman
INSERT INTO car_insurance.car (license_no, model)
VALUES 
    ('MRK42', 'Ironmobile'),
    ('BAT001', 'Batmobile'),
    ('SPIDEY01', 'Web-slinger'),
    ('SUPER001', 'Kryptonian Cruiser'),
    ('Hulk001', 'Batmobile');



INSERT INTO car_insurance.owns (customer_id, license_no)
VALUES 
    ((SELECT customer_id FROM customer WHERE first_name = 'Iron'), 'MRK42'),
    ((SELECT customer_id FROM customer WHERE first_name = 'Bat'), 'BAT001'),
    ((SELECT customer_id FROM customer WHERE first_name = 'Spider'), 'SPIDEY01'),
    ((SELECT customer_id FROM customer WHERE first_name = 'Super'), 'SUPER001'),
    ((SELECT customer_id FROM customer WHERE first_name = 'Bruce'), 'Hulk001');


INSERT INTO car_insurance.policy (policy_id)
VALUES
    (294),
    (355),
    (698),
    (830),
    (840);

INSERT INTO car_insurance.covers (license_no, policy_id)
VALUES
    ('MRK42', 294),
    ('BAT001', 355),
    ('SPIDEY01', 698),
    ('SUPER001', 830),
    ('Hulk001', 840);


INSERT INTO car_insurance.accident (date, place)
VALUES
    ('2024-01-15', 'Main Street'),
    ('2024-02-20', 'Highway 101'),
    ('2024-03-05', 'Oak Street'),
    ('2024-03-10', 'Elm Street');

INSERT INTO car_insurance.participated (license_no, accident_report_id)
VALUES
    ('MRK42', 1),
    ('BAT001', 2),
    ('SPIDEY01', 3),
    ('SUPER001', 4),
    ('Hulk001', 4);


INSERT INTO car_insurance.premium_payment (due_date, amount, received_on)
VALUES 
    ('2024-03-15', 100.00, '2024-03-10'),
    ('2024-03-15', 120.00, '2024-03-12'),
    ('2024-03-15', 150.00, '2024-03-14'),
    ('2024-03-15', 110.00, '2024-03-16'),
    ('2024-03-15', 130.00, '2024-03-18');

INSERT INTO car_insurance.payment (policy_id, payment_no)
VALUES 
    (294, 1),
    (355, 2),
    (698, 3),
    (830, 4),
    (840, 5);

-- queries on database
-- ----------------------- 2
SELECT * FROM covers
WHERE
    license_no = 'MRK42';

SELECT * FROM customer
WHERE customer_id=(SELECT customer_id FROM owns WHERE license_no='SUPER001');


SELECT * FROM car WHERE model='Batmobile' ORDER BY license_no ASC;


-- ----------------------- 3
-- compound condition
SELECT * FROM customer
WHERE first_name = 'Iron' AND last_name = 'Man';

SELECT * FROM customer
WHERE first_name = 'Iron' OR last_name = 'Man';

SELECT * FROM car
WHERE model IN ('Batmobile', 'Web-slinger');

SELECT * FROM accident
WHERE date BETWEEN '2024-01-01' AND '2024-02-01';

SELECT * FROM customer
WHERE address LIKE '%New York%';


-- relational operator
SELECT * FROM customer
WHERE phone_number IS NULL;

-- aggregate function
SELECT COUNT(*) FROM car;

-- -------------- 4
-- updating DATABASE
UPDATE car_insurance.customer
SET phone_number = '+1111111111'
WHERE first_name = 'Super' AND last_name = 'Man';


-- alter in table
ALTER TABLE car_insurance.customer
ADD COLUMN date_of_birth DATE;

select * from customer;
select * from participated;

-- delete from table
DELETE FROM car_insurance.participated
WHERE license_no = 'MRK42';

select * from participated;

-- ----------------------- 5
SELECT 
    SUM(amount) AS total_amount,
    AVG(amount) AS average_amount,
    COUNT(*) AS total_payments,
    MAX(amount) AS max_amount,
    MIN(amount) AS min_amount
FROM car_insurance.premium_payment;


-- ----------------------- 6
-- Single-Row Subquery
SELECT *
FROM car_insurance.customer
WHERE customer_id = (
    SELECT customer_id
    FROM car_insurance.owns
    WHERE license_no = 'MRK42'
);

-- Multiple-Row Subquery
SELECT *
FROM car_insurance.accident
WHERE report_id IN (
    SELECT accident_report_id
    FROM car_insurance.participated
    WHERE license_no IN (
        SELECT license_no
        FROM car_insurance.owns
        WHERE customer_id IN (
            SELECT customer_id
            FROM car_insurance.customer
            WHERE address LIKE '%New York%'
        )
    )
);

-- Scalar Subquery
SELECT *,
    (SELECT COUNT(*) FROM car_insurance.payment WHERE policy_id = p.policy_id) AS num_payments
FROM car_insurance.policy p;

-- Subquery in (DML) INSERT statement
INSERT INTO car_insurance.customer (first_name, last_name, email, phone_number, address)
VALUES (
    'Black',
    'Panther',
    'blackpanther@example.com',
    '+1234567894',
    'Wakanda'
);


INSERT INTO car_insurance.car (license_no, model)
VALUES (
    'PANTHER001',
    'Black Panther'
);

INSERT INTO car_insurance.owns (customer_id, license_no)
VALUES (
    (SELECT customer_id FROM car_insurance.customer WHERE first_name = 'Black' AND last_name = 'Panther'),
    'PANTHER001'
);
select * from customer WHERE first_name='Black' AND last_name='Panther';


-- Deleting Black Panther from Database
DELETE FROM owns WHERE license_no="PANTHER001";
DELETE FROM car WHERE license_no="PANTHER001";
DELETE FROM customer WHERE first_name="Black";


-- Nested Subquery
SELECT c.first_name, c.last_name, a.date
FROM car_insurance.customer c
JOIN car_insurance.owns o ON c.customer_id = o.customer_id
JOIN car_insurance.participated p ON o.license_no = p.license_no
JOIN car_insurance.accident a ON p.accident_report_id = a.report_id;



-- ----------------------- 7
-- 1 simple
SELECT COUNT(*) AS total_accidents FROM car_insurance.accident;

SELECT AVG(amount) AS average_premium_amount FROM car_insurance.premium_payment;

-- 2 Group by and having


-- SELECT place, COUNT(*) AS total_accidents
-- FROM car_insurance.accident
-- GROUP BY place;

SELECT place, COUNT(*) AS total_accidents
FROM car_insurance.accident
GROUP BY place
HAVING COUNT(*) >= 1;


-- SELECT customer.*, car.model
-- FROM car_insurance.customer
-- INNER JOIN car_insurance.owns ON customer.customer_id = owns.customer_id
-- INNER JOIN car_insurance.car ON owns.license_no = car.license_no;


-- SELECT c.*, p.policy_id
-- FROM car_insurance.customer c
-- LEFT JOIN car_insurance.policy p ON c.customer_id = p.policy_id;


-- SELECT *
-- FROM car_insurance.customer
-- WHERE customer_id IN (
--     SELECT customer_id
--     FROM car_insurance.owns
--     WHERE license_no IN (
--         SELECT license_no
--         FROM car_insurance.participated
--     )
-- );


-- SELECT *
-- FROM car_insurance.customer c
-- WHERE EXISTS (
--     SELECT 1
--     FROM car_insurance.payment p
--     WHERE p.policy_id = c.customer_id
-- );

-- 3. Inner and outer join

-- IN
SELECT customer.*, car.model
FROM car_insurance.customer
INNER JOIN car_insurance.owns ON customer.customer_id = owns.customer_id
INNER JOIN car_insurance.car ON owns.license_no = car.license_no
WHERE customer.customer_id IN (
    SELECT customer_id
    FROM car_insurance.owns
    WHERE license_no IN (
        SELECT license_no
        FROM car_insurance.participated
    )
);

-- EXISTS
SELECT c.license_no, c.model
FROM car_insurance.car c
WHERE EXISTS (
    SELECT 1
    FROM car_insurance.participated p
    INNER JOIN car_insurance.accident a ON p.accident_report_id = a.report_id
    WHERE p.license_no = c.license_no
);


select * from policy;
select * from customer;

-- ----------------------- 8
CREATE VIEW customer_car_view AS
SELECT c.*, car.model AS car_model
FROM car_insurance.customer c
INNER JOIN car_insurance.owns ON c.customer_id = owns.customer_id
INNER JOIN car_insurance.car ON owns.license_no = car.license_no;

SELECT * FROM customer WHERE first_name="Mr" AND last_name="Bean";
-- INSERT INTO customer_car_view (first_name, last_name, email, phone_number, address, car_model)
-- VALUES ('Mr', 'Bean', 'mrbean@example.com', '+123456789', '123 Main St', 'Toyota Camry');
INSERT INTO customer_car_view (first_name, last_name, email, phone_number, address)
VALUES ('Mr', 'Bean', 'mrbean@example.com', '+123456789', '123 Main St');

INSERT INTO customer_car_view (license_no ,car_model)
-- VALUES ('Mini Cooper');
VALUES ('SLW287R','Mini Cooper');


-- INSERT INTO car_insurance.customer (first_name, last_name, email, phone_number, address)
-- VALUES ('Mr', 'Bean', 'mrbean@example.com', '+123456789', '123 Main St');

-- INSERT INTO car_insurance.car (license_no, model)
-- VALUES ('ABC123', 'Toyota Camry');

-- INSERT INTO car_insurance.owns (customer_id, license_no)
-- VALUES ((SELECT customer_id FROM car_insurance.customer WHERE first_name = 'Mr' AND last_name = 'Bean'), 'ABC123');



UPDATE customer_car_view
SET phone_number = '+987654321'
WHERE first_name = 'Mr' AND last_name = 'Bean';



ALTER VIEW customer_car_view AS
SELECT c.customer_id, c.first_name, c.last_name, c.email, c.phone_number, c.address, car.model AS car_model
FROM car_insurance.customer c
INNER JOIN car_insurance.car ON owns.license_no = car.license_no;
INNER JOIN car_insurance.owns ON c.customer_id = owns.customer_id


DROP VIEW IF EXISTS customer_car_view;

SELECT * FROM customer_car_view;

SELECT * FROM customer WHERE first_name="Mr" AND last_name="Bean";
SELECT * FROM customer;
SELECT * FROM owns;
SELECT * FROM car;

DELETE FROM owns WHERE license_no="ABC123";
DELETE FROM car WHERE license_no="ABC123";
DELETE FROM customer WHERE first_name="Mr";


-- --------------------- 2024 March 19 - In lab

-- ----- Horizontal View
CREATE VIEW CUSTOM_VIEW AS SELECT *
FROM customer WHERE last_name =  'Man';
SELECT * FROM CUSTOM_VIEW;

-- ----- Vertical View
CREATE VIEW CUSTOM_VIEW1 AS SELECT first_name, last_name, phone_number from customer;
SELECT * FROM CUSTOM_VIEW1;

