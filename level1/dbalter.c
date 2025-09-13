#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Callback function for SELECT queries
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    sqlite3 *db; // Database connection object
    char *zErrMsg = 0; // To store error messages from SQLite
    int rc; // Return code from SQLite API calls
    const char *sql; // SQL statement string

    // 1. Open database (or create if it doesn't exist)
    rc = sqlite3_open("/home/lokeshwarankrishnasamy/workspace/level1/test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(1);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

   

    // 3. Create SQL statements for inserting data
    sql = 
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) " \
          "VALUES (5, 'Lokesh', 20, 'chennai ', 65000.00 );";

    // Execute SQL statement (multiple inserts in one call)
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    // 4. Create SQL statement for selecting data
    sql = "SELECT * from COMPANY";

    // Execute SQL statement with callback to print results
    fprintf(stdout, "\nSELECT operation:\n");
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }

    // 5. Close the database
    sqlite3_close(db);

    return 0;
}