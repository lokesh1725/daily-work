#include <stdio.h>

int main() {
    int num, i, limit;
    

    

     printf("Enter a number: ");
     scanf("%d", &num);
   
    printf("Enter the limit for the table: ");
    scanf("%d", &limit);

    
    for (i = 1; i <= limit; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
        
    }

    return 0;
}
