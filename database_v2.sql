--
-- File generated with SQLiteStudio v3.1.0 on Mon Mar 6 10:24:17 2017
--
-- Text encoding used: System
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: Characters
CREATE TABLE Characters (ID INTEGER PRIMARY KEY, Class INTEGER, Health INTEGER, Attack INTEGER, Defense INTEGER, Movement INTEGER);
INSERT INTO Characters (ID, Class, Health, Attack, Defense, Movement) VALUES (1, 'Mage', 100, 10, 0, 5);
INSERT INTO Characters (ID, Class, Health, Attack, Defense, Movement) VALUES (2, 'Crossbow', 100, 6, 7, 5);
INSERT INTO Characters (ID, Class, Health, Attack, Defense, Movement) VALUES (3, 'Archer', 100, 3, 10, 5);
INSERT INTO Characters (ID, Class, Health, Attack, Defense, Movement) VALUES (4, 'Knight', 100, 10, 8, 5);
INSERT INTO Characters (ID, Class, Health, Attack, Defense, Movement) VALUES (5, 'Berserker', 100, 12, 5, 5);
INSERT INTO Characters (ID, Class, Health, Attack, Defense, Movement) VALUES (6, 'Templar', 100, 8, 12, 5);

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
