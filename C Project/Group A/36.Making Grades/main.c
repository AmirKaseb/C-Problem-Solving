#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    scanf("%d", &n);

    printf("MAKING THE GRADE OUTPUT\n");
    while (n--) {
        int people;
        int testsNumber;
        scanf("%d %d", &people, &testsNumber);

        double mean = 0.0;
        int bonus[people];
        double avg[people];
        int absences[people];
        int testResult[testsNumber];

        for (int i = 0; i < people; ++i) {
            for (int j = 0; j < testsNumber; ++j)
                scanf("%d", &testResult[j]);

            scanf("%d %d", &bonus[i], &absences[i]);

            for (int j = 0; j < testsNumber; ++j) {
                for (int k = j + 1; k < testsNumber; ++k) {
                    if (testResult[k] < testResult[j]) {
                        int temp = testResult[k];
                        testResult[k] = testResult[j];
                        testResult[j] = temp;
                    }
                }
            }

            int s = 0;
            avg[i] = 0;

            if (testsNumber > 2)
                s = 1;

            for (int j = s; j < testsNumber; ++j)
                avg[i] += testResult[j];

            avg[i] /= (testsNumber - s);
            avg[i] = floor(avg[i]);
            mean += avg[i];
        }

        mean /= people;
        double standardDesviation = 0.0;

        for (int i = 0; i < people; ++i)
            standardDesviation += (avg[i] - mean) * (avg[i] - mean);

        standardDesviation = sqrt(standardDesviation / people);

        if (standardDesviation < 1.0)
            standardDesviation = 1.0;

        for (int i = 0; i < people; ++i)
            avg[i] += (bonus[i] / 2) * 3;

        int grade[people];

        for (int i = 0; i < people; ++i) {
            if (avg[i] >= mean + standardDesviation)
                grade[i] = 0.0;
            else if (avg[i] >= mean)
                grade[i] = 1.0;
            else if (avg[i] >= mean - standardDesviation)
                grade[i] = 2.0;
            else
                grade[i] = 3.0;
        }

        double avgGrade = 0.0;

        for (int i = 0; i < people; ++i) {
            if (!absences[i])
                --grade[i];
            else
                grade[i] += absences[i] / 4.0;


            grade[i] = (int)fmin(fmax(grade[i], 0), 4);

            avgGrade += 4 - grade[i];
        }

        printf("%.1f\n", avgGrade / people);
    }

    printf("END OF OUTPUT\n");

    return 0;
}
