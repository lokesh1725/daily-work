#include <stdio.h>

int main()
{
    FILE *fp;
    char name[50];
    char about[200];
    char email[100];
    long long phone;

    fp = fopen("details.txt", "w");

    if(fp == NULL)
    {
        printf("File not opened\n");
        return 1;
    }

    printf("What is your name : ");
    fgets(name, sizeof(name), stdin);

    printf("Tell me about yourself: ");
    fgets(about, sizeof(about), stdin);

    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);

    printf("Enter your phone number: ");
    scanf("%lld", &phone);

    fprintf(fp, "Name: %s", name);
    fprintf(fp, "About: %s", about);
    fprintf(fp, "Email: %s", email);
    fprintf(fp, "Phone Number: %lld\n", phone);

    fclose(fp);

    printf("Details saved successfully in details.txt\n");

    return 0;
}