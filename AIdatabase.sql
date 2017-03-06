--
-- File generated with SQLiteStudio v3.1.0 on Mon Mar 6 10:35:25 2017
--
-- Text encoding used: System
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: Characters
CREATE TABLE Characters (ID INTEGER PRIMARY KEY, Class CHAR, Health INTEGER, Attack INTEGER, Defense INTEGER, Movement INTEGER);
INSERT INTO Characters (ID, Class, Health, Attack, Defense, Movement) VALUES (1, 'Templar', 100, 8, 12, 5);

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
