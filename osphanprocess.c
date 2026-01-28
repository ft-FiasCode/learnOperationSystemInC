#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        sleep(5);
        printf("Orphan Child PID: %d, New Parent PID: %d\n", getpid(), getppid());
    } else {
        printf("Parent exiting...\n");
    }

    return 0;
}

