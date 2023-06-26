#include <stdio.h>
#include <string.h>

#define Maxn 8

char chess[Maxn + 5][Maxn + 5];
char Nowcolor;
char opcolor[100];
int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int Countcol(char color) {
    int sum = 0;
    for (int i = 1; i <= Maxn; i++)
        for (int j = 1; j <= Maxn; j++)
            sum += (chess[i][j] == color);
    return sum;
}

int Canplace(int x, int y, int dirx, int diry) {
    int findopcolor = 0;
    for (int i = x + dirx, j = y + diry; i >= 1 && i <= Maxn && j >= 1 && j <= Maxn; i += dirx, j += diry) {
        if (chess[i][j] == '-')
            return 0;
        else if (chess[i][j] == opcolor[Nowcolor]) {
            findopcolor = 1;
        } else if (chess[i][j] == Nowcolor) {
            if (findopcolor)
                return 1;
            else
                return 0;
        }
    }
    return 0;
}

int CanplaceMove(int x, int y) {
    for (int i = 0; i < 8; i++)
        if (Canplace(x, y, dx[i], dy[i]))
            return 1;
    return 0;
}

void List() {
    int first = 1;
    for (int i = 1; i <= Maxn; i++)
        for (int j = 1; j <= Maxn; j++)
            if (chess[i][j] == '-' && CanplaceMove(i, j)) {
                if (first) {
                    first = 0;
                    printf("(%d,%d)", i, j);
                } else
                    printf(" (%d,%d)", i, j);
            }
    if (first == 1)
        printf("No legal move.\n");
    else
        printf("\n");
}

void Change(int x, int y, int dirx, int diry) {
    int flag = 0;
    for (int i = x + dirx, j = y + diry; i >= 1 && i <= Maxn && j >= 1 && j <= Maxn; i += dirx, j += diry) {
        if (chess[i][j] == '-')
            return;
        else if (chess[i][j] == Nowcolor) {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return;
    for (int i = x + dirx, j = y + diry; i >= 1 && i <= Maxn && j >= 1 && j <= Maxn; i += dirx, j += diry) {
        if (chess[i][j] == opcolor[Nowcolor]) {
            chess[i][j] = Nowcolor;
        } else if (chess[i][j] == Nowcolor)
            break;
    }
    return;
}

void Move(int x, int y) {
    chess[x][y] = Nowcolor;
    for (int i = 0; i < 8; i++)
        Change(x, y, dx[i], dy[i]);
    printf("Black -%3d White -%3d\n", Countcol('B'), Countcol('W'));
}

void Print() {
    for (int i = 1; i <= Maxn; i++) {
        printf("%s\n", chess[i] + 1);
    }
}

int main() {
    opcolor['B'] = 'W';
    opcolor['W'] = 'B';
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= Maxn; i++)
            scanf("%s", chess[i] + 1);
        scanf(" %c", &Nowcolor);
        char s[5];
        while (1) {
            scanf("%s", s);
            if (s[0] == 'L')
                List();
            else if (s[0] == 'M') {
                if (CanplaceMove(s[1] - '0', s[2] - '0'))
                    Move(s[1] - '0', s[2] - '0');
                else {
                    Nowcolor = opcolor[Nowcolor];
                    Move(s[1] - '0', s[2] - '0');
                }
                Nowcolor = opcolor[Nowcolor];
            } else if (s[0] == 'Q') {
                Print();
                break;
            }
        }
        if (T)
            printf("\n");
    }
    return 0;
}
