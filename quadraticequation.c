#include <math.h>
#include <stdio.h>

int main() {
    float a, b, c;
    float x1;
    
    printf("Enter the a value: ");
    scanf("%f", &a); 
    printf("Enter the b value: ");
    scanf("%f", &b);  
    printf("Enter the c value: ");
    scanf("%f", &c);  
    
    float d = b*b - 4*a*c;
    
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2*a);
        printf("x1: %.2f\n", x1);  
    }
    
    return 0;
}