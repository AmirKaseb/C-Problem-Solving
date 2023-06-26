#include <stdio.h>

// Function to check if a number is an ugly number
int is_ugly(int n) {
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }
    return n == 1;
}

int main() {
    int count = 1; // start with 1, which is the first ugly number
    int num = 1;
    while (count < 1500) {
        num++;
        if (is_ugly(num)) {
            count++;
        }
    }
    printf("The 1500'th ugly number is %d.\n", num);
    return 0;
}
