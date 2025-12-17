# 🏢 Program 3: Company Database Setup

## 🔄 Order of Creation (Special Handling Required)
Due to a circular dependency between `EMPLOYEE` and `DEPARTMENT` (an Employee works in a Department, but a Department is managed by an Employee), we must follow this specific sequence:

1. `DEPARTMENT` (Create initially *without* the `MgrSSN` foreign key)
2. `EMPLOYEE` (Create with FK to `DEPARTMENT`)
3. **ALTER** `DEPARTMENT` (Add the FK constraint `MgrSSN` referencing `EMPLOYEE`)
4. `DLOCATION` (Depends on `DEPARTMENT`)
5. `PROJECT` (Depends on `DEPARTMENT`)
6. `WORKS_ON` (Depends on `EMPLOYEE`, `PROJECT`)

## 🛠️ Table Creation

```sql
-- 1. Department (Initially without MgrSSN constraint)
CREATE TABLE DEPARTMENT (
    DNo INT PRIMARY KEY,
    DName VARCHAR(100),
    MgrSSN CHAR(9), 
    MgrStartDate DATE
);

-- 2. Employee
CREATE TABLE EMPLOYEE (
    SSN CHAR(9) PRIMARY KEY,
    Name VARCHAR(100),
    Address VARCHAR(255),
    Sex CHAR(1),
    Salary DECIMAL(10, 2),
    SuperSSN CHAR(9),
    DNo INT,
    FOREIGN KEY (DNo) REFERENCES DEPARTMENT(DNo)
);

-- 3. Add Circular FK
ALTER TABLE DEPARTMENT
ADD CONSTRAINT FK_Dept_Mgr
FOREIGN KEY (MgrSSN) REFERENCES EMPLOYEE(SSN);

CREATE TABLE DLOCATION (
    DNo INT,
    DLoc VARCHAR(100),
    PRIMARY KEY (DNo, DLoc),
    FOREIGN KEY (DNo) REFERENCES DEPARTMENT(DNo) ON DELETE CASCADE
);

CREATE TABLE PROJECT (
    PNo INT PRIMARY KEY,
    PName VARCHAR(100),
    PLocation VARCHAR(100),
    DNo INT,
    FOREIGN KEY (DNo) REFERENCES DEPARTMENT(DNo)
);

CREATE TABLE WORKS_ON (
    SSN CHAR(9),
    PNo INT,
    Hours DECIMAL(5, 1),
    PRIMARY KEY (SSN, PNo),
    FOREIGN KEY (SSN) REFERENCES EMPLOYEE(SSN) ON DELETE CASCADE,
    FOREIGN KEY (PNo) REFERENCES PROJECT(PNo) ON DELETE CASCADE
);
```

## 📥 Data Insertion

*Note: Due to circular dependencies, we insert Departments first with NULL managers, then Employees, then update Departments.*

```sql
-- 1. Create Departments (MgrSSN is NULL initially)
INSERT INTO DEPARTMENT (DNo, DName, MgrStartDate) VALUES (1, 'Headquarters', '2019-01-01');
INSERT INTO DEPARTMENT (DNo, DName, MgrStartDate) VALUES (4, 'Administration', '2019-01-01');
INSERT INTO DEPARTMENT (DNo, DName, MgrStartDate) VALUES (5, 'Accounts', '2018-01-01');

-- 2. Create Employees (Referring to Dept DNo)
-- Scott (SSN: 101) - In Accounts
INSERT INTO EMPLOYEE VALUES ('101', 'Scott', 'Bangalore', 'M', 700000, NULL, 5);
-- Smith (SSN: 102) - In Admin
INSERT INTO EMPLOYEE VALUES ('102', 'Smith', 'Mysore', 'M', 450000, '101', 4);
-- John (SSN: 103) - In Accounts
INSERT INTO EMPLOYEE VALUES ('103', 'John', 'Bangalore', 'M', 250000, '101', 5);

-- 3. Update Department Managers
UPDATE DEPARTMENT SET MgrSSN = '101' WHERE DNo = 5; -- Scott manages Accounts
UPDATE DEPARTMENT SET MgrSSN = '102' WHERE DNo = 4;

-- 4. Locations
INSERT INTO DLOCATION VALUES (1, 'Bangalore');
INSERT INTO DLOCATION VALUES (4, 'Mysore');
INSERT INTO DLOCATION VALUES (5, 'Bangalore');

-- 5. Projects
INSERT INTO PROJECT VALUES (10, 'IoT', 'Bangalore', 5);
INSERT INTO PROJECT VALUES (20, 'BigData', 'Mysore', 4);
INSERT INTO PROJECT VALUES (30, 'Cloud', 'Bangalore', 5);

-- 6. Works On
INSERT INTO WORKS_ON VALUES ('101', 10, 10); -- Scott works on IoT
INSERT INTO WORKS_ON VALUES ('101', 30, 5);  -- Scott works on Cloud
INSERT INTO WORKS_ON VALUES ('102', 20, 20); -- Smith works on BigData
INSERT INTO WORKS_ON VALUES ('103', 10, 40); -- John works on IoT
```
