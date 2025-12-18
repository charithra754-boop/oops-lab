# 🏢 Program 3: Company Database (SQL)

**the vibe:** corporate life. salaries, managers, and projects.

## 📋 Schema
- **employee** (ssn, name, address, sex, salary, superssn, dno)
- **department** (dno, dname, mgrssn, mgrstartdate)
- **dlocation** (dno, dloc)
- **project** (pno, pname, plocation, dno)
- **works_on** (ssn, pno, hours)

---

## 🔍 Queries

### 1. List project numbers for projects involving employee ‘Scott’ (worker or manager).

**option 1: `union` (combining two distinct sets)**
```sql
(select pno from works_on w
 join employee e on w.ssn = e.ssn
 where e.name = 'scott')
union
(select pno from project p
 join department d on p.dno = d.dno
 join employee e on d.mgrssn = e.ssn
 where e.name = 'scott');
```

---

### 2. Show the resulting salaries if every employee working on the ‘IoT’ project is given a 10 percent raise.

**the goal:** hypothetical projection (select), not an actual update.

**the query:**
```sql
select e.name, e.salary as old_salary, e.salary * 1.10 as new_salary
from employee e
join works_on w on e.ssn = w.ssn
join project p on w.pno = p.pno
where p.pname = 'iot';
```

---

### 3. Find sum, max, min, and average salary of 'Accounts' department.

**the command:**
```sql
select 
    sum(salary) as total_cost, 
    max(salary) as highest_paid, 
    min(salary) as lowest_paid, 
    avg(salary) as average_pay
from employee e
join department d on e.dno = d.dno
where d.dname = 'accounts';
```

---

### 4. Retrieve the name of each employee who works on all the projects controlled by the department number (use NOT EXISTS).

**the goal:** "relational division". this finds employees where there is *no* project in the target set that they *don't* work on.

**the query (the brain twister):**
```sql
select e.name 
from employee e
where not exists (
    select p.pno 
    from project p 
    where p.dno = 5 -- assuming we are checking department 5
    and not exists (
        select w.pno 
        from works_on w 
        where w.ssn = e.ssn and w.pno = p.pno
    )
);
```

> **🤯 logic breakdown:**
> 1. find all projects for dept 5.
> 2. for a specific employee `e`, find if there are any of those projects they do *not* work on.
> 3. if that list of "missed projects" is empty (`not exists`), then the employee works on all of them. double negatives for the win!

---

### 5. For each department with > 5 employees, retrieve dept number and count of employees making > Rs. 6,00,000.

**the query:**
```sql
select dno, count(*) as high_earners_count
from employee
where salary > 600000 
and dno in (
    select dno 
    from employee 
    group by dno 
    having count(*) > 5
)
group by dno;
```
