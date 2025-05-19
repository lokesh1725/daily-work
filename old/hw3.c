#include <stdio.h>

int main(int argc, char** argv)
{
    int num, i;
   
    printf(" supply a number: ");
    scanf("%d", &num);

    for (i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", num, i, num * i);
       
       
    }
        
    return 0;
}
