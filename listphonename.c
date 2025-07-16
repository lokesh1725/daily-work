#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50
#define FILE_PATH "contacts.txt"

void addContact() {
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];

    printf("Enter name: ");
    scanf(" %[^\n]", name);

    printf("Enter phone: ");
    scanf(" %[^\n]", phone);

    FILE *file = fopen(FILE_PATH, "a");  // Append mode
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s,%s\n", name, phone);  // Save to file
    fclose(file);

    printf("Contact added successfully.\n");
}

void listContacts() {
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];

    FILE *file = fopen(FILE_PATH, "r");  // Read mode
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n--- Saved Contacts ---\n");
    int count = 1;
    while (fscanf(file, " %[^,],%[^\n]\n", name, phone) == 2) {
        printf("Contact %d:\n", count++);
        printf("  Name : %s\n", name);
        printf("  Phone: %s\n\n", phone);
    }

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\n1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: listContacts(); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
