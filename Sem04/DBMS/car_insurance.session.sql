
--@block
CREATE TABLE car_insurance.customer (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    email VARCHAR(100),
    phone_number VARCHAR(15),
    address VARCHAR(255)
);

--@block
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



--@block inserting details in customer table
INSERT INTO car_insurance.customer (first_name, last_name, email, phone_number, address)
VALUES 
    ('Ironman', '', 'ironman@example.com', '+1234567890', 'Stark Tower, New York'),
    ('Batman', '', 'batman@example.com', '+1234567891', 'Wayne Manor, Gotham City'),
    ('Spiderman', '', 'spiderman@example.com', '+1234567892', 'Queens, New York'),
    ('Superman', '', 'superman@example.com', '+1234567893', 'Metropolis');


--@block 
-- Insert cars for Ironman, Batman, Spiderman, and Superman
INSERT INTO car_insurance.car (license_no, model)
VALUES 
    ('MRK42', 'Ironmobile'),
    ('BAT001', 'Batmobile'),
    ('SPIDEY01', 'Web-slinger'),
    ('SUPER001', 'Kryptonian Cruiser');


--@block
INSERT INTO car_insurance.owns (customer_id, license_no)
VALUES 
    ((SELECT customer_id FROM customer WHERE first_name = 'Ironman'), 'MRK42'),
    ((SELECT customer_id FROM customer WHERE first_name = 'Batman'), 'BAT001'),
    ((SELECT customer_id FROM customer WHERE first_name = 'Spiderman'), 'SPIDEY01'),
    ((SELECT customer_id FROM customer WHERE first_name = 'Superman'), 'SUPER001');


--@block
INSERT INTO car_insurance.policy (policy_id)
VALUES
    (294),
    (355),
    (698),
    (830);

-- 2024 March 11
INSERT INTO car_insurance.covers (license_no, policy_id)
VALUES
    ('MRK42', 294),
    ('BAT001', 355),
    ('SPIDEY01', 698),
    ('SUPER001', 830);

--@block
TRUNCATE policy;

--@block
SELECT * FROM customer;
SELECT * FROM owns;
SELECT * FROM car;

--@block
SELECT * FROM policy;

SELECT * FROM covers;

-- queries on database

SELECT * FROM covers
WHERE
    license_no = 'MRK42';

SELECT * FROM customer
WHERE customer_id=(SELECT customer_id FROM owns WHERE license_no='SUPER001');

SELECT * FROM car WHERE model='Batmobile';

SELECT customer_id FROM owns WHERE license_no='SPIDEY01';

