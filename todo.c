#include <stdio.h>
#include <string.h>

#define LEN 100
#define FILE_NAME "tasks.txt"

void viewTasks() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[LEN];
    int i = 1;

    if (fp == NULL) {
        printf("No tasks.\n");
        return;
    }

    while (fgets(line, LEN, fp)) {
        line[strcspn(line, "\n")] = '\0';  // remove newline
        printf("%d. %s\n", i++, line);
    }
    fclose(fp);
}

void addTask() {
    FILE *fp = fopen(FILE_NAME, "a");
    char task[LEN];
    printf("Enter task: ");
    scanf(" %[^\n]", task);
    fprintf(fp, "%s\n", task);
    fclose(fp);
}

void deleteTask() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    char line[LEN];
    int num, i = 1;

    if (fp == NULL) {
        printf("No tasks to delete.\n");
        return;
    }

    viewTasks();
    printf("Enter task number to delete: ");
    scanf("%d", &num);

    while (fgets(line, LEN, fp)) {
        if (i != num) fprintf(temp, "%s", line);
        i++;
    }
    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    printf("Task deleted!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Task\n2. Delete Task\n3. View Tasks\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) addTask();
        else if (choice == 2) deleteTask();
        else if (choice == 3) viewTasks();
        else if (choice == 4) break;
        else printf("Invalid choice!\n");
    }
    return 0;
}
