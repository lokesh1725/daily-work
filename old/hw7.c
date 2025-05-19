#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2;
    printf("Enter two integers: ");
     scanf("%d %d", &num1, &num2) != 2;
       

    printf("Addition: %d\n", num1 + num2);
    printf("Subtraction: %d\n", num1 - num2);
    printf("Multiplication: %d\n", num1 * num2);
   
        printf("Division: %.2f\n", (float)num1 / num2);
        printf("Modulus: %d\n", num1 % num2);
   
    

    return 0;
}