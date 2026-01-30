#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child terminated.\n");
    } else {
        sleep(10);
        printf("Parent still alive.\n");
    }

    return 0;
}

##Run ps aux | grep Z to see zombie state.#
