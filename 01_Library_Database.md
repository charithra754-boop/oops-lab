# 📚 Program 1: Library Database (SQL)

**The Vibe:** We are managing a library. Books, authors, borrowers. It's classic data modeling.

## 📋 Schema
- **BOOK** (Book_id, Title, Publisher_Name, Pub_Year)
- **BOOK_AUTHORS** (Book_id, Author_Name)
- **PUBLISHER** (Name, Address, Phone)
- **BOOK_COPIES** (Book_id, Branch_id, No-of_Copies)
- **BOOK_LENDING** (Book_id, Branch_id, Card_No, Date_Out, Due_Date)
- **LIBRARY_BRANCH** (Branch_id, Branch_Name, Address)

---

## 🔍 Queries

### 1. Retrieve details of all books in the library – id, title, name of publisher, authors, number of copies in each branch, etc.

**The Goal:** A massive join to see everything about a book.

**Option 1: The "I want it all" Join (Standard)**
```sql
SELECT 
    B.Book_id, B.Title, B.Publisher_Name, A.Author_Name, 
    C.No_of_Copies, L.Branch_Name
FROM 
    BOOK B
    JOIN BOOK_AUTHORS A ON B.Book_id = A.Book_id
    JOIN BOOK_COPIES C ON B.Book_id = C.Book_id
    JOIN LIBRARY_BRANCH L ON C.Branch_id = L.Branch_id;
```

**Option 2: The "Comma-Separated" Style (Old School)**
```sql
SELECT 
    B.Book_id, B.Title, B.Publisher_Name, A.Author_Name, 
    C.No_of_Copies, L.Branch_Name
FROM 
    BOOK B, BOOK_AUTHORS A, BOOK_COPIES C, LIBRARY_BRANCH L
WHERE 
    B.Book_id = A.Book_id 
    AND B.Book_id = C.Book_id 
    AND C.Branch_id = L.Branch_id;
```

> **🎓 Fun Fact:** The `JOIN` syntax (ANSI-92) is generally preferred over the comma-separated syntax because it separates the *relationship logic* from the *filtering logic*. It makes your code less prone to accidental cross-joins (where you get millions of rows because you forgot a `WHERE` clause).

---

### 2. Get the particulars of borrowers who have borrowed more than 3 books, but from Jan 2017 to Jun 2017.

**The Goal:** Filtering by date range and aggregation.

**Option 1: `HAVING` Clause (The Groupie)**
```sql
SELECT Card_No
FROM BOOK_LENDING
WHERE Date_Out BETWEEN '2017-01-01' AND '2017-06-30'
GROUP BY Card_No
HAVING COUNT(*) > 3;
```

**Option 2: With a Join to get names (The Complete Picture)**
*Assuming there is a `BORROWER` table implied but not explicitly listed in schema. If not, we just return Card_No.*
```sql
SELECT B.Name, BL.Card_No
FROM BORROWER B
JOIN BOOK_LENDING BL ON B.Card_No = BL.Card_No
WHERE BL.Date_Out >= '2017-01-01' AND BL.Date_Out <= '2017-06-30'
GROUP BY BL.Card_No, B.Name
HAVING COUNT(BL.Book_id) > 3;
```

> **🤓 Educational Note:** `WHERE` filters rows *before* grouping. `HAVING` filters groups *after* grouping. If you try to say `WHERE COUNT(*) > 3`, the database will yell at you.

---

### 3. Delete a book in the BOOK table. Update the contents of other tables to reflect this data manipulation operation.

**The Goal:** Referential Integrity. If a book is gone, its copies and lending records should be too.

**Option 1: The Manual Cleanup (The Hard Way)**
```sql
-- You must delete children first to avoid foreign key constraint errors!
DELETE FROM BOOK_AUTHORS WHERE Book_id = 101;
DELETE FROM BOOK_COPIES WHERE Book_id = 101;
DELETE FROM BOOK_LENDING WHERE Book_id = 101;
DELETE FROM BOOK WHERE Book_id = 101;
```

**Option 2: `ON DELETE CASCADE` (The Pro Move)**
*This isn't a query, but a table definition strategy. If you defined your tables like this:*
```sql
CREATE TABLE BOOK_COPIES (
    ...
    FOREIGN KEY (Book_id) REFERENCES BOOK(Book_id) ON DELETE CASCADE
);
```
*Then you simply run:*
```sql
DELETE FROM BOOK WHERE Book_id = 101;
-- The database engine automatically wipes the related rows. Magic! ✨
```

---

### 4. Create a view of all books and their number of copies that are currently available in the Library.

**The Goal:** Abstraction. Making complex data look simple.

**The Command:**
```sql
CREATE VIEW Available_Books AS
SELECT 
    B.Book_id, B.Title, SUM(C.No_of_Copies) as Total_Copies
FROM 
    BOOK B
    JOIN BOOK_COPIES C ON B.Book_id = C.Book_id
GROUP BY 
    B.Book_id, B.Title;
```

> **🧠 Concept Check:** A **View** is a "virtual table". It doesn't store data itself; it stores the query. Every time you `SELECT * FROM Available_Books`, SQL runs the query inside it.
