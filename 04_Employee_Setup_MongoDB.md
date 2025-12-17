# 🍃 Program 4: Employee Database (MongoDB) Setup

## 🛠️ Collection & Data Creation

Copy and paste this into your MongoDB shell or Compass.

```javascript
use employee_db

// Clear existing data (optional, for fresh start)
db.employee.drop()

// Insert 10 Documents
db.employee.insertMany([
  { 
    eid: 1, 
    ename: "Rahul", 
    dept: "IT", 
    design: "developer", 
    salary: 60000, 
    yoj: 2020, 
    address: { dno: "101", street: "MG Road", locality: "Indiranagar", city: "Bangalore" } 
  },
  { 
    eid: 2, 
    ename: "Smith", 
    dept: "HR", 
    design: "manager", 
    salary: 80000, 
    yoj: 2018, 
    address: { dno: "202", street: "Brigade Rd", locality: "CBD", city: "Bangalore" } 
  },
  { 
    eid: 3, 
    ename: "Allen", 
    dept: "Sales", 
    design: "executive", 
    salary: 30000, 
    yoj: 2021, 
    address: { dno: "303", street: "Church St", locality: "CBD", city: "Bangalore" } 
  },
  { 
    eid: 4, 
    ename: "Ward", 
    dept: "IT", 
    design: "developer", 
    salary: 55000, 
    yoj: 2019, 
    address: { dno: "404", street: "Koramangala", locality: "4th Block", city: "Bangalore" } 
  },
  { 
    eid: 5, 
    ename: "Jones", 
    dept: "HR", 
    design: "manager", 
    salary: 76000, 
    yoj: 2017, 
    address: { dno: "505", street: "Jayanagar", locality: "3rd Block", city: "Bangalore" } 
  },
  { 
    eid: 6, 
    ename: "Martin", 
    dept: "IT", 
    design: "tester", 
    salary: 40000, 
    yoj: 2022, 
    address: { dno: "606", street: "Whitefield", locality: "EPIP", city: "Bangalore" } 
  },
  { 
    eid: 7, 
    ename: "Blake", 
    dept: "Sales", 
    design: "manager", 
    salary: 90000, 
    yoj: 2015, 
    address: { dno: "707", street: "Malleshwaram", locality: "8th Cross", city: "Bangalore" } 
  },
  { 
    eid: 8, 
    ename: "Clark", 
    dept: "IT", 
    design: "developer", 
    salary: 70000, 
    yoj: 2018, 
    address: { dno: "808", street: "Indiranagar", locality: "100ft Road", city: "Bangalore" } 
  },
  { 
    eid: 9, 
    ename: "Scott", 
    dept: "Finance", 
    design: "analyst", 
    salary: 65000, 
    yoj: 2019, 
    address: { dno: "909", street: "Residency Rd", locality: "Richmond", city: "Bangalore" } 
  },
  { 
    eid: 10, 
    ename: "Turner", 
    dept: "IT", 
    design: "developer", 
    salary: 52000, 
    yoj: 2021, 
    address: { dno: "1010", street: "HSR Layout", locality: "Sector 1", city: "Bangalore" } 
  }
]);
```
