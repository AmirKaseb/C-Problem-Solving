#include <stdio.h>
#include <math.h>

int main() {
    float p1x, p1y, p2x, p2y, p3x, p3y;
    scanf("%f %f %f %f %f %f", &p1x, &p1y, &p2x, &p2y, &p3x, &p3y);

    float A = p2x - p1x;
    float B = p2y - p1y;
    float C = p3x - p1x;
    float D = p3y - p1y;
    float E = A * (p1x + p2x) + B * (p1y + p2y);
    float F = C * (p1x + p3x) + D * (p1y + p3y);
    float G = 2.0 * (A * (p3y - p2y) - B * (p3x - p2x));

    if (G == 0) {
        printf("Points are collinear. Cannot construct a circle.\n");
        return 0;
    }

    float cx = (D * E - B * F) / G;
    float cy = (A * F - C * E) / G;
    float radius = sqrt(pow(p1x - cx, 2) + pow(p1y - cy, 2));

    printf("(x - %.3f)^2 + (y + %.3f)^2 = %.3f^2\n", cx, -cy, radius);
    printf("x^2 + y^2 - %.3fx + %.3fy - %.3f = 0\n", 2.0 * cx, -2.0 * cy, pow(cx, 2) + pow(cy, 2) - pow(radius, 2));

    return 0;
}
