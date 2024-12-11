# **Data Processing and Storage Assignment**

## **Description**
This project implements an in-memory key-value database in C++ with support for transactions. The database allows operations like starting a transaction, adding/updating key-value pairs, retrieving values, committing transactions, and rolling back transactions.

---

## **Features**
1. **Begin Transaction**: Start a new transaction to modify data.
2. **Put (Add/Update)**: Add or update key-value pairs within a transaction.
3. **Get (Retrieve)**: Fetch values by key, considering transaction visibility.
4. **Commit**: Apply changes from the transaction to the main database.
5. **Rollback**: Discard all changes made in the current transaction.

---

## **Setup and Usage Instructions**

### **Requirements**
- C++ Compiler supporting C++20 (e.g., GCC 11+, Clang 12+).
- CMake (if building with CMake).
- A development environment (e.g., VSCode, CLion, or terminal).

### **Setup**

#### **Using CLion**
1. Open CLion and select "Open" from the welcome screen.
2. Navigate to the project directory and open it.
3. Ensure the `CMakeLists.txt` file exists in the project directory. CLion automatically detects it and configures the build.
4. Click the "Run" button (green triangle) in the top-right corner to build and execute the project.
5. View the output in the "Run" console at the bottom.

#### **Direct Compilation**
1. Compile the library first:
   ```bash
   g++ -std=c++20 -c InMemoryDB.cpp -o InMemoryDB.o
   ```
2. Compile and link the main program with the library:
   ```bash
   g++ -std=c++20 main.cpp InMemoryDB.o -o in_memory_db
   ```
3. Run the program:
   ```bash
   ./in_memory_db
   ```

### **Sample Output**
The program will output various states and errors based on the operations performed in `main.cpp`. Example:
```plaintext
null
Error: Cannot put without an active transaction
null
6
Error: No active transaction to commit
Error: No active transaction to rollback
null
null
```

---

## **Future Modifications for Official Assignment**
1. **Clarifications on Error Messages**:
   - Specify the format for returning missing keys (e.g., "null" or a specific value like `-1`).
   - Define if error handling should use exceptions (`std::runtime_error`) or printed error messages.

2. **Additional Methods**:
   - Allow nested transactions for advanced use cases.
   - Add methods to delete keys or clear the database.

3. **Testing and Grading**:
   - Provide a suite of automated test cases for graders to verify the functionality.
   - Include edge cases, such as empty keys or extremely large data sets.

---

