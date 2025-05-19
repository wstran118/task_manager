#ifndef TASK_MANAGER_H
#define TASK_MANAGER

#define MAX_TASKS 100
#define MAX_DESC 100
#define FILENAME "tasks.txt"

typedef struct {
    int id;
    char description[MAX_DESC];
    int priority; //1-high, 2-medium, 3-low
    int completed; 
} Task;

void add_task(Task tasks[], int *task_count, const char *description, int priority);
void list_tasks(const Task tasks[], int task_count);
void delete_task(Task tasks[], int *task_count, int id);
void save_tasks(const Task tasks[], int task_count);
void load_tasks(Task tasks[]);
void complete_task(Task tasks[], int *task_count, int id);
int validate_input(const char *input, int min, int max);

#endif