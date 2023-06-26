#include <stdio.h>
#include <string.h>

#define MAX 250

int n, ans;
int gra[MAX][MAX];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int vis[MAX][MAX];
char Direction[] = {'e', 'n', 's', 'w'};
int sta[30], num[] = {0, 3};

void dfs(int x, int y, int pos, int dir) {
    if (pos == n + 1) {
        if (x == 105 && y == 105) {
            ans++;
            printf("%c", Direction[sta[1]]);
            for (int i = 2; i <= n; i++) {
                printf("%c", Direction[sta[i]]);
            }
            printf("\n");
        }
        return;
    }

    int step = 0;
    for (int i = pos; i <= n; i++) {
        step += i;
    }
    if (abs(x - 105) + abs(y - 105) > step) {
        return;
    }

    if (dir == -1) {
        for (int i = 0; i < 4; i++) {
            int xx = x + pos * dx[i], yy = y + pos * dy[i];
            if (vis[xx][yy]) {
                continue;
            }
            int k;
            if (1 <= i && i < 3) {
                for (k = (y < yy ? y : yy); k <= (y < yy ? yy : y); k++) {
                    if (gra[xx][k]) {
                        break;
                    }
                }
                if (k == (y < yy ? yy + 1 : y + 1)) {
                    sta[pos] = i;
                    vis[xx][yy] = 1;
                    dfs(xx, yy, pos + 1, 1);
                    vis[xx][yy] = 0;
                }
            } else {
                for (k = (x < xx ? x : xx); k <= (x < xx ? xx : x); k++) {
                    if (gra[k][yy]) {
                        break;
                    }
                }
                if (k == (x < xx ? xx + 1 : x + 1)) {
                    sta[pos] = i;
                    vis[xx][yy] = 1;
                    dfs(xx, yy, pos + 1, 0);
                    vis[xx][yy] = 0;
                }
            }
        }
    } else {
        if (dir == 0) {
            for (int i = 1; i < 3; i++) {
                int xx = x + pos * dx[i], yy = y + pos * dy[i];
                if (vis[xx][yy]) {
                    continue;
                }
                int k;
                for (k = (y < yy ? y : yy); k <= (y < yy ? yy : y); k++) {
                    if (gra[xx][k]) {
                        break;
                    }
                }
                if (k == (y < yy ? yy + 1 : y + 1)) {
                    sta[pos] = i;
                    vis[xx][yy] = 1;
                    dfs(xx, yy, pos + 1, 1);
                    vis[xx][yy] = 0;
                }
            }
        } else if (dir == 1) {
            for (int j = 0; j < 2; j++) {
                int i = num[j];
                int xx = x + pos * dx[i], yy = y + pos * dy[i];
                if (vis[xx][yy]) {
                    continue;
                }
                int k;
                for (k = (x < xx ? x : xx); k <= (x < xx ? xx : x); k++) {
                    if (gra[k][yy]) {
                        break;
                    }
                }
                if (k == (x < xx ? xx + 1 : x + 1)) {
                    sta[pos] = i;
                    vis[xx][yy] = 1;
                    dfs(xx, yy, pos + 1, 0);
                    vis[xx][yy] = 0;
                }
            }
        }
    }
}

int main() {
    int iCase;
    scanf("%d", &iCase);
    while (iCase--) {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(gra, 0, sizeof(gra));
        int k, x, y;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &x, &y);
            if (abs(x) > 105 || abs(y) > 105) {
                continue;
            }
            gra[105 + x][105 + y] = 1;
        }
        dfs(105, 105, 1, -1);
        printf("Found %d golygon(s).\n\n", ans);
    }
    return 0;
}
