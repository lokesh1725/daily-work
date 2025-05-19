# include <stdio.h>
int main(){
    int num ,a,b ,i;
    printf("enter the number a:");
    scanf("%d" , &a);
    printf("enter the number b:");
    scanf("%d", &b);
    for (i = 1; i<=20; i++){
        int result = a*i;
        if (result % b!=0){
            printf("%d * %d = %d\n", a ,i ,result );

        }
    }
   return 0;
}