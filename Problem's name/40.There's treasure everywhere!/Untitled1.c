#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct _point
{
    double x, y;
};

int main()
{
    int ttt = 0;
    char s[300];
    while (1)
    {
        ttt++;
        double s2 = sqrt(2.0);
        struct _point p;
        p.x = p.y = 0.0;
        char ch;
        ch = getchar();
        if (ch == 'E')
        {
            fgets(s, sizeof(s), stdin);
            break;
        }
        while (ch != '.')
        {
            double tmp = 0.0;
            while (isdigit(ch))
            {
                tmp = tmp * 10.0;
                tmp += ch - '0';
                ch = getchar();
            }

            char d[3] = "";
            int index = 0;
            d[index++] = ch;
            while (isalpha(ch = getchar()))
                d[index++] = ch;
            d[index] = '\0';
            if (strcmp(d, "N") == 0)
                p.y += tmp;
            else if (strcmp(d, "E") == 0)
                p.x += tmp;
            else if (strcmp(d, "W") == 0)
                p.x -= tmp;
            else if (strcmp(d, "S") == 0)
                p.y -= tmp;
            else if (strcmp(d, "NE") == 0)
                p.x += tmp / s2, p.y += tmp / s2;
            else if (strcmp(d, "SE") == 0)
                p.x += tmp / s2, p.y -= tmp / s2;
            else if (strcmp(d, "SW") == 0)
                p.x -= tmp / s2, p.y -= tmp / s2;
            else if (strcmp(d, "NW") == 0)
                p.x -= tmp / s2, p.y += tmp / s2;
        }
        getchar();
        double res = p.x * p.x + p.y * p.y;
        res = sqrt(res);
        printf("Map #%d\nThe treasure is located at (%.3f,%.3f).\n", ttt, p.x, p.y);
        printf("The distance to the treasure is %.3f.\n\n", res);
    }
    return 0;
}
