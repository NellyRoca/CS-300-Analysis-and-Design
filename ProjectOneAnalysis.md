# Project One: Pseudocode and Runtime Analysis for Data Structures

By Nelly Roca – SNHU-CS-300

---

## Shared Logic: File Handling & Course Object Creation

- Open the file `courses.txt`.
- While not end of file:
  - Read line.
  - Split line by comma.
  - If line has fewer than 2 parts:
    - Display "Formatting Error".
    - Continue.
  - Create new Course object.
  - Set course.courseID = line[0].
  - Set course.title = line[1].
  - For i from 2 to length of line:
    - Add line[i] to course.prerequisites list.

---

## Vector-Based Pseudocode

- Menu Option 1: Load Data  
  Create empty vector courseList.  
  For each course in file:  
    Append course object to courseList.

- Menu Option 2: Print Course List (Sorted)  
  Sort courseList by courseID.  
  For each course in courseList:  
    Print course.courseID and course.title.

- Menu Option 3: Find Course Info  
  Prompt user for courseID.  
  For each course in courseList:  
    If course.courseID equals input:  
      Print course.title and prerequisites.  
      Exit loop.

- Menu Option 9: Exit Program  
  Exit program.

---

## Hash Table-Based Pseudocode

- Menu Option 1: Load Data  
  Create empty hashTable.  
  For each course in file:  
    Insert course using courseID as key.

- Menu Option 2: Print Course List (Sorted)  
  Create list of keys from hashTable.  
  Sort keys alphanumerically.  
  For each key in sorted list:  
    Print hashTable[key].courseID and title.

- Menu Option 3: Find Course Info  
  Prompt user for courseID.  
  If courseID exists in hashTable:  
    Print title and prerequisites.  
  Else:  
    Print "Course not found".

- Menu Option 9: Exit Program  
  Exit program.

---

## Binary Search Tree-Based Pseudocode

- Menu Option 1: Load Data  
  Create empty BST.  
  For each course in file:  
    Insert course into BST using courseID as key.

- Menu Option 2: Print Course List (Sorted)  
  Perform in-order traversal of BST:  
    If node exists:  
      Traverse left.  
      Print courseID and title.  
      Traverse right.

- Menu Option 3: Find Course Info  
  Prompt user for courseID.  
  Search BST for courseID.  
  If found:  
    Print title and prerequisites.  
  Else:  
    Print "Course not found".

- Menu Option 9: Exit Program  
  Exit program.

---

## Runtime Analysis Chart

| Operation            | Vector          | Hash Table         | Binary Search Tree    |
|----------------------|-----------------|--------------------|----------------------|
| File Load & Parse    | O(n)            | O(n)               | O(n)                 |
| Insertion            | O(1) append     | O(1) average       | O(log n) average     |
| Sort Course List     | O(n log n)      | O(n log n)         | O(n) via traversal   |

---

## Data Structure Evaluation

**Vector**  
- Pros: Simple and easy to implement; Works well for small datasets  
- Cons: Linear search is inefficient; Requires sorting each time to print; Not scalable for large data  

**Hash Table**  
- Pros: Very fast search and insertion; Efficient data loading and access  
- Cons: Keys must be extracted and sorted to print in order; Higher memory usage  

**Binary Search Tree (BST)**  
- Pros: Data stays sorted naturally; Balanced search, insertion, and traversal  
- Cons: Needs logic for balancing; More complex implementation  

---

## Recommendation

Based on runtime performance and efficiency, I recommend using the **Binary Search Tree (BST)**. It efficiently handles loading data, printing an ordered list, and searching course details. Its in-order traversal avoids extra sorting, making it the best all-around choice for the advising program.
