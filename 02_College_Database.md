# 🎓 Program 2: College Database (SQL)

**The Vibe:** Students, marks, and the dreaded "Final IA" calculation.

## 📋 Schema
- **STUDENT** (USN, SName, Address, Phone, Gender)
- **SEMSEC** (SSID, Sem, Sec)
- **CLASS** (USN, SSID)
- **SUBJECT** (Subcode, Title, Sem, Credits)
- **IAMARKS** (USN, Subcode, SSID, Test1, Test2, Test3, FinalIA)

---

## 🔍 Queries

### 1. List all the student details studying in the fourth semester ‘C’ section.

**Option 1: Simple Join**
```sql
SELECT S.* 
FROM STUDENT S
JOIN CLASS C ON S.USN = C.USN
JOIN SEMSEC SS ON C.SSID = SS.SSID
WHERE SS.Sem = 4 AND SS.Sec = 'C';
```

**Option 2: Subquery (The "Inside-Out" approach)**
```sql
SELECT * FROM STUDENT 
WHERE USN IN (
    SELECT USN FROM CLASS 
    WHERE SSID IN (
        SELECT SSID FROM SEMSEC WHERE Sem = 4 AND Sec = 'C'
    )
);
```

---

### 2. Compute the total number of male and female students in each semester and in each section.

**The Goal:** Multi-level Grouping.

**The Query:**
```sql
SELECT SS.Sem, SS.Sec, S.Gender, COUNT(S.USN) as Student_Count
FROM STUDENT S
JOIN CLASS C ON S.USN = C.USN
JOIN SEMSEC SS ON C.SSID = SS.SSID
GROUP BY SS.Sem, SS.Sec, S.Gender
ORDER BY SS.Sem, SS.Sec;
```

> **💡 Optimization Tip:** If you have millions of students, ensure you have indexes on `SSID` and `USN` to make these joins snappy.

---

### 3. Create a view of Test1 marks of student USN ‘1BI15CS101’ in all subjects.

**The Command:**
```sql
CREATE VIEW Student_Test1_Marks AS
SELECT Subcode, Test1 
FROM IAMARKS 
WHERE USN = '1BI15CS101';
```

---

### 4. Calculate the Final IA (average of best two test marks) and update the corresponding table for all students.

**The Goal:** Mathematical logic inside an update.
*Logic:* (Test1 + Test2 + Test3 - Lowest_Score) / 2

**Option 1: Using `LEAST` (MySQL/PostgreSQL)**
```sql
UPDATE IAMARKS 
SET FinalIA = (Test1 + Test2 + Test3 - LEAST(Test1, Test2, Test3)) / 2;
```

**Option 2: The `CASE` Statement (Universal SQL)**
*Use this if your DB doesn't support `LEAST`.*
```sql
UPDATE IAMARKS 
SET FinalIA = CASE
    WHEN Test1 <= Test2 AND Test1 <= Test3 THEN (Test2 + Test3) / 2
    WHEN Test2 <= Test1 AND Test2 <= Test3 THEN (Test1 + Test3) / 2
    ELSE (Test1 + Test2) / 2
END;
```

> **🔥 Hot Take:** This is the most useful query in this entire PDF for actual college students. Everyone wants to know their best-of-two average!

---

### 5. List the subjects based on ascending order of their credits.

**The Command:**
```sql
SELECT Title, Credits 
FROM SUBJECT 
ORDER BY Credits ASC;
```
