CREATE TABLE customer2 (
    id INT NOT NULL,
    name CHARACTER(25)
)

ALTER TABLE customer2
RENAMAE COLUMN id TO ID2;

--@block
DROP TABLE customer2;