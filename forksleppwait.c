#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process running...\n");
        sleep(3);
        printf("Child process finished.\n");
    } else {
        // Parent process
        printf("Parent waiting for child...\n");
        wait(NULL);
        printf("Child terminated, parent continues.\n");
    }

    return 0;
}

