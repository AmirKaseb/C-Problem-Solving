#include <stdio.h>
#include <stdlib.h>

struct IDnumber // Store the student's state
{
    int num;
    int sum;
};

struct IDnumber queStudents[10000];
int front = 0;
int rear = 0;

void initial(int N)
{
    for (int i = 0; i < N; i++)
    {
        queStudents[i].num = i + 1;
        queStudents[i].sum = 0;
    }
    rear = N;
}

void payStudents(int N, int k)
{
    int m = 1, flag = 0;
    struct IDnumber id;
    for (int i = 1; i <= k; i++)
    {
        if (front < rear)
            id = queStudents[front]; // Get the object at the front of the queue
        else
            break;
        if (flag == 0)
            m = i;
        if (id.sum + m <= 40) // If the sum is less than 40
        {
            id.sum += m; // Reset the student's amount
            flag = 0;
        }
        else if (id.sum + m > 40) // If the sum is greater than 40
        {
            m -= 40 - id.sum; // m is the remaining amount
            id.sum = 40;      // Reset the student's amount to 40
            flag = 1;         // Set flag to 1
            i--;              // Stop the ATM from working
        }
        front++;
        if (id.sum < 40)
            queStudents[rear++] = id; // If the amount is less than 40, add the student back to the end of the queue
        else
            printf("%3d", id.num); // Output the number with a width of 3 characters
        if (i == k)
            i = 0; // The ATM starts giving money from 1 again
    }
}

int main()
{
    int N, k;

    while (scanf("%d %d", &N, &k) == 2)
    {
        if (N == 0 && k == 0)
            break;
        initial(N);
        payStudents(N, k);
        printf("\n");
    }

    return 0;
}
