# Command-Line Task Manager
A simple yet robust command-line task management application written in C. This project demonstrates core C programming skills, including file I/O, struct-based data management, modular design, and input validation. It allows users to manage tasks by adding, listing, deleting, and marking them as completed, with persistent storage in a text file.
## Features

- Add Tasks: Create tasks with a description and priority (High, Medium, Low).
- List Tasks: View all tasks with their ID, description, priority, and completion status.
- Delete Tasks: Remove tasks by their ID.
- Mark as Completed: Update tasks to reflect completion.
- Persistent Storage: Tasks are saved to and loaded from a tasks.txt file.
- Input Validation: Ensures robust handling of invalid inputs (e.g., non-numeric input, out-of-range priorities).
- Modular Code: Organized with separate header and source files for maintainability.

## Prerequisites

GCC: C compiler (available on Linux, macOS, or via MinGW on Windows).
Make: For building the project using the provided Makefile.
A C99-compatible environment.

## Installation

1. Clone or download the repository to your local machine.
2. Ensure the following files are in the project directory:
- task_manager.c
- task_manager.h
- Makefile

3. Open a terminal in the project directory.
4. Run the following command to compile:
````
make
````
5. This generates an executable named task_manager (or task_manager.exe on Windows).
To clean up object files and the executable, run:
````
make clean
````

## Usage

1. Run the program:
````
./task_manager
````

2. Follow the menu prompts to interact with the task manager:Task Manager
````
1. Add Task
2. List Tasks
3. Delete Task
4. Mark Task as Completed
5. Exit
Enter choice:
````

3. Example workflow:
Choose 1 to add a task, enter a description (e.g., "Finish project report"), and a priority (1=High, 2=Medium, 3=Low).
Choose 2 to list all tasks.
Choose 3 and enter a task ID to delete a task.
Choose 4 and enter a task ID to mark a task as completed.
Choose 5 to exit (tasks are automatically saved to tasks.txt).



Example Output
````
Task Manager
1. Add Task
2. List Tasks
3. Delete Task
4. Mark Task as Completed
5. Exit
Enter choice: 1
Enter task description: Write README
Enter priority (1=High, 2=Medium, 3=Low): 1
Task added successfully.

Enter choice: 2
Tasks:
ID | Description        | Priority | Status
------------------------------------
1  | Write README       | 1        | Pending

Enter choice: 4
Enter task ID to mark as completed: 1
Task marked as completed.

Enter choice: 2
Tasks:
ID | Description        | Priority | Status
------------------------------------
1  | Write README       | 1        | Completed
````

## File Structure

task_manager.c: Main program with user interface and core logic.
task_manager.h: Header file with struct definitions and function prototypes.
Makefile: Automates compilation.
tasks.txt: Generated file for storing tasks persistently.

#
