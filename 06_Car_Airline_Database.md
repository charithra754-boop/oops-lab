# 🚗 Program 6: Car & Airline Database (SQL)

## Part A: Car Ownership Database

### 📋 Schema
- **PERSON** (driver_id, name, address)
- **CAR** (Regno, model, year)
- **OWNS** (driver_id, Regno)

### 🔍 Query
**1. Display the number of cars owned by each driver.**

**Option 1: Using `COUNT`**
```sql
SELECT P.name, COUNT(O.Regno) as Car_Count
FROM PERSON P
JOIN OWNS O ON P.driver_id = O.driver_id
GROUP BY P.driver_id, P.name;
```

**Option 2: Left Join (To show drivers with 0 cars too)**
```sql
SELECT P.name, COUNT(O.Regno) as Car_Count
FROM PERSON P
LEFT JOIN OWNS O ON P.driver_id = O.driver_id
GROUP BY P.driver_id, P.name;
```

---

## Part B: Airline Database

### 📋 Schema
- **AIRCRAFT** (Aircraft_ID, Aircraft_name, Cruising_range)
- **CERTIFIED** (Emp_ID, Aircraft_ID)
- **EMPLOYEE** (Emp_ID, Ename, Salary)

### 🔍 Queries

**1. Find the employee ID's of employees who make the highest salary.**

**Option 1: Subquery**
```sql
SELECT Emp_ID 
FROM EMPLOYEE 
WHERE Salary = (SELECT MAX(Salary) FROM EMPLOYEE);
```

**Option 2: Limit/Top (DB Dependent)**
```sql
SELECT Emp_ID 
FROM EMPLOYEE 
ORDER BY Salary DESC 
LIMIT 1; 
-- Note: This only returns ONE person. If there's a tie, the subquery version is safer!
```

**2. Find the employees who are not certified to operate any aircraft.**

**Option 1: `NOT IN`**
```sql
SELECT E.Ename 
FROM EMPLOYEE E
WHERE E.Emp_ID NOT IN (SELECT DISTINCT Emp_ID FROM CERTIFIED);
```

**Option 2: `LEFT JOIN` ... `NULL`**
```sql
SELECT E.Ename 
FROM EMPLOYEE E
LEFT JOIN CERTIFIED C ON E.Emp_ID = C.Emp_ID
WHERE C.Aircraft_ID IS NULL;
```

> **🏁 Finish Line:** The `LEFT JOIN ... WHERE NULL` pattern is a high-performance alternative to `NOT IN`, especially in older SQL engines or with massive datasets. It basically asks: "Try to match employees to certifications. Now, show me the rows where the match failed."
