#include <stdio.h>
#include <time.h>

int main() {
    float amount, annual_rate;
    int term;
    
  
    printf("Enter loan amount: ");
    scanf("%f", &amount);
    
    printf("Enter loan term (months): ");
    scanf("%d", &term);
    
    printf("Enter annual interest rate (e.g., 0.15 for 15%%): ");
    scanf("%f", &annual_rate);

   
    time_t now = time(NULL);
    struct tm *current_date = localtime(&now);
    int year = current_date->tm_year + 1900;
    
    
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
   
    int day = 15;

  
    float monthly_rate = annual_rate / 12;
    float monthly_interest = monthly_rate * amount;  
    float monthly_principal = amount / term;       
    float monthly_emi = monthly_principal + monthly_interest;

    float total_principal = 0;
    float total_interest = 0;
    float total_emi = 0;

    printf("\nDate\t\tPrincipal\tInterest\tEMI\n");

    for (int month = 0; month < term; month++) {
        int current_month = month % 12;
        
       
        printf("%s %d, %d\t", months[current_month], day, year);
        
       
        printf("%.2f\t\t%.2f\t\t%.2f\n", monthly_principal, monthly_interest, monthly_emi);
      
        total_principal += monthly_principal;
        total_interest += monthly_interest;
        total_emi += monthly_emi;
        
       
        if (current_month == 11) {
            year++;
        }
    }

    printf("\nTotal Principal = %.2f", total_principal);
    printf("\nTotal Interest  = %.2f", total_interest);
    printf("\nFinal Amount (Total EMI) = %.2f\n", total_emi);

    return 0;
}