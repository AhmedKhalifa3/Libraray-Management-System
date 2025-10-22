# Library Management System

## Chapter 1: Introduction and Problem Statement

### 1.1 Project Overview
The Library Management System is an **object-oriented C++ application** designed to manage a library's book collection.  
It allows users to:

- Add and delete books.
- Search for books by title, author, or ID.
- Borrow and return books.
- Maintain an updated catalog of available books.

### 1.2 Project Scope
This project focuses on **core library management functionalities**, including:

- Book management (add, delete, search).
- Borrowing and returning books.
- Basic retrieval of book information.

### 1.3 Project Objectives
- Provide a user-friendly interface for library staff.
- Enable efficient book searches.
- Maintain records of borrowed and returned books.
- Streamline book management processes.

### 1.4 Related Work
Existing library management software may be complex, costly, or lack certain features.  
This project offers a **simple, customizable, and cost-effective solution** for small to medium-sized libraries.

### 1.5 Problem Statement
Manual book management is **time-consuming, error-prone, and inefficient**.  
The system automates these tasks, improving **efficiency, accuracy, and accessibility**.

### 1.6 Tasks and Deliverables
**Tasks:**

- Design `Book` and `Library` classes.
- Implement functions for adding, deleting, searching, borrowing, and returning books.
- Create user input/output interfaces.
- Test and debug the system.

**Deliverables:**

- Fully functional Library Management System.
- Comprehensive documentation and user guide.

### 1.7 Assumptions and Constraints
- System operates within a single library.
- Hardware/software requirements are met.
- Suitable for small to medium-sized collections.

### 1.8 Target Audience
Library staff, librarians, and administrators managing book collections.

### 1.9 Summary
This chapter introduces the project, its objectives, scope, and problem statement.  
Subsequent chapters cover design, implementation, testing, results, and user guides.

---

## Chapter 2: Solution Design and Implementation

### 2.1 Solution Overview
The system consists of **two main classes**:

1. `Book` – stores book information and availability.
2. `Library` – manages the book collection and operations.

### 2.2 Class Structure

#### 2.2.1 Book Class
**Attributes:**

- `title`, `author`, `publisher`
- `ID`, `year`
- `availability`

**Methods:**

- `get_title()`, `get_author()`, `get_ID()`, `get_publisher()`, `get_year()`
- `isAvailable()`
- `borrowBook()`, `returnBook()`

#### 2.2.2 Library Class
**Attributes:**

- `books`: vector of `Book*` representing the collection.

**Methods:**

- `addBook(Book* book)`, `deleteBook(const string& title)`
- `displayBooks() const`
- `searchByAuthor()`, `searchByTitle()`, `searchByID()`, `searchByYear()`
- `borrowBook(const string& title)`, `returnBook(const string& title)`
- `saveBooks(const string& filename)`, `getFileBooks(const string& filename)`

### 2.3 Implementation Details
- **Book Operations:** Adding, deleting, and searching books.
- **Borrowing/Returning:** Updates book availability.
- **Input Validation:** Ensures correct input using try-catch blocks.
- **Flowcharts/Control Flow:** Visualizes operational steps for all actions.

---

## Chapter 3: Testing and Verification

### 3.1 Testing Methodologies

#### Unit Testing
- Verify `Book` and `Library` methods with multiple input scenarios.
- Test edge cases (e.g., borrowing already borrowed books).

#### Integration Testing
- Ensure `Book` and `Library` interact correctly.
- Validate data consistency when adding, deleting, borrowing, and returning books.

#### Validation Testing
- Confirm system meets requirements.
- Check user input handling and expected outputs.
- Test file storage and retrieval functionality.

---

## Chapter 4: Results, Discussion, and Future Enhancements

### 4.1 Results and Achievements
- Successfully adds, deletes, searches, borrows, and returns books.
- Persists data in a TXT file across sessions.
- Efficiently manages library operations.

### 4.2 Challenges and Lessons Learned
- Exception handling and input validation required robust solutions.
- Learned importance of **data persistence** and **error handling**.

### 4.3 Future Enhancements
1. **User Management:** Support multiple users with different access levels.
2. **Advanced Search Options:** Search by genre, ISBN, or date range.
3. **Data Analytics:** Generate reports on book usage and popularity.

---

## Chapter 5: Conclusion and References

### 5.1 Conclusion
Developed a **fully functional Library Management System in C++**, improving efficiency, accuracy, and user experience.

### 5.2 Lessons Learned
- Importance of **exception handling**.
- Ensuring **data persistence** using external files.

### 5.3 References
1. Stroustrup, B. *The C++ Programming Language*, 4th ed., Addison-Wesley, 2013.  
2. Savitch, W. *Absolute C++*, Pearson, 2017.  
3. Eckel, B. *Thinking in C++ (Vol. 1 & 2)*, Prentice Hall, 2014.
