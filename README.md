# Student Record Management System

A console-based **Student Record Management System developed in C**. This project allows users to add, display, search, update, and delete student records. Student data is stored in a file so that records can be accessed again when the program is restarted.

## 📌 About the Project

This project was created to practice and demonstrate fundamental **C programming concepts** such as:

* Structures
* Arrays
* Functions
* Loops
* Conditional statements
* File handling
* User input/output
* Searching and updating records
* Basic data management

It is designed as a beginner-friendly C project and can be further improved with additional features.

## ✨ Features

* ➕ Add new student records
* 📋 Display all student records
* 🔍 Search for a student by roll number
* ✏️ Update student information
* 🗑️ Delete student records
* 📊 Calculate student percentage
* 💾 Store records using file handling
* 🚪 Menu-driven console interface

## 🛠️ Technologies Used

* **Programming Language:** C
* **Compiler:** GCC / MinGW
* **Editor:** Visual Studio Code
* **Version Control:** Git & GitHub

## 📂 Project Structure

```text
Student-Record-Management-System/
│
├── Student_Record_Management.c
├── README.md
└── LICENSE
```

## ▶️ How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/ranveersingh0905/Student-Record-Management-System.git
```

### 2. Navigate to the Project Folder

```bash
cd Student-Record-Management-System
```

### 3. Compile the Program

Using GCC:

```bash
gcc Student_Record_Management.c -o Student_Record_Management
```

### 4. Run the Program

On Git Bash / Linux:

```bash
./Student_Record_Management
```

On Windows:

```bash
Student_Record_Management.exe
```

## 🖥️ Main Menu

```text
========================================
       STUDENT RECORD MANAGEMENT
========================================

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit

Enter your choice:
```

## 📚 Concepts Demonstrated

### Structures

A `struct Student` is used to store information such as:

* Roll number
* Name
* Age
* Department
* Marks
* Percentage

### Functions

The program is divided into separate functions for different operations, making the code easier to understand and maintain.

### File Handling

Student records are stored in a file using C file-handling functions such as:

```c
fopen()
fread()
fwrite()
fclose()
```

### CRUD Operations

The project demonstrates basic **CRUD operations**:

| Operation | Function               |
| --------- | ---------------------- |
| Create    | Add Student            |
| Read      | Display/Search Student |
| Update    | Update Student         |
| Delete    | Delete Student         |

## 🚀 Future Improvements

The project can be extended with:

* [ ] Input validation
* [ ] Duplicate roll-number prevention
* [ ] Search students by name
* [ ] Sort students by percentage
* [ ] Grade calculation
* [ ] Subject-wise marks
* [ ] Better formatted output
* [ ] Improved error handling
* [ ] Separate `.c` and `.h` files
* [ ] Improved user input handling

## 🎯 Learning Objective

The main objective of this project is to strengthen practical knowledge of **C programming and file handling** by building a simple real-world application.

## 👨‍💻 Author

**Ranveer Singh**

GitHub: [ranveersingh0905](https://github.com/ranveersingh0905)

## 📄 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more information.

---

⭐ If you find this project useful, consider giving the repository a star!

