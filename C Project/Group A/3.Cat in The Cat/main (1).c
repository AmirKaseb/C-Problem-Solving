#include <stdio.h>
#include <math.h>
int main(void) {
    int intialh, workers;
    while (scanf("%d %d", &intialh, &workers) == 2) {
        if (!intialh && !workers)
            break;
        int N,notwork, sumheight;
            for (N = 1; N < intialh; N++) {
                if (fabs(log(intialh) * log(N) - log(workers) * log(N + 1)) < 1e-8)
                break;}

            notwork = (workers - 1) / (N - 1);
            sumheight = (N + 1) * intialh - workers * N;
        printf("%d %d\n", notwork, sumheight);
    }}
