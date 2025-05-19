#include <stdio.h>
int add(int  , int );
int sub(int , int);
int mul(int , int);
int div(int , int);

int main(int argc, char* argv[])
{
int a, b;
int choice;

printf("enter the value A:");
scanf("%d" , &a);
printf("enter the value B:");
scanf("%d", &b);

printf("\n1. Add \n");
printf("2. sub\n");
printf("3. mul\n");
printf("4. div\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
   
         switch(choice) {
            case 1:
                 add(a,  b);
                break;
            case 2:
                sub(a,b);
                break;
            case 3:
                mul(a,b);
                break;
            case 4:
                div(a,b);
                break;
            
            case 5:
            printf("Exiting\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    return 0;
}


int add (int a, int b)
{
int x=a+b;
    printf("sum of : %d" , x );
    return x;
}
int sub (int a, int b)
{
int y=a-b;
printf("difference of: %d" , y);
return y;
}
int mul (int a, int b)
{
int z=a*b;
printf("product; of: %d" , z);
return z;
}
int div (int a, int b)
{
int w=a/b;
printf("quotient of: %d" , w);
return w;
}