# 🏢 Program 3: Company Database (SQL)

**The Vibe:** Corporate life. Salaries, managers, and projects.

## 📋 Schema
- **EMPLOYEE** (SSN, Name, Address, Sex, Salary, SuperSSN, DNo)
- **DEPARTMENT** (DNo, DName, MgrSSN, MgrStartDate)
- **DLOCATION** (DNo, DLoc)
- **PROJECT** (PNo, PName, PLocation, DNo)
- **WORKS_ON** (SSN, PNo, Hours)

---

## 🔍 Queries

### 1. List project numbers for projects involving employee ‘Scott’ (worker or manager).

**Option 1: `UNION` (Combining two distinct sets)**
```sql
(SELECT PNo FROM WORKS_ON W
 JOIN EMPLOYEE E ON W.SSN = E.SSN
 WHERE E.Name = 'Scott')
UNION
(SELECT PNo FROM PROJECT P
 JOIN DEPARTMENT D ON P.DNo = D.DNo
 JOIN EMPLOYEE E ON D.MgrSSN = E.SSN
 WHERE E.Name = 'Scott');
```

---

### 2. Show the resulting salaries if every employee working on the ‘IoT’ project is given a 10 percent raise.

**The Goal:** Hypothetical projection (Select), not an actual Update.

**The Query:**
```sql
SELECT E.Name, E.Salary as Old_Salary, E.Salary * 1.10 as New_Salary
FROM EMPLOYEE E
JOIN WORKS_ON W ON E.SSN = W.SSN
JOIN PROJECT P ON W.PNo = P.PNo
WHERE P.PName = 'IoT';
```

---

### 3. Find sum, max, min, and average salary of 'Accounts' department.

**The Command:**
```sql
SELECT 
    SUM(Salary) as Total_Cost, 
    MAX(Salary) as Highest_Paid, 
    MIN(Salary) as Lowest_Paid, 
    AVG(Salary) as Average_Pay
FROM EMPLOYEE E
JOIN DEPARTMENT D ON E.DNo = D.DNo
WHERE D.DName = 'Accounts';
```

---

### 4. Retrieve the name of each employee who works on all the projects controlled by the department number (use NOT EXISTS).

**The Goal:** "Relational Division". This finds employees where there is *no* project in the target set that they *don't* work on.

**The Query (The Brain Twister):**
```sql
SELECT E.Name 
FROM EMPLOYEE E
WHERE NOT EXISTS (
    SELECT P.PNo 
    FROM PROJECT P 
    WHERE P.DNo = 5 -- Assuming we are checking Department 5
    AND NOT EXISTS (
        SELECT W.PNo 
        FROM WORKS_ON W 
        WHERE W.SSN = E.SSN AND W.PNo = P.PNo
    )
);
```

> **🤯 Logic Breakdown:**
> 1. Find all projects for Dept 5.
> 2. For a specific employee `E`, find if there are any of those projects they do *NOT* work on.
> 3. If that list of "missed projects" is empty (`NOT EXISTS`), then the employee works on ALL of them. Double negatives for the win!

---

### 5. For each department with > 5 employees, retrieve dept number and count of employees making > Rs. 6,00,000.

**The Query:**
```sql
SELECT DNo, COUNT(*) as High_Earners_Count
FROM EMPLOYEE
WHERE Salary > 600000 
AND DNo IN (
    SELECT DNo 
    FROM EMPLOYEE 
    GROUP BY DNo 
    HAVING COUNT(*) > 5
)
GROUP BY DNo;
```
