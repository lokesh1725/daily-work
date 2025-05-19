#include <stdio.h>

int main() {
    char n[100], c;
    int l = 0, start, end;
    
    printf("Name: ");
    scanf("%99[^\n]", n);

    
    while (n[l]) l++;
    
    printf("Length: %d\nReversed: ", l);
    for (int i = l; i--; ) putchar(n[i]);

    
    
    printf("\n\nEnter start position (1-%d): ", l);
    scanf("%d", &start);
    printf("Enter end position (%d-%d): ", start, l);
    scanf("%d", &end);

    
    if (start > 0 && end <= l && start <= end) {
        printf("Letters from %d to %d: ", start, end);
        for (int i = start-1; i < end; i++) {
            putchar(n[i]);
        }
    } else {
        printf("Invalid range!");
    }

   
    printf("\n\nFind letter: ");
    scanf(" %c", &c);
    printf("'%c' at positions: ", c);
    for (int i = 0; i < l; i++)
       
    
    return 0;
}