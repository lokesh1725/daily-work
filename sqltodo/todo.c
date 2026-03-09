#include <stdio.h>
#include <sqlite3.h>

sqlite3 *db;

/* CREATE TABLE IF NOT EXISTS */
void initDB() {
    char *err = 0;

    char sql[] =
        "CREATE TABLE IF NOT EXISTS tasks ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "task TEXT NOT NULL);";

    sqlite3_exec(db, sql, 0, 0, &err);
}

/* ADD TASK */
void addTask() {
    sqlite3_stmt *stmt;
    char task[100];

    printf("Enter task: ");
    scanf(" %[^\n]", task);

    char sql[] = "INSERT INTO tasks(task) VALUES(?);";

    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, task, -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    printf("Task added!\n");
}

/* VIEW TASKS */
void viewTasks() {
    sqlite3_stmt *stmt;
    char sql[] = "SELECT * FROM tasks;";

    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    printf("\n--- TASK LIST ---\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("%d. %s\n",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_text(stmt, 1));
    }

    sqlite3_finalize(stmt);
}

/* DELETE TASK */
void deleteTask() {
    int id;
    sqlite3_stmt *stmt;

    viewTasks();

    printf("Enter task id to delete: ");
    scanf("%d", &id);

    char sql[] = "DELETE FROM tasks WHERE id=?;";

    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    printf("Task deleted!\n");
}

int main() {
    int choice;

    if (sqlite3_open("tasks.db", &db)) {
        printf("Database not opened!\n");
        return 0;
    }

    initDB();   //  important

    while (1) {
        printf("\n1.Add\n2.Delete\n3.View\n4.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) addTask();
        else if (choice == 2) deleteTask();
        else if (choice == 3) viewTasks();
        else break;
    }

    sqlite3_close(db);
}