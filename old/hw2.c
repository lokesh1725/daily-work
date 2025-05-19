#include <stdio.h>
#include <ctype.h>

int main() {
    char n[100], c;
    int l = 0, s, e;
    
    printf("Name: ");
    scanf("%99[^\n]", n);
    while (n[l]) l++;
    
    printf("Length: %d\nReversed: ", l);
    for (int i = l; i--; ) putchar(n[i]);

    printf("\nStart(1-%d):\n", l); scanf("%d", &s);
    printf("End(%d-%d):\n", s, l); scanf("%d", &e);

    printf(s>0&&e<=l&&s<=e?"\nLetters %d-%d: ":"\nInvalid!",s,e);
    for (int i = s-1; i < e && i < l; i++) putchar(n[i]);

    printf("\nFind:\n"); scanf(" %c", &c);
    printf("'%c' at:", tolower(c));
    for (int i = 0; i < l; i++)
        tolower(n[i]) == tolower(c) && printf("%d ", i+1);
    
    return 0;
} 