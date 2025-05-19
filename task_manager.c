#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_manager.h"

void add_task(Task tasks[], int *task_count, const char *description, int priority) 
{
    if(*task_count >= MAX_TASKS){
        printf("Error: Task limit reach\n");
        return;
    }
    tasks[*task_count].id = *task_count + 1;
    strncpy(tasks[*task_count].description, description, MAX_DESC - 1);
    tasks[*task_count].description[MAX_DESC-1]='\0';
    tasks[*task_count].priority = priority;
    tasks[*task_count].completed = 0;
    (*task_count)++;
    printf("Task added successfully.\n");
    save_tasks(tasks, *task_count);
}// end add_task

void list_tasks(const Task tasks[], int task_count)
{
    if(task_count == 0) {
        printf("No tasks avaiable.\n");
        return;
    }//end if

    printf("\nTasks:\n");
    printf("ID |  Description | Priority | Status\n");
    printf("-------------------------------------\n");
    for(int i = 0; i < task_count; i++) {
        printf("%d | %s | $d | %s\n", tasks[i].id, tasks[i].description, tasks[i].priority, tasks[i].completed? "Completed" : "Pending");
    }//end for
}//end list_tasks

void delete_task(Task tasks[], int *task_count, int id)
{
    int found = 0;
    for(int i = 0; i < *task_count; i++){
        if(tasks[i].id == id) {
            found = 1;
            for(int j = i; j < *task_count -1; j++) {
                tasks[j] = tasks[j+1];
                tasks[j].id = j + 1; // reassign ID
            }//end for
            (*task_count)--;
            printf("Task deleted successfully.\n");
            save_tasks(tasks, *task_count);
            break;
        }// end if
        if(!found) {
            printf("Error: Task ID not found.\n");
        }
    }//end outter for

}//end delete_task

void complete_task(Task tasks[], int task_count, int id) 
{
 for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
            printf("Task marked as completed.\n");
            save_tasks(tasks, task_count);
            return;
        }
    }
    printf("Error: Task ID not found.\n");
}

void save_tasks(const Task tasks[], int task_count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error: Could not save tasks.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d|%s|%d|%d\n", tasks[i].id, tasks[i].description,
                tasks[i].priority, tasks[i].completed);
    }
    fclose(file);
}

int load_tasks(Task tasks[]) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        return 0; // File doesn't exist yet
    }
    int task_count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file) && task_count < MAX_TASKS) {
        sscanf(line, "%d|[^|]|%d|%d", &tasks[task_count].id,
               tasks[task_count].description, &tasks[task_count].priority,
               &tasks[task_count].completed);
        task_count++;
    }
    fclose(file);
    return task_count;
}

int validate_input(const char *input, int min, int max) {
    char *endptr;
    long value = strtol(input, &endptr, 10);
    if (*endptr != '\n' && *endptr != '\0') {
        return -1; // Not a number
    }
    if (value < min || value > max) {
        return -1; // Out of range
    }
    return (int)value;
}

int main() {
    Task tasks[MAX_TASKS];
    int task_count = load_tasks(tasks);
    char input[256];
    int choice;

    while (1) {
        printf("\nTask Manager\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Mark Task as Completed\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        fgets(input, sizeof(input), stdin);

        choice = validate_input(input, 1, 5);
        if (choice == -1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            continue;
        }

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1: {
                printf("Enter task description: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline
                if (strlen(input) == 0) {
                    printf("Error: Description cannot be empty.\n");
                    break;
                }
                printf("Enter priority (1=High, 2=Medium, 3=Low): ");
                fgets(input, sizeof(input), stdin);
                int priority = validate_input(input, 1, 3);
                if (priority == -1) {
                    printf("Invalid priority. Please enter 1, 2, or 3.\n");
                    break;
                }
                add_task(tasks, &task_count, input, priority);
                break;
            }
            case 2:
                list_tasks(tasks, task_count);
                break;
            case 3:
                printf("Enter task ID to delete: ");
                fgets(input, sizeof(input), stdin);
                int id = validate_input(input, 1, MAX_TASKS);
                if (id == -1) {
                    printf("Invalid ID.\n");
                    break;
                }
                delete_task(tasks, &task_count, id);
                break;
            case 4:
                printf("Enter task ID to mark as completed: ");
                fgets(input, sizeof(input), stdin);
                id = validate_input(input, 1, MAX_TASKS);
                if (id == -1) {
                    printf("Invalid ID.\n");
                    break;
                }
                complete_task(tasks, task_count, id);
                break;
        }
    }
    return 0;
}
