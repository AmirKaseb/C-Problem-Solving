#include <stdio.h>
#include <string.h>

#define LENGTH 60

int decimal_num(char*);
void multiplication(int*, int*, int, int);

int main()
{
    int a, b, i, result;
    char first_number[LENGTH];
    char sec_number[LENGTH];
    int power_of_2[LENGTH];
    int multiplicand[LENGTH];

    printf("Enter the first number: \n");
    fgets(first_number, LENGTH, stdin);
    a = decimal_num(first_number);

    printf("Enter the second number: \n");
    fgets(sec_number, LENGTH, stdin);
    b = decimal_num(sec_number);

    result = a * b;

    power_of_2[0] = 1;
    multiplicand[0] = a;
    multiplication(power_of_2, multiplicand, b, result);

    return 0;
}

void multiplication(int *power_of_2, int *multiplicand, int x, int result)
{
    int i, j, temp, test;

    for (int i = 0; power_of_2[i] <= x; i++)
    {
        power_of_2[i + 1] = power_of_2[i] * 2;
        if (power_of_2[i + 1] > x)
        {
            power_of_2[i + 1] = 0;
            break;
        }
    }

    for (int i = 0; i < LENGTH; i++)
    {
        if (power_of_2[i] == 0)
        {
            break;
        }
        multiplicand[i] = multiplicand[0] * power_of_2[i];
    }

    printf("The steps:\n");
    for (i = 0; power_of_2[i] != 0; i++)
    {
        test = 0;
        temp = power_of_2[i];

        for (j = 0; j < (temp % 10); j++)
        {
            printf("|");
            test++;
        }
        printf(" ");
        temp /= 10;
        if (temp != 0)
        {
            for (j = 0; j < (temp % 10); j++)
            {
                test++;
                printf("n");
            }
            printf(" ");
            test++;
        }
        temp /= 10;
        if (temp != 0)
        {
            for (j = 0; j < (temp % 10); j++)
            {
                test++;
                printf("9");
            }
            printf(" ");
            test++;
        }
        temp /= 10;
        if (temp != 0)
        {
            for (j = 0; j < (temp % 10); j++)
            {
                test++;
                printf("8");
            }
            printf(" ");
            test++;
        }
        temp /= 10;
        if (temp != 0)
        {
            for (j = 0; j < (temp % 10); j++)
            {
                test++;
                printf("r");
            }
            printf(" ");
            test++;
        }
        if (x % 2 == 1)
        {
            printf("*");
            test += 2;
            x /= 2;
        }
        else
        {
            x /= 2;
            test++;
        }

        for (j = test; j < 34; j++)
        {
            printf(" ");
        }

        temp = multiplicand[i];

        for (j = 0; j < (multiplicand[i]) % 10; j++)
        {
            printf("|");
        }
        printf(" ");
        temp /= 10;
        if (temp != 0)
        {
            for (j = 0; j < (temp % 10); j++)
            {
                printf("n");
            }
            printf(" ");
        }
        temp /= 10;
        if (temp != 0)
        {
            for (j = 0; j < (temp % 10); j++)
            {
                printf("9");
            }
            printf(" ");
        }
        temp /= 10;
        if (temp != 0)
        {
            for (j = 0; j < (temp % 10); j++)
            {
                printf("8");
            }
            printf(" ");
        }
        temp /= 10;
        if (temp != 0)
        {
            for (j = 0; j < (temp % 10); j++)
            {
                printf("r");
            }
            printf(" ");
        }

        printf("\n");
    }

    temp = result;
    printf("The solution is: ");
    for (i = 0; i < (temp % 10); i++)
    {
        printf("|");
    }
    if (i != 0)
    {
        printf(" ");
    }
    temp /= 10;
    for (i = 0; i < (temp % 10); i++)
    {
        printf("n");
    }
    if (i != 0)
    {
        printf(" ");
    }
    temp /= 10;
    for (i = 0; i < (temp % 10); i++)
    {
        printf("9");
    }
    if (i != 0)
    {
        printf(" ");
    }
    temp /= 10;
    for (i = 0; i < (temp % 10); i++)
    {
        printf("8");
    }
    if (i != 0)
    {
        printf(" ");
    }
    temp /= 10;
    for (i = 0; i < (temp % 10); i++)
    {
        printf("r");
    }

    printf("\n");
}

int decimal_num(char *first_number)
{
    int ones = 0, tens = 0, hundreds = 0, thousands = 0, ten_thousands = 0, num = 0;
    for (int i = 0; i < LENGTH; i++)
    {
        if (first_number[i] == '|')
        {
            ones++;
        }
        else if (first_number[i] == 'n')
        {
            tens += 10;
        }
        else if (first_number[i] == '9')
        {
            hundreds += 100;
        }
        else if (first_number[i] == '8')
        {
            thousands += 1000;
        }
        else if (first_number[i] == 'r')
        {
            ten_thousands += 10000;
        }
        num = ones + tens + hundreds + thousands + ten_thousands;
    }
    return num;
}
