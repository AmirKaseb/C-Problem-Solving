#include <stdio.h>

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_days_in_month(int year, int month) {
    int days_in_month[] = {31, is_leap_year(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[month-1];
}

int main() {
    int year, month, day;
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month (1:12): ");
    scanf("%d", &month);
    printf("Enter the day (1:31): ");
    scanf("%d", &day);

    int days_in_month = get_days_in_month(year, month);
    if (day > days_in_month) {
        printf("Invalid date.\n");
        return 1;
    }

    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int d = (day + y + y/4 -y/100 + y/400 + (31*m)/12) % 7;

    switch (d) {
        case 0:
            printf("Sunday, ");
            break;
        case 1:
            printf("Monday, ");
            break;
        case 2:
            printf("Tuesday, ");
            break;
        case 3:
            printf("Wednesday, ");
            break;
        case 4:
            printf("Thursday, ");
            break;
        case 5:
            printf("Friday, ");
            break;
        case 6:
            printf("Saturday, ");
            break;
    }

    printf("%d/%02d/%02d\n", year, month, day);

    return 0;
}
