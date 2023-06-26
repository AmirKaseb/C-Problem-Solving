#include <stdio.h>
#include <string.h>

int main()
{
    char grid[10][10];
    int a[10][10];
    int r, c;
    int i, j, kase = 0, num, word, k;

    while (scanf("%d", &r) && r)
    {
        scanf("%d", &c);
        kase++;
        num = 0;
        memset(a, 0, sizeof(a));
        getchar(); // Read and discard the newline character

        for (i = 0; i < r; i++) // Input grid content and assign sequence numbers to the starting cells
        {
            for (j = 0; j < c; j++)
            {
                grid[i][j] = getchar();

                if (grid[i][j] != '*' && (i == 0 || j == 0))
                    a[i][j] = (++num);
                else if (grid[i][j] != '*' && (grid[i - 1][j] == '*' || grid[i][j - 1] == '*'))
                    a[i][j] = (++num);
            }
            getchar(); // Read and discard the newline character
        }

        word = 0; // Flag to check if currently reading a word

        if (kase - 1)
            printf("\n");

        printf("puzzle #%d:\n", kase);
        printf("Across\n");

        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (!word && grid[i][j] != '*') // If currently not reading a word and encounter a word
                {
                    word = 1;
                    printf("%3d.", a[i][j]);
                    printf("%c", grid[i][j]);

                    if (j == c - 1)
                    {
                        word = 0;
                        printf("\n");
                    }
                }
                else if (word && grid[i][j] == '*')
                {
                    word = 0;
                    printf("\n");
                }
                else if (word && grid[i][j] != '*')
                {
                    printf("%c", grid[i][j]);

                    if (j == c - 1)
                    {
                        word = 0;
                        printf("\n");
                    }
                }
            }
        }

        printf("Down\n");
        word = 0;

        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if ((i == 0 || grid[i - 1][j] == '*') && grid[i][j] != '*') // Starting cell
                {
                    word = 1;

                    if (a[i][j])
                        printf("%3d.", a[i][j]);

                    for (k = 0; k < r - i && grid[i + k][j] != '*'; k++)
                    {
                        printf("%c", grid[i + k][j]);
                    }

                    if (k == r - i || grid[i + k][j] == '*')
                        printf("\n");
                }
            }
        }
    }

    return 0;
}
