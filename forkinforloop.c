#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    for (i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
            return 0;
        }
    }
    return 0;
}

