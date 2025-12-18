# 📚 Program 1: Library Database (SQL)

**the vibe:** we are managing a library. books, authors, borrowers. it's classic data modeling.

## 📋 Schema
- **book** (book_id, title, publisher_name, pub_year)
- **book_authors** (book_id, author_name)
- **publisher** (name, address, phone)
- **book_copies** (book_id, branch_id, no-of_copies)
- **book_lending** (book_id, branch_id, card_no, date_out, due_date)
- **library_branch** (branch_id, branch_name, address)

---

## 🔍 Queries

### 1. Retrieve details of all books in the library – id, title, name of publisher, authors, number of copies in each branch, etc.

**the goal:** a massive join to see everything about a book.

**option 1: the "i want it all" join (standard)**
```sql
select 
    b.book_id, b.title, b.publisher_name, a.author_name, 
    c.no_of_copies, l.branch_name
from 
    book b
    join book_authors a on b.book_id = a.book_id
    join book_copies c on b.book_id = c.book_id
    join library_branch l on c.branch_id = l.branch_id;
```

**option 2: the "comma-separated" style (old school)**
```sql
select 
    b.book_id, b.title, b.publisher_name, a.author_name, 
    c.no_of_copies, l.branch_name
from 
    book b, book_authors a, book_copies c, library_branch l
where 
    b.book_id = a.book_id 
    and b.book_id = c.book_id 
    and c.branch_id = l.branch_id;
```

> **🎓 fun fact:** the `join` syntax (ansi-92) is generally preferred over the comma-separated syntax because it separates the *relationship logic* from the *filtering logic*. it makes your code less prone to accidental cross-joins (where you get millions of rows because you forgot a `where` clause).

---

### 2. Get the particulars of borrowers who have borrowed more than 3 books, but from Jan 2017 to Jun 2017.

**the goal:** filtering by date range and aggregation.

**option 1: `having` clause (the groupie)**
```sql
select card_no
from book_lending
where date_out between '2017-01-01' and '2017-06-30'
group by card_no
having count(*) > 3;
```

**option 2: with a join to get names (the complete picture)**
*assuming there is a `borrower` table implied but not explicitly listed in schema. if not, we just return card_no.*
```sql
select b.name, bl.card_no
from borrower b
join book_lending bl on b.card_no = bl.card_no
where bl.date_out >= '2017-01-01' and bl.date_out <= '2017-06-30'
group by bl.card_no, b.name
having count(bl.book_id) > 3;
```

> **🤓 educational note:** `where` filters rows *before* grouping. `having` filters groups *after* grouping. if you try to say `where count(*) > 3`, the database will yell at you.

---

### 3. Delete a book in the BOOK table. Update the contents of other tables to reflect this data manipulation operation.

**the goal:** referential integrity. if a book is gone, its copies and lending records should be too.

**option 1: the manual cleanup (the hard way)**
```sql
-- you must delete children first to avoid foreign key constraint errors!
delete from book_authors where book_id = 101;
delete from book_copies where book_id = 101;
delete from book_lending where book_id = 101;
delete from book where book_id = 101;
```

**option 2: `on delete cascade` (the pro move)**
*this isn't a query, but a table definition strategy. if you defined your tables like this:*
```sql
create table book_copies (
    ...
    foreign key (book_id) references book(book_id) on delete cascade
);
```
*then you simply run:*
```sql
delete from book where book_id = 101;
-- the database engine automatically wipes the related rows. magic! ✨
```

---

### 4. Create a view of all books and their number of copies that are currently available in the Library.

**the goal:** abstraction. making complex data look simple.

**the command:**
```sql
create view available_books as
select 
    b.book_id, b.title, sum(c.no_of_copies) as total_copies
from 
    book b
    join book_copies c on b.book_id = c.book_id
group by 
    b.book_id, b.title;
```

> **🧠 concept check:** a **view** is a "virtual table". it doesn't store data itself; it stores the query. every time you `select * from available_books`, sql runs the query inside it.
