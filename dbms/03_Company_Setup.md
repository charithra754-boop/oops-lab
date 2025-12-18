# 🏢 Program 3: Company Database Setup

## 🔄 Order of Creation (Special Handling Required)
due to a circular dependency between `employee` and `department` (an employee works in a department, but a department is managed by an employee), we must follow this specific sequence:

1. `department` (create initially *without* the `mgrssn` foreign key)
2. `employee` (create with fk to `department`)
3. **alter** `department` (add the fk constraint `mgrssn` referencing `employee`)
4. `dlocation` (depends on `department`)
5. `project` (depends on `department`)
6. `works_on` (depends on `employee`, `project`)

## 🛠️ Table Creation

```sql
-- 1. department (initially without mgrssn constraint)
create table department (
    dno int primary key,
    dname varchar(100),
    mgrssn char(9), 
    mgrstartdate date
);

-- 2. employee
create table employee (
    ssn char(9) primary key,
    name varchar(100),
    address varchar(255),
    sex char(1),
    salary decimal(10, 2),
    superssn char(9),
    dno int,
    foreign key (dno) references department(dno)
);

-- 3. add circular fk
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

## 📥 Data Insertion

*note: due to circular dependencies, we insert departments first with null managers, then employees, then update departments.*

```sql
-- 1. create departments (mgrssn is null initially)
insert into department (dno, dname, mgrstartdate) values (1, 'headquarters', '2019-01-01');
insert into department (dno, dname, mgrstartdate) values (4, 'administration', '2019-01-01');
insert into department (dno, dname, mgrstartdate) values (5, 'accounts', '2018-01-01');

-- 2. create employees (referring to dept dno)
-- scott (ssn: 101) - in accounts
insert into employee values ('101', 'scott', 'bangalore', 'm', 700000, null, 5);
-- smith (ssn: 102) - in admin
insert into employee values ('102', 'smith', 'mysore', 'm', 450000, '101', 4);
-- john (ssn: 103) - in accounts
insert into employee values ('103', 'john', 'bangalore', 'm', 250000, '101', 5);

-- 3. update department managers
update department set mgrssn = '101' where dno = 5; -- scott manages accounts
update department set mgrssn = '102' where dno = 4;

-- 4. locations
insert into dlocation values (1, 'bangalore');
insert into dlocation values (4, 'mysore');
insert into dlocation values (5, 'bangalore');

-- 5. projects
insert into project values (10, 'iot', 'bangalore', 5);
insert into project values (20, 'bigdata', 'mysore', 4);
insert into project values (30, 'cloud', 'bangalore', 5);

-- 6. works on
insert into works_on values ('101', 10, 10); -- scott works on iot
insert into works_on values ('101', 30, 5);  -- scott works on cloud
insert into works_on values ('102', 20, 20); -- smith works on bigdata
insert into works_on values ('103', 10, 40); -- john works on iot
```
