#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    
    printf("Parent process (PID: %d) starting...\n", getpid());
    
    pid = fork();  // Create child process
    
    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("CHILD: I am the child process.\n");
        printf("CHILD: My PID is %d\n", getpid());
        printf("CHILD: My Parent PID (PPID) is %d\n", getppid());
    }
    else {
        // Parent process
        printf("PARENT: I am the parent process.\n");
        printf("PARENT: My PID is %d\n", getpid());
        printf("PARENT: Child PID is %d\n", pid);
        
        // Wait for child to complete
        int status;
        waitpid(pid, &status, 0);
        printf("PARENT: Child %d finished with status %d\n", pid, status);
    }
    
    return 0;
}
