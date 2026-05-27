#include <stdio.h>
int main() {
    FILE *f = fopen("data.txt", "a");
    char task[100];
    printf("Enter task: ");
    fgets(task, sizeof(task), stdin);
        fprintf(f, "%s", task);
    fclose(f);
    printf("Task added to data.txt");
    return 0;
}