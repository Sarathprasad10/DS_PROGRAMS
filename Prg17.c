//Define a structure for dates with dd/mm/yyyy. Provide functions for reading, displaying and comparing two dates are equal or not
#include <stdio.h>
struct date
{
    int day;
    int month;
    int year;
};
struct date read()
{
    struct date d;
    printf("\nEnter a date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d.day, &d.month, &d.year);
    return d;
}

int compare(struct date d1, struct date d2)
{
    int flag=0;
    if(d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
    {
        flag=1;
    }
    if(flag == 1)
    {
        printf("\n%d/%d/%d and %d/%d/%d are equal.", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    }
    else
    {
        printf("\n%d/%d/%d and %d/%d/%d are not equal.", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    }
        
    return 0;
}

int main()
{
    int dmy;
    struct date d1, d2;
    char choice;
    do
    {
        d1 = read();
        d2 = read();
        dmy = compare(d1, d2);
        printf("\nDo you want to compare more dates? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    return 0;
}


