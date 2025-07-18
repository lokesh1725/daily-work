#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LEN 50
#define FILE_PATH "contacts.txt"

typedef struct {
    char name[LEN], phone[LEN];
} Contact;

void addContact() {
    Contact c;
    printf("Enter name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter phone: ");
    scanf(" %[^\n]", c.phone);

    FILE *f = fopen(FILE_PATH, "a");
    if (!f) { perror("File"); return; }
    fprintf(f, "%s,%s\n", c.name, c.phone);
    fclose(f);
    printf("Contact added.\n");
}

int loadContacts(Contact c[]) {
    FILE *f = fopen(FILE_PATH, "r");
    if (!f) { perror("File"); return 0; }
    int n = 0;
    while (fscanf(f, " %[^,],%[^\n]", c[n].name, c[n].phone) == 2 && n < MAX) n++;
    fclose(f);
    return n;
}

void printContacts(Contact c[], int n, char filter) {
    int found = 0, s = 1;
    for (int i = 0; i < n; i++) {
        char ch = c[i].name[0];
        if (!filter || ch == filter || ch == (filter ^ 32)) {
            printf("%d. Name : %s\n   Phone: %s\n\n", s++, c[i].name, c[i].phone);
            found = 1;
        }
    }
    if (filter && !found) printf("No contacts found starting with '%c'\n", filter);
}

int main() {
    int opt;
    Contact book[MAX];

    do {
        printf("\n1. Add\n2. List All\n3. List by Letter\n4. Exit\nChoice: ");
        scanf("%d", &opt);

        if (opt == 1) addContact();
        else if (opt == 2 || opt == 3) {
            int n = loadContacts(book);
            char letter = 0;
            if (opt == 3) {
                printf("Enter letter: ");
                scanf(" %c", &letter);
            }
            printContacts(book, n, letter);
        } else if (opt != 4) printf("Invalid option.\n");
    } while (opt != 4);

    return 0;
}
