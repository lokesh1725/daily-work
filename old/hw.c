#include <stdio.h>

int main() {
    char n[100], c;
    int l = 0, p;
    
    printf("Name: ");

    scanf("%99[^\n]", n);

    while (n[l]) l++;
    
    printf("Len:%d\nRev:", l);
    for (p = l; p--; ) putchar(n[p]);
    
    printf("\nPos(1-%d):", l);
    scanf("%d", &p);

    printf("Letter:%c\n", p>0&&p<=l?n[p-1]:'?');
    
    printf("Find:");

    scanf(" %c", &c);
    printf("'%c' at:", c);
    
    for (p = 0; p < l; p++)
        
    return 0;
}