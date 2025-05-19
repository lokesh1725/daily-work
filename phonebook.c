#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
} Contact;

Contact phonebook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phonebook is full!\n");
        return;
    }
    
    printf("Enter name: ");
    scanf(" %[^\n]", phonebook[contactCount].name);
    
    printf("Enter phone: ");
    scanf(" %[^\n]", phonebook[contactCount].phone);
    
    printf("Enter email: ");
    scanf(" %[^\n]", phonebook[contactCount].email);
    
    contactCount++;
    printf("Contact added successfully!\n");
}

void findContact() {
    char searchName[MAX_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone: %s\n", phonebook[i].phone);
            printf("Email: %s\n", phonebook[i].email);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;
    
    do {
        printf("1. Add contact\n");
        printf("2. Find contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                findContact();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}