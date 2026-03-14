#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* convert string to lowercase */
void toLower(char *str)
{
    for(int i=0; str[i]; i++)
        str[i]=tolower(str[i]);
}

/* ADD CONTACT */
void addContact()
{
    FILE *fp;
    char name[100],dob[20],place[100];

    fp=fopen("5000data.txt","a");
    if(fp==NULL)
    {
        printf("File error\n");
        return;
    }

    printf("\nEnter Name: ");
    scanf(" %[^\n]",name);

    printf("Enter DOB (YYYY-MM-DD): ");
    scanf("%s",dob);

    printf("Enter Place: ");
    scanf(" %[^\n]",place);

    fprintf(fp,"%s,%s,%s\n",name,dob,place);

    fclose(fp);
    printf("Contact added successfully!\n");
}

/* VIEW CONTACTS */
void viewContacts()
{
    FILE *fp;
    char line[300];
    char name[100],dob[20],place[100];

    fp=fopen("5000data.txt","r");
    if(fp==NULL)
    {
        printf("No contacts found!\n");
        return;
    }

    /* move pointer to beginning */
    fseek(fp,0,SEEK_SET);

    printf("\n%-25s %-15s %-20s\n","NAME","DOB","PLACE");
    printf("-------------------------------------------------------------\n");

    while(fgets(line,sizeof(line),fp))
    {
        if(sscanf(line,"%[^,],%[^,],%[^\n]",name,dob,place)==3)
            printf("%-25s %-15s %-20s\n",name,dob,place);
    }

    fclose(fp);
}

/* FIND CONTACT */
void findContact()
{
    FILE *fp;
    char line[300];
    char name[100],dob[20],place[100];
    char search[100],temp[100];
    int found=0;

    printf("\nEnter starting letters: ");
    scanf(" %[^\n]",search);
    toLower(search);

    fp=fopen("5000data.txt","r");
    if(fp==NULL)
    {
        printf("No contacts found!\n");
        return;
    }

    /* move pointer to beginning */
    fseek(fp,0,SEEK_SET);

    printf("\n%-25s %-15s %-20s\n","NAME","DOB","PLACE");
    printf("-------------------------------------------------------------\n");

    while(fgets(line,sizeof(line),fp))
    {
        if(sscanf(line,"%[^,],%[^,],%[^\n]",name,dob,place)==3)
        {
            strcpy(temp,name);
            toLower(temp);

            if(strncmp(temp,search,strlen(search))==0)
            {
                printf("%-25s %-15s %-20s\n",name,dob,place);
                found=1;
            }
        }
    }

    if(!found)
        printf("No matching contact found\n");

    fclose(fp);
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- CONTACT DATABASE SYSTEM ---\n");
        printf("1.Add Contact\n");
        printf("2.View Contacts\n");
        printf("3.Find Contact\n");
        printf("4.Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: findContact(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}