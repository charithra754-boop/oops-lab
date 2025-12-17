# 🚗 Program 6: Car & Airline Database Setup

## Part A: Car Ownership

### 🔄 Order of Creation
1. `PERSON`
2. `CAR`
3. `OWNS` (Depends on `PERSON`, `CAR`)

### 🛠️ Table Creation
```sql
CREATE TABLE PERSON (
    driver_id VARCHAR(20) PRIMARY KEY,
    name VARCHAR(100),
    address VARCHAR(255)
);

CREATE TABLE CAR (
    Regno VARCHAR(20) PRIMARY KEY,
    model VARCHAR(50),
    year INT
);

CREATE TABLE OWNS (
    driver_id VARCHAR(20),
    Regno VARCHAR(20),
    PRIMARY KEY (driver_id, Regno),
    FOREIGN KEY (driver_id) REFERENCES PERSON(driver_id) ON DELETE CASCADE,
    FOREIGN KEY (Regno) REFERENCES CAR(Regno) ON DELETE CASCADE
);
```

### 📥 Data Insertion
```sql
INSERT INTO PERSON VALUES ('D1', 'John', 'Bangalore');
INSERT INTO PERSON VALUES ('D2', 'Alex', 'Mysore');
INSERT INTO PERSON VALUES ('D3', 'Ravi', 'Bangalore');

INSERT INTO CAR VALUES ('KA01-1234', 'Swift', 2018);
INSERT INTO CAR VALUES ('KA02-5678', 'Innova', 2020);
INSERT INTO CAR VALUES ('KA03-9012', 'Honda City', 2019);

INSERT INTO OWNS VALUES ('D1', 'KA01-1234'); -- John owns Swift
INSERT INTO OWNS VALUES ('D1', 'KA02-5678'); -- John owns Innova too
INSERT INTO OWNS VALUES ('D2', 'KA03-9012'); -- Alex owns City
-- Ravi owns nothing (useful for checking left join)
```

---

## Part B: Airline Database

### 🔄 Order of Creation
1. `AIRCRAFT`
2. `EMPLOYEE_AIRLINE`
3. `CERTIFIED` (Depends on `AIRCRAFT`, `EMPLOYEE_AIRLINE`)

### 🛠️ Table Creation
```sql
CREATE TABLE AIRCRAFT (
    Aircraft_ID INT PRIMARY KEY,
    Aircraft_name VARCHAR(100),
    Cruising_range INT
);

CREATE TABLE EMPLOYEE_AIRLINE (
    Emp_ID INT PRIMARY KEY,
    Ename VARCHAR(100),
    Salary DECIMAL(10, 2)
);

CREATE TABLE CERTIFIED (
    Emp_ID INT,
    Aircraft_ID INT,
    PRIMARY KEY (Emp_ID, Aircraft_ID),
    FOREIGN KEY (Emp_ID) REFERENCES EMPLOYEE_AIRLINE(Emp_ID) ON DELETE CASCADE,
    FOREIGN KEY (Aircraft_ID) REFERENCES AIRCRAFT(Aircraft_ID) ON DELETE CASCADE
);
```

### 📥 Data Insertion
```sql
INSERT INTO AIRCRAFT VALUES (101, 'Boeing 747', 5000);
INSERT INTO AIRCRAFT VALUES (102, 'Airbus A320', 3000);
INSERT INTO AIRCRAFT VALUES (103, 'Cessna', 500);

INSERT INTO EMPLOYEE_AIRLINE VALUES (1, 'Pilot A', 150000);
INSERT INTO EMPLOYEE_AIRLINE VALUES (2, 'Pilot B', 120000);
INSERT INTO EMPLOYEE_AIRLINE VALUES (3, 'Steward C', 50000);
INSERT INTO EMPLOYEE_AIRLINE VALUES (4, 'Pilot D', 150000); -- Tie for highest salary

INSERT INTO CERTIFIED VALUES (1, 101); -- Pilot A flies Boeing
INSERT INTO CERTIFIED VALUES (1, 102); -- Pilot A flies Airbus
INSERT INTO CERTIFIED VALUES (2, 103); -- Pilot B flies Cessna
-- Steward C and Pilot D are not certified (useful for query #2)
```
