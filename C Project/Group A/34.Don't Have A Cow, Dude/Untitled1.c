#include <stdio.h>
#include <math.h>
#define errort 1e-8
int main() {
    double R, P;int tc;
    const double pi = 3.14159265358979323846;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%lf %lf", &R, &P);
        double l = 0, r = pi, mid, ret = 0;
        double A = R * R * pi;
        while (fabs(l - r) > errort) {
            mid = (l + r)/2;
            ret = hypot(R * cos(mid) - R, R * sin(mid));
            double theta = (pi - mid)/2;
            double area = (ret * ret * theta/2 + (R * R * mid/2 - R * R * sin(mid)/2))*2;
            if (area < A * P)
                l = mid;
            else
                r = mid;
                }
        printf("R = %.0lf, P = %.2lf, Rope = %.2lf\n", R, P, ret);}
    return 0;
}
