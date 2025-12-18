# 🎓 Program 2: College Database (SQL)

**the vibe:** students, marks, and the dreaded "final ia" calculation.

## 📋 Schema
- **student** (usn, sname, address, phone, gender)
- **semsec** (ssid, sem, sec)
- **class** (usn, ssid)
- **subject** (subcode, title, sem, credits)
- **iamarks** (usn, subcode, ssid, test1, test2, test3, finalia)

---

## 🔍 Queries

### 1. List all the student details studying in the fourth semester ‘C’ section.

**option 1: simple join**
```sql
select s.* 
from student s
join class c on s.usn = c.usn
join semsec ss on c.ssid = ss.ssid
where ss.sem = 4 and ss.sec = 'c';
```

**option 2: subquery (the "inside-out" approach)**
```sql
select * from student 
where usn in (
    select usn from class 
    where ssid in (
        select ssid from semsec where sem = 4 and sec = 'c'
    )
);
```

---

### 2. Compute the total number of male and female students in each semester and in each section.

**the goal:** multi-level grouping.

**the query:**
```sql
select ss.sem, ss.sec, s.gender, count(s.usn) as student_count
from student s
join class c on s.usn = c.usn
join semsec ss on c.ssid = ss.ssid
group by ss.sem, ss.sec, s.gender
order by ss.sem, ss.sec;
```

> **💡 optimization tip:** if you have millions of students, ensure you have indexes on `ssid` and `usn` to make these joins snappy.

---

### 3. Create a view of Test1 marks of student USN ‘1BI15CS101’ in all subjects.

**the command:**
```sql
create view student_test1_marks as
select subcode, test1 
from iamarks 
where usn = '1bi15cs101';
```

---

### 4. Calculate the Final IA (average of best two test marks) and update the corresponding table for all students.

**the goal:** mathematical logic inside an update.
*logic:* (test1 + test2 + test3 - lowest_score) / 2

**option 1: using `least` (mysql/postgresql)**
```sql
update iamarks 
set finalia = (test1 + test2 + test3 - least(test1, test2, test3)) / 2;
```

**option 2: the `case` statement (universal sql)**
*use this if your db doesn't support `least`.*
```sql
update iamarks 
set finalia = case
    when test1 <= test2 and test1 <= test3 then (test2 + test3) / 2
    when test2 <= test1 and test2 <= test3 then (test1 + test3) / 2
    else (test1 + test2) / 2
end;
```

> **🔥 hot take:** this is the most useful query in this entire pdf for actual college students. everyone wants to know their best-of-two average!

---

### 5. List the subjects based on ascending order of their credits.

**the command:**
```sql
select title, credits 
from subject 
order by credits asc;
```
