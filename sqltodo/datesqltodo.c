#include <stdio.h>
#include <sqlite3.h>

sqlite3 *db;

/* CREATE TABLE */
void createTable() {
    char *err = 0;

    char sql[] =
        "CREATE TABLE IF NOT EXISTS todo ("
        "date TEXT,"
        "task TEXT,"
        "status TEXT);";

    if (sqlite3_exec(db, sql, 0, 0, &err) != SQLITE_OK) {
        printf("Error creating table\n");
    }
}

/* INSERT DATA */
void insertData() {

    sqlite3_stmt *stmt;

    char task[100];
    char date[20];
    char status[20];

    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]", date);

    printf("Enter task: ");
    scanf(" %[^\n]", task);

    printf("Enter status (Complete/Incomplete): ");
    scanf(" %[^\n]", status);

    char sql[] = "INSERT INTO todo(date, task, status) VALUES(?,?,?);";

    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, date, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, task, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, status, -1, SQLITE_STATIC);

    sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    printf("Task added successfully!\n");
}

/* VIEW DATA (SHOW ROWID FOR DELETE) */
void viewData() {

    sqlite3_stmt *stmt;

    char sql[] = "SELECT rowid, * FROM todo;";

    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    printf("\nID | DATE        | STATUS     | TASK\n");
    printf("--------------------------------------------------------------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *date   = sqlite3_column_text(stmt, 1);
        const unsigned char *task   = sqlite3_column_text(stmt, 2);
        const unsigned char *status = sqlite3_column_text(stmt, 3);

        printf("%-2d | %-10s | %-10s | %s\n",
               id,
               date,
               status,
               task);
    }

    sqlite3_finalize(stmt);
}

/* DELETE TASK USING ROWID */
void deleteTask() {

    sqlite3_stmt *stmt;
    int id;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    char sql[] = "DELETE FROM todo WHERE rowid = ?;";

    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        printf("Task deleted successfully!\n");
    } else {
        printf("Failed to delete\n");
    }

    sqlite3_finalize(stmt);
}

/* MAIN FUNCTION */
int main() {

    int choice;

    if (sqlite3_open("todo.db", &db)) {
        printf("Database not opened\n");
        return 0;
    }

    createTable();

    while (1) {

        printf("\n--- TODO MENU ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            insertData();
        }
        else if (choice == 2) {
            viewData();
        }
        else if (choice == 3) {
            deleteTask();
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    sqlite3_close(db);

    return 0;
}
