CREATE TABLE fruit_colours (
  id INTEGER PRIMARY KEY,
  name VARCHAR(10),
  colour VARCHAR(10)
);
INSERT INTO fruit_colours VALUES (0001, 'apple', 'red');
INSERT INTO fruit_colours VALUES (0002, 'banana', 'yellow');
INSERT INTO fruit_colours VALUES (0003, 'grape', 'green');
INSERT INTO fruit_colours VALUES (0004, 'orange', 'orange');
INSERT INTO fruit_colours VALUES (0005, 'blueberry', 'blue');
INSERT INTO fruit_colours VALUES (0006, 'blackberry', 'black');

SELECT * FROM fruit_colours WHERE id>0;

CREATE TABLE fruit_prices (
  id INTEGER PRIMARY KEY,
  name VARCHAR(10),
  price INTEGER
);

INSERT INTO fruit_prices VALUES (0001, 'apple', 100);
INSERT INTO fruit_prices VALUES (0003, 'banana', 100);
INSERT INTO fruit_prices VALUES (0002, 'grape', 100);
INSERT INTO fruit_prices VALUES (0004, 'orange', 100);
INSERT INTO fruit_prices VALUES (0005, 'blueberry', 100);

SELECT * FROM fruit_prices WHERE id>0;

SELECT *
  FROM fruit_colours t1
   JOIN fruit_prices t2
   USING (name);
    

    