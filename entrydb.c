#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Callback function for SELECT queries
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[512]; // Buffer to hold dynamic SQL
    int id;
    char name[100];

    // Get ID and NAME from user
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter NAME: ");
    scanf(" %[^\n]", name); // Read string with spaces

    // Open (or create) the database
    rc = sqlite3_open("/home/lokeshwarankrishnasamy/workspace/level1/test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    // Prepare SQL insert with fixed address and salary
    snprintf(sql, sizeof(sql),
        "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
        "VALUES (%d, '%s', 0, 'chennai', 65000.00);", id, name);

    // Execute insert
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Record inserted successfully\n");
    }

    // Select and print all records
    printf("\nSELECT operation:\n");
    rc = sqlite3_exec(db, "SELECT * FROM COMPANY;", callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }

    // Close database
    sqlite3_close(db);
    return 0;
}
