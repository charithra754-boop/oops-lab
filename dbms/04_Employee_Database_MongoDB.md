# 🍃 Program 4: Employee Database (MongoDB)

**The Vibe:** NoSQL. Flexible schemas. JSON-like documents.

## 📋 Schema (Fields)
- `eid`, `ename`, `dept`, `design`
- `salary`, `yoj`
- `address`: {`dno`, `street`, `locality`, `city`}

---

## 🔍 Commands

### A. Create 10 documents.
**Command:**
```javascript
db.employee.insertMany([
  { eid: 1, ename: "Rahul", dept: "IT", design: "developer", salary: 60000, yoj: 2020, address: { dno: "101", street: "MG Road", locality: "Indiranagar", city: "Bangalore" } },
  { eid: 2, ename: "Smith", dept: "HR", design: "manager", salary: 80000, yoj: 2018, address: { dno: "202", street: "Brigade Rd", locality: "CBD", city: "Bangalore" } },
  // ... imagine 8 more entries here ...
  { eid: 3, ename: "Priya", dept: "IT", design: "developer", salary: 55000, yoj: 2021, address: { dno: "303", street: "Koramangala", locality: "4th Block", city: "Bangalore" } }
]);
```

### B. Queries

**1. Display all the employees with a salary in the range (50000, 75000).**
```javascript
db.employee.find({ salary: { $gt: 50000, $lt: 75000 } }).pretty()
```

**2. Display all the employees with the designation “developer”.**
```javascript
db.employee.find({ design: "developer" }).pretty()
```

**3. Add the field `age` to the employee “Rahul”.**
```javascript
db.employee.updateOne(
  { ename: "Rahul" },
  { $set: { age: 30 } }
)
```

**4. Remove `YOJ` from “Rahul”.**
```javascript
db.employee.updateOne(
  { ename: "Rahul" },
  { $unset: { yoj: "" } }
)
```

**5. Remove `p3` from “Rahul”.**
*Assuming `p3` is a specific field (maybe project 3?):*
```javascript
db.employee.updateOne({ ename: "Rahul" }, { $unset: { p3: "" } })
```
*If `p3` was a value in an array (e.g., projects list):*
```javascript
db.employee.updateOne({ ename: "Rahul" }, { $pull: { projects: "p3" } })
```

**6. Add a new embedded object “contacts” with “email” and “phone” as array objects to “Rahul”.**
```javascript
db.employee.updateOne(
  { ename: "Rahul" },
  { $set: { contacts: { email: "rahul@gmail.com", phone: [] } } }
)
```

**7. Add two phone numbers to “Rahul”.**
```javascript
db.employee.updateOne(
  { ename: "Rahul" },
  { $push: { "contacts.phone": { $each: ["9876543210", "1234567890"] } } }
)
```

> **🔧 Mongo Fact:** `$each` is a modifier used with `$push` to append multiple values at once. Without it, you'd insert the entire array `["num1", "num2"]` as a single element nested inside the phone array!
