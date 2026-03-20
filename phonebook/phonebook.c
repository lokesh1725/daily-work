#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "5000datanum.txt"

/* convert to lowercase */
void toLower(char *s)
{
    for(int i = 0; s[i]; i++)
        s[i] = tolower(s[i]);
}

/* ensure file ends with newline */
void ensureNewLine(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    if(size > 0)
    {
        fseek(fp, -1, SEEK_END);
        char ch = fgetc(fp);
        fseek(fp, 0, SEEK_END);

        if(ch != '\n')
            fputc('\n', fp);
    }
}

/* ADD CONTACT */
void addContact()
{
    FILE *fp = fopen(FILE_NAME, "a+");
    if(!fp)
    {
        printf("File error\n");
        return;
    }

    char name[100], dob[20], place[100], phone[20];

    ensureNewLine(fp);

    printf("\nEnter Name: ");
    scanf(" %[^\n]", name);

    printf("Enter DOB (YYYY-MM-DD): ");
    scanf("%s", dob);

    printf("Enter Place: ");
    scanf(" %[^\n]", place);

    printf("Enter Phone Number: ");
    scanf("%s", phone);

    fprintf(fp, "%s,%s,%s,%s\n", name, dob, place, phone);

    fclose(fp);
    printf("Contact added successfully!\n");
}

/* HEADER */
void printHeader()
{
    printf("\n%-5s %-25s %-15s %-20s %-15s\n",
           "S.No","NAME","DOB","PLACE","NUMBER");
    printf("--------------------------------------------------------------------------------\n");
}

/* VIEW CONTACTS */
void viewContacts()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if(!fp)
    {
        printf("No contacts found!\n");
        return;
    }

    char line[300], name[100], dob[20], place[100], phone[20];
    int count = 1;

    printHeader();

    while(fgets(line, sizeof(line), fp))
    {
        if(sscanf(line,"%[^,],%[^,],%[^,],%s",name,dob,place,phone)==4)
        {
            printf("%-5d %-25s %-15s %-20s %-15s\n",
                   count++,name,dob,place,phone);
        }
    }

    fclose(fp);
}

/* FIND CONTACT */
void findContact()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if(!fp)
    {
        printf("No contacts found!\n");
        return;
    }

    char search[100], temp[100];
    char line[300], name[100], dob[20], place[100], phone[20];
    int count = 1, found = 0;

    printf("\nEnter starting letters: ");
    scanf(" %[^\n]", search);
    toLower(search);

    printHeader();

    while(fgets(line,sizeof(line),fp))
    {
        if(sscanf(line,"%[^,],%[^,],%[^,],%s",name,dob,place,phone)==4)
        {
            strcpy(temp,name);
            toLower(temp);

            if(strncmp(temp,search,strlen(search))==0)
            {
                printf("%-5d %-25s %-15s %-20s %-15s\n",
                       count++,name,dob,place,phone);
                found = 1;
            }
        }
    }

    if(!found)
        printf("No matching contact found\n");

    fclose(fp);
}

/* DELETE CONTACT */
void deleteContact()
{
    FILE *fp = fopen(FILE_NAME,"r");
    FILE *temp = fopen("temp.txt","w");

    if(!fp || !temp)
    {
        printf("File error\n");
        return;
    }

    int del, count = 1, found = 0;
    char line[300];

    printf("\nEnter Serial Number to delete: ");
    scanf("%d",&del);

    while(fgets(line,sizeof(line),fp))
    {
        if(count != del)
            fputs(line,temp);
        else
            found = 1;

        count++;
    }

    fclose(fp);
    fclose(temp);

    if(found)
    {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Contact deleted successfully!\n");
    }
    else
    {
        remove("temp.txt");
        printf("Invalid Serial Number!\n");
    }
}

/* MAIN FUNCTION */
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- CONTACT DATABASE SYSTEM ---\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Find Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: findContact(); break;
            case 4: deleteContact(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}