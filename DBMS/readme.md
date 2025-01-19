------------------------------------------------
SQL

1) CREATE TABLE
2) SELECT
3) DISTINCT
4) DISTINCT ON
5) SERIAL
6) PRIMARY KEY
7) NOT NULL
8) NULL
9) CHECK
10) Operators: 
    a) >
    b) >=
    c) <
    d) <=
    e) =
    f) != (or) <>
    g) IN
    h) NOT
    i) AND
    j) OR
    k) BETWEEN
    m) LIKE and ILIKE
        i) %
        ii) _
    n) IS NULL
11) LIMIT
12) OFFSET
13) FETCH (https://neon.tech/postgresql/postgresql-tutorial/postgresql-fetch)

-------
content

It’s important to note that PostgreSQL evaluates the OFFSET clause before the LIMIT clause.

PostgreSQL stores rows in a table in an unspecified order, therefore, when you use the LIMIT clause, you should always use the ORDER BY clause to control the row order.

If you don’t use the ORDER BY clause, you may get a result set with the rows in an unspecified order.


----------------
One column depending on another in the table:

```sql
DROP TABLE IF EXISTS student;
CREATE TABLE student(
	"roll number" INT CHECK >= 0,
	"first name" CHAR(50),
	"last name" CHAR(50),
	"full name" TEXT GENERATED ALWAYS AS ("first name" || ' ' || "last name") STORED,

	PRIMARY KEY("full name")
);

INSERT INTO student
VALUES
	(112101011, 'chekkala sandeep', 'reddy'),
	(112101011, 'chekkala sandeep', 'reddz');

SELECT * 
FROM student;
```

-----
GOOD concept

```sql
DROP TABLE IF EXISTS student_scores;

-- Create sequence explicitly with a starting value
CREATE SEQUENCE student_scores_id_seq 
START WITH 1000
INCREMENT BY 2;

CREATE TABLE student_scores (
  id INT PRIMARY KEY DEFAULT nextval('student_scores_id_seq'),
  name VARCHAR(50) NOT NULL,
  subject VARCHAR(50) NOT NULL,
  score INTEGER NOT NULL CHECK (score >= 0)
);

-- Associate sequence with the 'id' column
ALTER SEQUENCE student_scores_id_seq OWNED BY student_scores.id;


INSERT INTO student_scores (name, subject, score)
VALUES
  ('Alice', 'Math', 90),
  ('Bob', 'Math', 85),
  ('Alice', 'Physics', 92),
  ('Bob', 'Physics', 88),
  ('Charlie', 'Math', 95),
  ('Charlie', 'Physics', 90);

SELECT *
FROM student_scores;

-- retrieve the highest score for each student in either Math or Physics


SELECT  name, MAX(score)
FROM student_scores
GROUP BY name;

-- using the DISTINCT ON clause:
SELECT
DISTINCT ON(name)
	id,
	name,
	subject,
	score as "max score"
FROM student_scores
ORDER BY name, score DESC;
```