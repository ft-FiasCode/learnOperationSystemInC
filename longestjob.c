#include <stdio.h>

int main() {
    int n, i, j;
    int bt[10], p[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] < bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}

