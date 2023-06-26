#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-6
typedef struct {
    double x, y;
} Pt;
typedef struct {
    Pt p;
    double dist, l, r;
} Interval;
int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return (intervalA->dist < intervalB->dist) ? -1 : 1;
}
Pt getLineIntersection(double a1, double b1, double c1, double a2, double b2, double c2) {
    c1 = -c1, c2 = -c2;
    double d, dx, dy;
    d = a1 * b2 - a2 * b1;
    dx = c1 * b2 - c2 * b1;
    dy = a1 * c2 - a2 * c1;
    return (Pt) { dx/d, dy/d };
}
void getTangentIntersection(Pt co, double r, Pt p, Pt *pa, Pt *pb) {
    double a, b, c;
    double m1a, m1b, m1c, m2a, m2b, m2c, m1, m2;
    a = r*r - (co.x - p.x) * (co.x - p.x);
    b = 2 * (co.x - p.x) * (co.y - p.y);
    c = r*r - (co.y - p.y) * (co.y - p.y);
    if (fabs(a) < eps) {
        m2 = (-c) / b;
        m1a = 1, m1b = 0, m1c = -(m1a * p.x + m1b * p.y);
        m2a = m2, m2b = -1, m2c = -(m2a * p.x + m2b * p.y);
    } else {
        m1 = (-b + sqrt(b*b - 4*a*c))/ (2*a);
        m2 = (-b - sqrt(b*b - 4*a*c))/ (2*a);
        m1a = m1, m1b = -1, m1c = -(m1a * p.x + m1b * p.y);
        m2a = m2, m2b = -1, m2c = -(m2a * p.x + m2b * p.y);
    }
    *pa = getLineIntersection(m1a, m1b, m1c, m1b, -m1a, -(m1b * co.x + (-m1a) * co.y));
    *pb = getLineIntersection(m2a, m2b, m2c, m2b, -m2a, -(m2b * co.x + (-m2a) * co.y));
}
int main() {
    Pt pa, pb, co = {1, 1}, p = {0, 0};
    const double pi = acos(-1);
    double diameter, radius;
    while (scanf("%lf %lf %lf", &diameter, &p.x, &p.y) == 3) {
        if (fabs(diameter) < eps)
            break;
        Interval interval[1600];
        radius = diameter / 2;
        int idx = 0;
        for (int i = -20; i < 20; i++) {
            for (int j = -20; j < 20; j++) {
                getTangentIntersection((Pt) {i, j}, radius, p, &pa, &pb);
                double t1, t2;
                t1 = atan2(pa.y - p.y, pa.x - p.x);
                t2 = atan2(pb.y - p.y, pb.x - p.x);
                if (t1 > t2) {
                    double temp = t1;
                    t1 = t2;
                    t2 = temp;
                }
                if (fabs(t1 - t2) * 180 / pi < 0.01f)
                    continue;
                interval[idx].dist = pow(pa.x - p.x, 2) + pow(pb.y - p.y, 2);
                interval[idx].l = t1;
                interval[idx].r = t2;
                interval[idx].p = (Pt) {i, j};
                idx++;
            }
        }
        qsort(interval, idx, sizeof(Interval), compare);
        int ret = 0;
        for (int i = 0; i < idx; i++) {
            double t1 = interval[i].l, t2 = interval[i].r;
            if (t2 - t1 < pi) {
                int f = 1;
                for (int j = 0; j < i; j++) {
                    double l = fmax(t1, interval[j].l), r = fmin(t2, interval[j].r);
                    if (l <= r + 0.01f * pi / 180) {
                        f = 0;
                        j = i;
                    }
                }
                ret += f;
            } else {
                double t3, t4;
                t3 = t2, t4 = pi;
                t2 = t1, t1 = -pi;
                int f = 1;
                for (int j = 0; j < i; j++) {
                    double l = fmax(t1, interval[j].l), r = fmin(t2, interval[j].r);
                    if (l <= r + 0.01f * pi / 180) {
                        f = 0;
                        j = i;
                    }
                }
                if (!f)
                    continue;
                t1 = t3, t2 = t4;
                for (int j = 0; j < i; j++) {
                    double l = fmax(t1, interval[j].l), r = fmin(t2, interval[j].r);
                    if (l <= r + 0.01f * pi / 180) {
                        f = 0;
                        j = i;
                    }
                }
                if (!f)
                    continue;
                ret += f;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
