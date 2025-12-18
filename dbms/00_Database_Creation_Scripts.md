# 🛠️ Database Creation Scripts

here are the sql `create table` statements and mongodb setup commands to initialize the databases for all the lab programs.

---

## 📚 Program 1: Library Database

**order of creation:** `publisher` -> `library_branch` -> `book` -> `book_authors` -> `book_copies` -> `book_lending`.

```sql
create table publisher (
    name varchar(100) primary key,
    address varchar(255),
    phone varchar(20)
);

create table library_branch (
    branch_id int primary key,
    branch_name varchar(100),
    address varchar(255)
);

create table book (
    book_id int primary key,
    title varchar(255),
    publisher_name varchar(100),
    pub_year int,
    foreign key (publisher_name) references publisher(name) on delete cascade
);

create table book_authors (
    book_id int,
    author_name varchar(100),
    primary key (book_id, author_name),
    foreign key (book_id) references book(book_id) on delete cascade
);

create table book_copies (
    book_id int,
    branch_id int,
    no_of_copies int,
    primary key (book_id, branch_id),
    foreign key (book_id) references book(book_id) on delete cascade,
    foreign key (branch_id) references library_branch(branch_id) on delete cascade
);

create table book_lending (
    book_id int,
    branch_id int,
    card_no int,
    date_out date,
    due_date date,
    primary key (book_id, branch_id, card_no),
    foreign key (book_id) references book(book_id) on delete cascade,
    foreign key (branch_id) references library_branch(branch_id) on delete cascade
);
```

---

## 🎓 Program 2: College Database

**order of creation:** `student` -> `semsec` -> `class` -> `subject` -> `iamarks`.

```sql
create table student (
    usn varchar(20) primary key,
    sname varchar(100),
    address varchar(255),
    phone varchar(20),
    gender char(1)
);

create table semsec (
    ssid varchar(20) primary key,
    sem int,
    sec char(1)
);

create table class (
    usn varchar(20),
    ssid varchar(20),
    primary key (usn, ssid),
    foreign key (usn) references student(usn) on delete cascade,
    foreign key (ssid) references semsec(ssid) on delete cascade
);

create table subject (
    subcode varchar(20) primary key,
    title varchar(100),
    sem int,
    credits int
);

create table iamarks (
    usn varchar(20),
    subcode varchar(20),
    ssid varchar(20),
    test1 int,
    test2 int,
    test3 int,
    finalia decimal(5, 2),
    primary key (usn, subcode, ssid),
    foreign key (usn) references student(usn) on delete cascade,
    foreign key (subcode) references subject(subcode) on delete cascade,
    foreign key (ssid) references semsec(ssid) on delete cascade
);
```

---

## 🏢 Program 3: Company Database

**note:** this schema has a circular dependency (`employee` needs `department`, `department` needs `employee` manager). we create tables first, then add the foreign key constraint for the manager.

```sql
-- 1. create department without manager fk first
create table department (
    dno int primary key,
    dname varchar(100),
    mgrssn char(9), 
    mgrstartdate date
);

-- 2. create employee
create table employee (
    ssn char(9) primary key,
    name varchar(100),
    address varchar(255),
    sex char(1),
    salary decimal(10, 2),
    superssn char(9),
    dno int,
    foreign key (superssn) references employee(ssn),
    foreign key (dno) references department(dno)
);

-- 3. add manager fk to department
alter table department
add constraint fk_dept_mgr
foreign key (mgrssn) references employee(ssn);

create table dlocation (
    dno int,
    dloc varchar(100),
    primary key (dno, dloc),
    foreign key (dno) references department(dno) on delete cascade
);

create table project (
    pno int primary key,
    pname varchar(100),
    plocation varchar(100),
    dno int,
    foreign key (dno) references department(dno)
);

create table works_on (
    ssn char(9),
    pno int,
    hours decimal(5, 1),
    primary key (ssn, pno),
    foreign key (ssn) references employee(ssn) on delete cascade,
    foreign key (pno) references project(pno) on delete cascade
);
```

---

## 🍃 Program 4: Employee Database (MongoDB)

since mongodb is schema-less, you don't strictly *need* to create a collection, but here is how you initialize it with a sample document to enforce structure if desired.

```javascript
// switch to database
use employee_db

// create collection explicitly (optional)
db.createcollection("employee")

// insert a sample document to establish structure
db.employee.insertone({
    eid: 1,
    ename: "rahul",
    dept: "it",
    design: "developer",
    salary: 50000,
    yoj: 2020,
    address: {
        dno: "101",
        street: "mg road",
        locality: "indiranagar",
        city: "bangalore"
    }
})
```

---

## 🍝 Program 5: Restaurant Database (MongoDB)

```javascript
// switch to database
use restaurant_db

// create collection
db.createcollection("restaurant")

// insert sample structure
db.restaurant.insertone({
    id: 1,
    name: "truffles",
    cuisine: "american",
    address: {
        building: "123",
        street: "st marks road",
        area: "cbd",
        pincode: "560001"
    },
    nearby_landmarks: ["museum", "metro station"],
    online_delivery: "yes",
    famous_for: "burgers"
})
```

---

## 🚗 Program 6: Car & Airline Databases (SQL)

### Part A: Car Ownership

```sql
create table person (
    driver_id varchar(20) primary key,
    name varchar(100),
    address varchar(255)
);

create table car (
    regno varchar(20) primary key,
    model varchar(50),
    year int
);

create table owns (
    driver_id varchar(20),
    regno varchar(20),
    primary key (driver_id, regno),
    foreign key (driver_id) references person(driver_id) on delete cascade,
    foreign key (regno) references car(regno) on delete cascade
);
```

### Part B: Airline Database

```sql
create table aircraft (
    aircraft_id int primary key,
    aircraft_name varchar(100),
    cruising_range int
);

create table employee_airline (
    emp_id int primary key,
    ename varchar(100),
    salary decimal(10, 2)
);

create table certified (
    emp_id int,
    aircraft_id int,
    primary key (emp_id, aircraft_id),
    foreign key (emp_id) references employee_airline(emp_id) on delete cascade,
    foreign key (aircraft_id) references aircraft(aircraft_id) on delete cascade
);
```
