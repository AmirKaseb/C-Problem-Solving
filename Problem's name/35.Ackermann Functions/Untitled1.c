#include <stdio.h>

long ackermann(long n) {
    long counter = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        counter++;
    }
    return counter;
}

int main() {
    long L, H;
    scanf("%ld %ld", &L, &H);

    while (L != 0 && H != 0) {
        long maxSequence = -1;
        long maxNumber = -1;

        for (long i = L; i <= H; i++) {
            long sequenceLength = ackermann(i);
            if (sequenceLength > maxSequence) {
                maxSequence = sequenceLength;
                maxNumber = i;
            }
        }

        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n", L, H, maxNumber, maxSequence - 1);

        scanf("%ld %ld", &L, &H);
    }

    return 0;
}
