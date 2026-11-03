# Smart-Parcel-Priority-Sorter
A C-based parcel management system with priority sorting, parcel searching and dispatch planning.
# 📦 Smart Parcel Priority Sorter

A console-based parcel management system developed using **C programming**. The project simulates how a courier company can manage parcels, prioritise deliveries, search records, and generate a dispatch summary based on parcel priority and delivery deadlines.

## 🚀 Project Overview

The Smart Parcel Priority Sorter is designed to simplify basic parcel management operations. It allows users to enter parcel details, store records permanently in a file, sort parcels according to priority, and generate a dispatch plan.

The project focuses on applying fundamental C programming concepts to solve a practical, real-world-inspired problem.

## ✨ Features

- **Add New Parcel:** Enter parcel ID, destination, distance, priority, and delivery deadline.
- **View All Parcels:** Display all previously saved parcel records.
- **Sort by Priority:** Arrange parcels using Bubble Sort, with Urgent parcels first, followed by Express and Normal.
- **Search Parcel:** Find a parcel using its unique ID through Linear Search.
- **Dispatch Summary:** Calculate parcel statistics, total distance, and parcels approaching their deadlines.
- **Priority Dispatch Plan:** Identify urgent parcels and parcels with deadlines within two days, then estimate their dispatch schedule.
- **Input Validation:** Validate parcel details and prevent duplicate parcel IDs.
- **File Storage:** Save parcel records using binary file handling so that data remains available after restarting the program.

## 🛠️ Technologies & Concepts Used

**Language:** C

**Tools:** Visual Studio Code, GCC Compiler, Git, GitHub

**C Programming Concepts:**
- Structures (`struct`)
- Functions
- Arrays
- Conditional Statements and Loops
- File Handling (`fread()`, `fwrite()`)
- Bubble Sort
- Linear Search
- Input Validation

## ⚙️ How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/anubhav-2107/Smart-Parcel-Priority-Sorter.git
```

### 2. Open the Project Folder

```bash
cd Smart-Parcel-Priority-Sorter
```

### 3. Compile the Program

```bash
gcc main.c -o sorter
```

### 4. Run the Program

**Windows:**
```bash
.\sorter.exe
```

**Linux/macOS:**
```bash
./sorter
```

## 📋 Main Menu

The program provides the following operations:

1. Add New Parcel
2. View All Parcels
3. Sort Parcels by Priority
4. Search Parcel
5. Dispatch Summary
6. Exit

## 📊 Priority System

| Priority | Type | Description |
|---|---|---|
| 3 | Urgent | Highest delivery priority |
| 2 | Express | Medium delivery priority |
| 1 | Normal | Standard delivery priority |

## 📦 Dispatch Planning Logic

The dispatch summary considers:
- Parcel priority.
- Remaining delivery deadline.
- Total delivery distance.
- Estimated travel time.

The dispatch plan uses an assumed average vehicle speed of **60 km/hour** and a maximum driving time of **8 hours per day**.

*Note: Dispatch timings are simulated estimates, not actual delivery predictions. The program does not use live traffic or route data.*

## 🎯 Learning Objectives

This project helped me understand how fundamental C programming concepts can be combined to build a functional application. It provided practical experience with structures, functions, sorting algorithms, searching techniques, file handling, and input validation.

## 🔮 Future Improvements

- Add a graphical user interface.
- Implement more advanced sorting algorithms.
- Add parcel status tracking.
- Introduce delivery route optimisation.
- Generate detailed delivery reports.

## 👨‍💻 Author

**Anubhav Chawla**

GitHub: [@anubhav-2107](https://github.com/anubhav-2107)

---

⭐ If you find this project interesting, feel free to explore the repository!
