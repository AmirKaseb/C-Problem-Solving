#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_N 1005
int n, l, c, v;
int topics[MAX_N];
// state: idx = {num lecture, DI}
struct pair {
    int first, second;};
struct pair memo[MAX_N];
struct pair solve(int idx) {
    if(idx == n) return (struct pair){0,0};
    if(memo[idx].first != -1) return memo[idx];
    int min_lec = INT_MAX;
    int min_DI = INT_MAX;
    int time_left = l;
    for(int i=idx;i<n;i++){
        time_left -= topics[i];
        if(time_left < 0) break;
        int di = 0;
        if(time_left==0) di = 0;
        else if(time_left<=10) di = -c;
        else di = (time_left-10)*(time_left-10);
        struct pair sub_res = solve(i+1);
        int lec_needed = sub_res.first+1;
        di += sub_res.second;
        if(lec_needed < min_lec) {
            min_lec = lec_needed;
            min_DI = di;
        } else if(min_lec == lec_needed) {
            min_DI = (di < min_DI) ? di : min_DI;}}
    return memo[idx] = (struct pair){min_lec, min_DI};}
int main() {
    int tc=1;
    while(scanf("%d",&n),n){
        if(tc>1) printf("\n");
        scanf("%d %d",&l,&c);
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            topics[i] = v;
            memo[i].first = -1;
            memo[i].second = -1;}
        struct pair res = solve(0);
        printf("Case %d:\n",tc++);
        printf("Minimum number of lectures: %d\n", res.first);
        printf("Total dissatisfaction index: %d\n", res.second);}
    return 0;}
