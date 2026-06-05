#include <stdio.h>
#include <string.h>

int main()
{
    FILE *master;
    FILE *person;

    char name[50];
    char about[200];
    char email[100];
    char filename[60];
    long long phone;

    printf("What is your name: ");
    fgets(name, sizeof(name), stdin);

    /* Remove newline from name */
    name[strcspn(name, "\n")] = '\0';

    printf("Tell me about yourself: ");
    fgets(about, sizeof(about), stdin);

    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);

    printf("Enter your phone number: ");
    scanf("%lld", &phone);

    /* Create personal file name */
    sprintf(filename, "%s.txt", name);

    /* Open master file */
    master = fopen("master_details.txt", "a");

    if(master == NULL)
    {
        printf("Master file not opened\n");
        return 1;
    }

    /* Open personal file */
    person = fopen(filename, "w");

    if(person == NULL)
    {
        printf("Personal file not opened\n");
        fclose(master);
        return 1;
    }

    /* Save only name and file name in master file */
    fprintf(master, "%s - %s\n", name, filename);

    /* Save full details in personal file */
    fprintf(person, "Name: %s\n", name);
    fprintf(person, "About: %s", about);
    fprintf(person, "Email: %s", email);
    fprintf(person, "Phone Number: %lld\n", phone);

    fclose(master);
    fclose(person);

    printf("\nDetails saved successfully.\n");
    printf("Master File   : master_details.txt\n");
    printf("Personal File : %s\n", filename);

    return 0;
}
