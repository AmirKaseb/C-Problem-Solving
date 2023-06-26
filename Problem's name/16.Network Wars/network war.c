#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MEM(a, b) memset((a), (b), sizeof(a))
#define INF 1000000007
#define N 210

int a[30][30];
int vis[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char str[1000];
    while (scanf("%s", str) != EOF) {
        if (strcmp(str, "W") == 0) {
            break;
        }

        char c1, c2;
        scanf(" %c %c", &c1, &c2);

        int p = c1 - 'A';
        int l = c2 - 'A';
        MEM(a, 0);

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == ';') {
                str[i] = ' ';
            }
            if (str[i] == '.') {
                str[i] = ' ';
            }
        }

        char tmp[10];
        char *token = strtok(str, " ");
        while (token != NULL) {
            if (strlen(token) > 1) {
                int x = token[0] - 'A';
                for (int j = 2; j < strlen(token); j++) {
                    int y = token[j] - 'A';
                    a[x][y] = a[y][x] = 1;
                }
            }
            token = strtok(NULL, " ");
        }

        if (p == l) {
            printf("Both annihilated in node %c\n", p + 'A');
        }
        else {
            MEM(vis, 0);
            vis[p] = 1;
            vis[l] = 2;
            while (1) {
                bool flag1 = true;
                bool flag2 = true;
                for (int i = 0; i < 26; i++) {
                    int x = (i + p) % 26;
                    if (vis[x]) {
                        continue;
                    }
                    if (a[p][x] == 0) {
                        continue;
                    }
                    vis[x] = 1;
                    flag1 = false;
                    p = x;
                    break;
                }
                char key[100] = " ";
                if (flag1) {
                    printf("Paskill trapped in node %c", p + 'A');
                }
                for (int i = 0; i < 26; i++) {
                    int x = (l - i + 26) % 26;
                    if (a[l][x] && vis[x] != 2) {
                        l = x;
                        flag2 = false;
                        if (vis[x] == 1) {
                            flag2 = true;
                        }
                        vis[x] = 2;
                        break;
                    }
                }
                if (p == l) {
                    sprintf(key, "%sBoth annihilated in node %c", key, l + 'A');
                    printf("%s\n", key);
                    break;
                }
                if (flag2) {
                    sprintf(key, "%sLisper trapped in node %c", key, l + 'A');
                    printf("%s\n", key);
                    break;
                }
                if (flag1 && flag2) {
                    sprintf(key, "%sLisper destroyed in node %c", key, l + 'A');
                    printf("%s\n", key);
                    break;
                }
            }
        }
    }
    return 0;
}
