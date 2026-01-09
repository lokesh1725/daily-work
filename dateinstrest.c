#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
    double amount, annual_rate;
    int term;

    printf("Enter loan amount: ");
    scanf("%lf", &amount);

    printf("Enter loan term (months): ");
    scanf("%d", &term);

    printf("Enter annual interest rate (in %%): ");
    scanf("%lf", &annual_rate);

    /* Convert percentage to decimal */
    annual_rate = annual_rate / 100.0;

    time_t now = time(NULL);
    struct tm *date = localtime(&now);

    int month = date->tm_mon;
    int year  = date->tm_year + 1900;
    int day = 15;

    const char *months[] = {
        "Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"
    };

    double monthly_rate = annual_rate / 12.0;

    double emi = amount * monthly_rate * pow(1 + monthly_rate, term) /
                 (pow(1 + monthly_rate, term) - 1);

    double balance = amount;
    double total_interest = 0;

    printf("\nDate\t\tPrincipal\tInterest\tEMI\n");

    for (int i = 0; i < term; i++) {
        double interest = balance * monthly_rate;
        double principal = emi - interest;

        if (principal > balance)
            principal = balance;

        balance -= principal;
        total_interest += interest;

        printf("%s %d, %d\t%.2f\t\t%.2f\t\t%.2f\n",
               months[month], day, year,
               principal, interest, emi);

        month++;
        if (month == 12) {
            month = 0;
            year++;
        }
    }

    printf("\nTotal Interest = %.2f", total_interest);
    printf("\nTotal Payment  = %.2f\n", emi * term);

    return 0;
}
