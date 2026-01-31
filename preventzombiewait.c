#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child terminated.\n");
    } else {
        wait(NULL);
        printf("Child cleaned, no zombie.\n");
    }

    return 0;
}

