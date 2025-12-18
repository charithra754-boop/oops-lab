# 🍃 Program 4: Employee Database (MongoDB)

**the vibe:** nosql. flexible schemas. json-like documents.

## 📋 Schema (Fields)
- `eid`, `ename`, `dept`, `design`
- `salary`, `yoj`
- `address`: {`dno`, `street`, `locality`, `city`}

---

## 🔍 Commands

### A. Create 10 documents.
**command:**
```javascript
db.employee.insertmany([
  { eid: 1, ename: "rahul", dept: "it", design: "developer", salary: 60000, yoj: 2020, address: { dno: "101", street: "mg road", locality: "indiranagar", city: "bangalore" } },
  { eid: 2, ename: "smith", dept: "hr", design: "manager", salary: 80000, yoj: 2018, address: { dno: "202", street: "brigade rd", locality: "cbd", city: "bangalore" } },
  // ... imagine 8 more entries here ...
  { eid: 3, ename: "priya", dept: "it", design: "developer", salary: 55000, yoj: 2021, address: { dno: "303", street: "koramangala", locality: "4th block", city: "bangalore" } }
]);
```

### B. Queries

**1. display all the employees with a salary in the range (50000, 75000).**
```javascript
db.employee.find({ salary: { $gt: 50000, $lt: 75000 } }).pretty()
```

**2. display all the employees with the designation “developer”.**
```javascript
db.employee.find({ design: "developer" }).pretty()
```

**3. add the field `age` to the employee “rahul”.**
```javascript
db.employee.updateone(
  { ename: "rahul" },
  { $set: { age: 30 } }
)
```

**4. remove `yoj` from “rahul”.**
```javascript
db.employee.updateone(
  { ename: "rahul" },
  { $unset: { yoj: "" } }
)
```

**5. remove `p3` from “rahul”.**
*assuming `p3` is a specific field (maybe project 3?):*
```javascript
db.employee.updateone({ ename: "rahul" }, { $unset: { p3: "" } })
```
*if `p3` was a value in an array (e.g., projects list):*
```javascript
db.employee.updateone({ ename: "rahul" }, { $pull: { projects: "p3" } })
```

**6. add a new embedded object “contacts” with “email” and “phone” as array objects to “rahul”.**
```javascript
db.employee.updateone(
  { ename: "rahul" },
  { $set: { contacts: { email: "rahul@gmail.com", phone: [] } } }
)
```

**7. add two phone numbers to “rahul”.**
```javascript
db.employee.updateone(
  { ename: "rahul" },
  { $push: { "contacts.phone": { $each: ["9876543210", "1234567890"] } } }
)
```

> **🔧 mongo fact:** `$each` is a modifier used with `$push` to append multiple values at once. without it, you'd insert the entire array `["num1", "num2"]` as a single element nested inside the phone array!
