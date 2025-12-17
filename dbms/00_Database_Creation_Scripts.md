# 🛠️ Database Creation Scripts

Here are the SQL `CREATE TABLE` statements and MongoDB setup commands to initialize the databases for all the lab programs.

---

## 📚 Program 1: Library Database

**Order of Creation:** `PUBLISHER` -> `LIBRARY_BRANCH` -> `BOOK` -> `BOOK_AUTHORS` -> `BOOK_COPIES` -> `BOOK_LENDING`.

```sql
CREATE TABLE PUBLISHER (
    Name VARCHAR(100) PRIMARY KEY,
    Address VARCHAR(255),
    Phone VARCHAR(20)
);

CREATE TABLE LIBRARY_BRANCH (
    Branch_id INT PRIMARY KEY,
    Branch_Name VARCHAR(100),
    Address VARCHAR(255)
);

CREATE TABLE BOOK (
    Book_id INT PRIMARY KEY,
    Title VARCHAR(255),
    Publisher_Name VARCHAR(100),
    Pub_Year INT,
    FOREIGN KEY (Publisher_Name) REFERENCES PUBLISHER(Name) ON DELETE CASCADE
);

CREATE TABLE BOOK_AUTHORS (
    Book_id INT,
    Author_Name VARCHAR(100),
    PRIMARY KEY (Book_id, Author_Name),
    FOREIGN KEY (Book_id) REFERENCES BOOK(Book_id) ON DELETE CASCADE
);

CREATE TABLE BOOK_COPIES (
    Book_id INT,
    Branch_id INT,
    No_of_Copies INT,
    PRIMARY KEY (Book_id, Branch_id),
    FOREIGN KEY (Book_id) REFERENCES BOOK(Book_id) ON DELETE CASCADE,
    FOREIGN KEY (Branch_id) REFERENCES LIBRARY_BRANCH(Branch_id) ON DELETE CASCADE
);

CREATE TABLE BOOK_LENDING (
    Book_id INT,
    Branch_id INT,
    Card_No INT,
    Date_Out DATE,
    Due_Date DATE,
    PRIMARY KEY (Book_id, Branch_id, Card_No),
    FOREIGN KEY (Book_id) REFERENCES BOOK(Book_id) ON DELETE CASCADE,
    FOREIGN KEY (Branch_id) REFERENCES LIBRARY_BRANCH(Branch_id) ON DELETE CASCADE
);
```

---

## 🎓 Program 2: College Database

**Order of Creation:** `STUDENT` -> `SEMSEC` -> `CLASS` -> `SUBJECT` -> `IAMARKS`.

```sql
CREATE TABLE STUDENT (
    USN VARCHAR(20) PRIMARY KEY,
    SName VARCHAR(100),
    Address VARCHAR(255),
    Phone VARCHAR(20),
    Gender CHAR(1)
);

CREATE TABLE SEMSEC (
    SSID VARCHAR(20) PRIMARY KEY,
    Sem INT,
    Sec CHAR(1)
);

CREATE TABLE CLASS (
    USN VARCHAR(20),
    SSID VARCHAR(20),
    PRIMARY KEY (USN, SSID),
    FOREIGN KEY (USN) REFERENCES STUDENT(USN) ON DELETE CASCADE,
    FOREIGN KEY (SSID) REFERENCES SEMSEC(SSID) ON DELETE CASCADE
);

CREATE TABLE SUBJECT (
    Subcode VARCHAR(20) PRIMARY KEY,
    Title VARCHAR(100),
    Sem INT,
    Credits INT
);

CREATE TABLE IAMARKS (
    USN VARCHAR(20),
    Subcode VARCHAR(20),
    SSID VARCHAR(20),
    Test1 INT,
    Test2 INT,
    Test3 INT,
    FinalIA DECIMAL(5, 2),
    PRIMARY KEY (USN, Subcode, SSID),
    FOREIGN KEY (USN) REFERENCES STUDENT(USN) ON DELETE CASCADE,
    FOREIGN KEY (Subcode) REFERENCES SUBJECT(Subcode) ON DELETE CASCADE,
    FOREIGN KEY (SSID) REFERENCES SEMSEC(SSID) ON DELETE CASCADE
);
```

---

## 🏢 Program 3: Company Database

**Note:** This schema has a circular dependency (`EMPLOYEE` needs `DEPARTMENT`, `DEPARTMENT` needs `EMPLOYEE` manager). We create tables first, then add the foreign key constraint for the manager.

```sql
-- 1. Create Department without Manager FK first
CREATE TABLE DEPARTMENT (
    DNo INT PRIMARY KEY,
    DName VARCHAR(100),
    MgrSSN CHAR(9), 
    MgrStartDate DATE
);

-- 2. Create Employee
CREATE TABLE EMPLOYEE (
    SSN CHAR(9) PRIMARY KEY,
    Name VARCHAR(100),
    Address VARCHAR(255),
    Sex CHAR(1),
    Salary DECIMAL(10, 2),
    SuperSSN CHAR(9),
    DNo INT,
    FOREIGN KEY (SuperSSN) REFERENCES EMPLOYEE(SSN),
    FOREIGN KEY (DNo) REFERENCES DEPARTMENT(DNo)
);

-- 3. Add Manager FK to Department
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

---

## 🍃 Program 4: Employee Database (MongoDB)

Since MongoDB is schema-less, you don't strictly *need* to create a collection, but here is how you initialize it with a sample document to enforce structure if desired.

```javascript
// Switch to database
use employee_db

// Create collection explicitly (optional)
db.createCollection("employee")

// Insert a sample document to establish structure
db.employee.insertOne({
    eid: 1,
    ename: "Rahul",
    dept: "IT",
    design: "developer",
    salary: 50000,
    yoj: 2020,
    address: {
        dno: "101",
        street: "MG Road",
        locality: "Indiranagar",
        city: "Bangalore"
    }
})
```

---

## 🍝 Program 5: Restaurant Database (MongoDB)

```javascript
// Switch to database
use restaurant_db

// Create collection
db.createCollection("restaurant")

// Insert sample structure
db.restaurant.insertOne({
    id: 1,
    name: "Truffles",
    cuisine: "American",
    address: {
        building: "123",
        street: "St Marks Road",
        area: "CBD",
        pincode: "560001"
    },
    nearby_landmarks: ["Museum", "Metro Station"],
    online_delivery: "yes",
    famous_for: "Burgers"
})
```

---

## 🚗 Program 6: Car & Airline Databases (SQL)

### Part A: Car Ownership

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

### Part B: Airline Database

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
