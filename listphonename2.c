#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 50
#define FILE_PATH "contacts.txt"

typedef struct {
    char name[LEN], phone[LEN];
} Contact;

void addContact() {
    Contact c;
    printf("Enter name: ");  scanf(" %[^\n]", c.name);
    printf("Enter phone: "); scanf(" %[^\n]", c.phone);

    FILE *f = fopen(FILE_PATH, "a");
    if (!f) { perror("File"); return; }
    fprintf(f, "%s,%s\n", c.name, c.phone);
    fclose(f);
}

void listContacts(char filter) {
    FILE *f = fopen(FILE_PATH, "r");
    if (!f) { perror("File"); return; }

    char name[LEN], phone[LEN];
    int count = 1, found = 0;
    fseek(f, 0, SEEK_SET);  // reset pointer

    while (fscanf(f, " %[^,],%[^\n]", name, phone) == 2) {
        if (!filter || tolower(name[0]) == tolower(filter)) {
            printf("%d. %s - %s\n", count++, name, phone);
            found = 1;
        }
    }

    if (filter && !found)
        printf("No contacts starting with '%c'.\n", filter);

    fclose(f);
}

void findContact() {
    char search[LEN], name[LEN], phone[LEN];
    printf("Enter name to find: ");
    scanf(" %[^\n]", search);

    FILE *f = fopen(FILE_PATH, "r");
    if (!f) { perror("File"); return; }

    fseek(f, 0, SEEK_SET);  // seek to start
    while (fscanf(f, " %[^,],%[^\n]", name, phone) == 2) {
        if (strcasecmp(name, search) == 0) {
            printf("Found: %s - %s\n", name, phone);
            fclose(f);
            return;
        }
    }

    printf("Contact not found.\n");
    fclose(f);
}

int main() {
    int choice;
    char ch;

    do {
        printf("\n1. Add\n2. List All\n3. List by Letter\n4. Find\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: listContacts(0); break;
            case 3: printf("Enter letter: "); scanf(" %c", &ch); listContacts(ch); break;
            case 4: findContact(); break;
            case 5: break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 5);

    return 0;
}
