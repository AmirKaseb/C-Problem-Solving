#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define maxn 20

char ch[maxn];

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%s", ch + 1) != EOF) {
        if (strlen(ch + 1) != 12) {
            printf("Invalid input format. Each line should contain exactly 12 characters.\n");
            continue;
        }

        bool flag = false;

        for (int i = 1; i <= 6; i++) {
            int k;
            if (i == 1)
                k = 6;
            else if (i == 2)
                k = 5;
            else if (i == 3)
                k = 4;
            else if (i == 4)
                k = 3;
            else if (i == 5)
                k = 2;
            else if (i == 6)
                k = 1;

            if (ch[i] == 'A')
                continue;

            char now1, now2;
            now1 = ch[i];
            now2 = ch[k];
            ch[i] = 'A', ch[k] = 'A';
            flag = false;

            for (int j = 7; j <= 12; j++) {
                if (ch[j] == now1) {
                    if (j == 7 && now2 == ch[12]) {
                        ch[7] = ch[12] = 'A';
                        flag = true;
                    } else if (j == 8 && now2 == ch[11]) {
                        flag = true;
                        ch[8] = ch[11] = 'A';
                    } else if (j == 9 && now2 == ch[10]) {
                        flag = true;
                        ch[9] = ch[10] = 'A';
                    } else if (j == 10 && now2 == ch[9]) {
                        flag = true;
                        ch[10] = ch[9] = 'A';
                    } else if (j == 11 && now2 == ch[8]) {
                        flag = true;
                        ch[8] = ch[11] = 'A';
                    } else if (j == 12 && now2 == ch[7]) {
                        flag = true;
                        ch[7] = ch[12] = 'A';
                    }
                }
                if (flag)
                    break;
            }

            if (!flag) {
                fprintf(outputFile, "FALSE\n");
                break;
            }
        }

        if (!flag)
            continue;
        else
            fprintf(outputFile, "TRUE\n");
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
