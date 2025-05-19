#include <stdio.h>
#include <string.h>

int main() {
    char name[100]; 
  
    printf("Enter your name: ");
    scanf("%s", name);
    

    int length = strlen(name);  
    
    printf("Reversed name: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", name[i]);
    }
    printf("\n");

    return 0;
}
