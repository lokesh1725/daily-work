#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Create table if not exists
void ensure_schema(sqlite3 *db) {
    const char *sql =
        "CREATE TABLE IF NOT EXISTS people_tbl ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "full_name TEXT NOT NULL,"
        "phone TEXT,"
        "email TEXT);";
    char *errmsg = NULL;
    if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        fprintf(stderr, "DB Error: %s\n", errmsg);
        sqlite3_free(errmsg);
        exit(1);
    }
}

// Add a new contact
void add_contact(sqlite3 *db) {
    char name[100], phone[100], email[100];
    printf("Full name: "); fgets(name, 100, stdin); name[strcspn(name, "\n")] = 0;
    printf("Phone: "); fgets(phone, 100, stdin); phone[strcspn(phone, "\n")] = 0;
    printf("Email: "); fgets(email, 100, stdin); email[strcspn(email, "\n")] = 0;

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,
        "INSERT INTO people_tbl(full_name, phone, email) VALUES(?,?,?)",
        -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, phone, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, email, -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    printf(" Contact added!\n");
}

// Search contact by name
void search_contact_by_name(sqlite3 *db) {
    char name[100];
    printf("Enter name to search: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,
        "SELECT id, full_name, phone, email FROM people_tbl "
        "WHERE full_name LIKE ?1 LIMIT 20;",
        -1, &stmt, NULL);

    char like[120];
    sprintf(like, "%%%s%%", name);
    sqlite3_bind_text(stmt, 1, like, -1, SQLITE_TRANSIENT);

    int found = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        found = 1;
        printf("[%d] %s | %s | %s\n",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_text(stmt, 1),
               sqlite3_column_text(stmt, 2),
               sqlite3_column_text(stmt, 3));
    }
    if (!found) {
        printf(" No contacts found with name '%s'\n", name);
    }
    sqlite3_finalize(stmt);
}

// Search contact by phone
void search_contact_by_phone(sqlite3 *db) {
    char phone[100];
    printf("Enter phone to search: ");
    fgets(phone, 100, stdin);
    phone[strcspn(phone, "\n")] = 0;

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,
        "SELECT id, full_name, phone, email FROM people_tbl "
        "WHERE phone LIKE ?1 LIMIT 20;",
        -1, &stmt, NULL);

    char like[120];
    sprintf(like, "%%%s%%", phone);
    sqlite3_bind_text(stmt, 1, like, -1, SQLITE_TRANSIENT);

    int found = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        found = 1;
        printf("[%d] %s | %s | %s\n",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_text(stmt, 1),
               sqlite3_column_text(stmt, 2),
               sqlite3_column_text(stmt, 3));
    }
    if (!found) {
        printf(" No contacts found with phone '%s'\n", phone);
    }
    sqlite3_finalize(stmt);
}

// View all contacts
void view_all_contacts(sqlite3 *db) {
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,
        "SELECT id, full_name, phone, email FROM people_tbl ORDER BY id LIMIT 100;",
        -1, &stmt, NULL);

    printf("\n--- All Contacts ---\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("[%d] %s | %s | %s\n",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_text(stmt, 1),
               sqlite3_column_text(stmt, 2),
               sqlite3_column_text(stmt, 3));
    }
    sqlite3_finalize(stmt);
}

// Update contact by ID
void update_contact(sqlite3 *db) {
    int id;
    printf("Enter contact ID to update: ");
    scanf("%d", &id);
    getchar(); // clear newline

    // Fetch current details
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,
        "SELECT full_name, phone, email FROM people_tbl WHERE id = ?;",
        -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) != SQLITE_ROW) {
        printf(" No contact found with ID %d\n", id);
        sqlite3_finalize(stmt);
        return;
    }

    const char *curr_name = (const char *)sqlite3_column_text(stmt, 0);
    const char *curr_phone = (const char *)sqlite3_column_text(stmt, 1);
    const char *curr_email = (const char *)sqlite3_column_text(stmt, 2);

    printf("Current details:\n");
    printf(" Name: %s\n Phone: %s\n Email: %s\n",
           curr_name, curr_phone, curr_email);

    sqlite3_finalize(stmt);

    char choice[10];
    printf("Update (1) Name, (2) Phone, (3) Email: ");
    fgets(choice, 10, stdin);

    char new_val[100];
    if (choice[0] == '1') {
        printf("Enter new name: ");
        fgets(new_val, 100, stdin); new_val[strcspn(new_val, "\n")] = 0;
        sqlite3_prepare_v2(db, "UPDATE people_tbl SET full_name=? WHERE id=?;",
                           -1, &stmt, NULL);
        sqlite3_bind_text(stmt, 1, new_val, -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 2, id);
    }
    else if (choice[0] == '2') {
        printf("Enter new phone: ");
        fgets(new_val, 100, stdin); new_val[strcspn(new_val, "\n")] = 0;
        sqlite3_prepare_v2(db, "UPDATE people_tbl SET phone=? WHERE id=?;",
                           -1, &stmt, NULL);
        sqlite3_bind_text(stmt, 1, new_val, -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 2, id);
    }
    else if (choice[0] == '3') {
        printf("Enter new email: ");
        fgets(new_val, 100, stdin); new_val[strcspn(new_val, "\n")] = 0;
        sqlite3_prepare_v2(db, "UPDATE people_tbl SET email=? WHERE id=?;",
                           -1, &stmt, NULL);
        sqlite3_bind_text(stmt, 1, new_val, -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 2, id);
    }
    else {
        printf(" Invalid choice.\n");
        return;
    }

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    printf(" Contact updated successfully!\n");
}

int main() {
    sqlite3 *db;
    if (sqlite3_open("people.db", &db)) {
        fprintf(stderr, " Can't open DB\n");
        return 1;
    }
    ensure_schema(db);

    char choice[10];
    while (1) {
        printf("\n==== Contacts DB ====\n");
        printf("1) Search contact by name\n");
        printf("2) Search contact by phone\n");
        printf("3) View all contacts\n");
        printf("4) Add contact\n");
        printf("5) Update contact\n");
        printf("6) Exit\n");
        printf("Choose: ");
        fgets(choice, 10, stdin);

        if (choice[0] == '1') search_contact_by_name(db);
        else if (choice[0] == '2') search_contact_by_phone(db);
        else if (choice[0] == '3') view_all_contacts(db);
        else if (choice[0] == '4') add_contact(db);
        else if (choice[0] == '5') update_contact(db);
        else if (choice[0] == '6') { printf(" Bye!\n"); break; }
        else printf(" Invalid choice.\n");
    }

    sqlite3_close(db);
    return 0;
}
