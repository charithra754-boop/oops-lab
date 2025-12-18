# 🍃 Program 4: Employee Database (MongoDB) Setup

## 🛠️ Collection & Data Creation

copy and paste this into your mongodb shell or compass.

```javascript
use employee_db

// clear existing data (optional, for fresh start)
db.employee.drop()

// insert 10 documents
db.employee.insertmany([
  { 
    eid: 1, 
    ename: "rahul", 
    dept: "it", 
    design: "developer", 
    salary: 60000, 
    yoj: 2020, 
    address: { dno: "101", street: "mg road", locality: "indiranagar", city: "bangalore" } 
  },
  { 
    eid: 2, 
    ename: "smith", 
    dept: "hr", 
    design: "manager", 
    salary: 80000, 
    yoj: 2018, 
    address: { dno: "202", street: "brigade rd", locality: "cbd", city: "bangalore" } 
  },
  { 
    eid: 3, 
    ename: "allen", 
    dept: "sales", 
    design: "executive", 
    salary: 30000, 
    yoj: 2021, 
    address: { dno: "303", street: "church st", locality: "cbd", city: "bangalore" } 
  },
  { 
    eid: 4, 
    ename: "ward", 
    dept: "it", 
    design: "developer", 
    salary: 55000, 
    yoj: 2019, 
    address: { dno: "404", street: "koramangala", locality: "4th block", city: "bangalore" } 
  },
  { 
    eid: 5, 
    ename: "jones", 
    dept: "hr", 
    design: "manager", 
    salary: 76000, 
    yoj: 2017, 
    address: { dno: "505", street: "jayanagar", locality: "3rd block", city: "bangalore" } 
  },
  { 
    eid: 6, 
    ename: "martin", 
    dept: "it", 
    design: "tester", 
    salary: 40000, 
    yoj: 2022, 
    address: { dno: "606", street: "whitefield", locality: "epip", city: "bangalore" } 
  },
  { 
    eid: 7, 
    ename: "blake", 
    dept: "sales", 
    design: "manager", 
    salary: 90000, 
    yoj: 2015, 
    address: { dno: "707", street: "malleshwaram", locality: "8th cross", city: "bangalore" } 
  },
  { 
    eid: 8, 
    ename: "clark", 
    dept: "it", 
    design: "developer", 
    salary: 70000, 
    yoj: 2018, 
    address: { dno: "808", street: "indiranagar", locality: "100ft road", city: "bangalore" } 
  },
  { 
    eid: 9, 
    ename: "scott", 
    dept: "finance", 
    design: "analyst", 
    salary: 65000, 
    yoj: 2019, 
    address: { dno: "909", street: "residency rd", locality: "richmond", city: "bangalore" } 
  },
  { 
    eid: 10, 
    ename: "turner", 
    dept: "it", 
    design: "developer", 
    salary: 52000, 
    yoj: 2021, 
    address: { dno: "1010", street: "hsr layout", locality: "sector 1", city: "bangalore" } 
  }
]);
```
