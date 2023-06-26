#include <stdio.h>
#include <string.h>

int val(char c) {
    if (c >= '0' && c <= '9')
        return (int)(c - '0');
    else
        return (int)(c - 'A' + 10);
}

int toDeci(char *str, int base) {
    int power = 1;
    int num = 0;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (val(str[i]) >= base) {
            return -1;
        } else {
            num += val(str[i]) * power;
            power *= base;
        }
    }
    return num;
}

void printBasePair(char *str1, char *str2, int base_x, int base_y) {
    printf("%s (base %d) = %s (base %d)\n", str1, base_x, str2, base_y);
}

void findSmallestBases(char *str1, char *str2) {
    int base_x, base_y;
    int found = 0;
    int value_x;
    int value_y;

    for (base_x = 2; base_x <= 36; base_x++) {
        value_x = toDeci(str1, base_x);
        if (value_x == -1)
            continue;

        for (base_y = 2; base_y <= 36; base_y++) {
            value_y = toDeci(str2, base_y);
            if (value_y == -1)
                continue;

            if (value_x == value_y) {
                found = 1;
                break;
            }
        }

        if (found) {
            break;
        }
    }

    if (found) {
        printBasePair(str1, str2, base_x, base_y);
    } else {
        printf("%s is not equal to %s in any base 2..36\n", str1, str2);
    }
}

int main() {
    char str1[100];
    char str2[100];

    while (scanf("%s %s", str1, str2) == 2) {
        findSmallestBases(str1, str2);
    }

    return 0;
}
