#include <stdio.h>

int main() {
    int num, a , b , i;
    int mod;
    
    printf("Enter the number a: ");
    scanf("%d", &a);
    
    printf("Enter  number b: ");
    scanf("%d", &b);

    mod= a%b;
    printf("mod: %d mod %d = %d\n" , a , b  , mod);
   
    return 0;
}