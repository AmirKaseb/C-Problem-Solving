#include <stdio.h>
#include <string.h>
#include <ctype.h>


int is_valid_isbn(char *isbn) {
    int i, j, len, sum1 = 0, sum2 = 0;
    len = strlen(isbn);
    j = 1;
    for (i = 0; i < len; i++) {
        if (isbn[i] >= '0' && isbn[i] <= '9') {
            sum1 += isbn[i] - '0';
            sum2 += sum1;
            j++;
        } else if (isbn[i] == '-') {
            continue;
        } else if (isbn[i] == 'X' && i == len - 1) {
            sum1 += 10;
            sum2 += sum1;
            j++;
        } else {
            return 0;
        }
    }
    if (j != 11) {
        return 0;
    }
    if (sum2 % 11 == 0) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    char isbn[81];
    while (1) {
        printf("Enter an ISBN code: ");
        if (fgets(isbn, 81, stdin) == NULL) {
            break;//To make sure that the input of the user is completed
        }
        int len = strlen(isbn);
        while (len > 0 && isspace(isbn[len - 1])) {
            len--;
            isbn[len] = '\0';//This line removes any character that we don't need here
        }
        printf("%s ", isbn);
        if (is_valid_isbn(isbn)) {
            printf("is correct.\n");
        } else {
            printf("is incorrect.\n");
        }
    }
    return 0;
}
