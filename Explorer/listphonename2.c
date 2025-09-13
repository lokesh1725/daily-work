#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "extra.h"




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
