#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();   // First fork

    if (pid1 == 0) {
        // First child
        printf("First Child: PID = %d, Parent PID = %d\n", getpid(), getppid());

        pid2 = fork();  // Second fork inside child

        if (pid2 == 0) {
            // Second child
            printf("Second Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        } else {
            printf("Parent of Second Child: Child PID = %d\n", pid2);
        }
    } else {
        // Original parent
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid1);
    }

    return 0;
}

