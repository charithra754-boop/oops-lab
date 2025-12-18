# 🚗 Program 6: Car & Airline Database (SQL)

## Part A: Car Ownership Database

### 📋 Schema
- **person** (driver_id, name, address)
- **car** (regno, model, year)
- **owns** (driver_id, regno)

### 🔍 Query
**1. display the number of cars owned by each driver.**

**option 1: using `count`**
```sql
select p.name, count(o.regno) as car_count
from person p
join owns o on p.driver_id = o.driver_id
group by p.driver_id, p.name;
```

**option 2: left join (to show drivers with 0 cars too)**
```sql
select p.name, count(o.regno) as car_count
from person p
left join owns o on p.driver_id = o.driver_id
group by p.driver_id, p.name;
```

---

## Part B: Airline Database

### 📋 Schema
- **aircraft** (aircraft_id, aircraft_name, cruising_range)
- **certified** (emp_id, aircraft_id)
- **employee** (emp_id, ename, salary)

### 🔍 Queries

**1. find the employee id's of employees who make the highest salary.**

**option 1: subquery**
```sql
select emp_id 
from employee 
where salary = (select max(salary) from employee);
```

**option 2: limit/top (db dependent)**
```sql
select emp_id 
from employee 
order by salary desc 
limit 1; 
-- note: this only returns one person. if there's a tie, the subquery version is safer!
```

**2. find the employees who are not certified to operate any aircraft.**

**option 1: `not in`**
```sql
select e.ename 
from employee e
where e.emp_id not in (select distinct emp_id from certified);
```

**option 2: `left join` ... `null`**
```sql
select e.ename 
from employee e
left join certified c on e.emp_id = c.emp_id
where c.aircraft_id is null;
```

> **🏁 finish line:** the `left join ... where null` pattern is a high-performance alternative to `not in`, especially in older sql engines or with massive datasets. it basically asks: "try to match employees to certifications. now, show me the rows where the match failed."
