#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2, pid3;
    
    printf("PARENT (PID: %d): Creating multiple children...\n", getpid());
    
    // First fork
    pid1 = fork();
    if (pid1 == 0) {
        // Child 1
        printf("CHILD1 (PID: %d, PPID: %d): I am child 1\n", getpid(), getppid());
        
        pid2 = fork();  // Child 1 creates Child 3
        if (pid2 == 0) {
            // Child 3 (grandchild of original parent)
            printf("CHILD3 (PID: %d, PPID: %d): I am grandchild\n", getpid(), getppid());
            sleep(1);
            printf("CHILD3: Exiting (will be orphaned soon)\n");
            exit(100);
        }
        // Child 1 exits quickly, orphaning Child 3
        sleep(2);
        printf("CHILD1: Exiting, orphaning Child3\n");
        exit(42);
    }
    
    // Second fork (only parent executes this)
    pid2 = fork();
    if (pid2 == 0) {
        // Child 2
        printf("CHILD2 (PID: %d, PPID: %d): I am child 2\n", getpid(), getppid());
        sleep(3);
        printf("CHILD2: Exiting normally\n");
        exit(84);
    }
    
    // Wait for all children
    int status;
    printf("PARENT: Waiting for children...\n");
    
    waitpid(pid1, &status, 0);
    printf("PARENT: Child1 exited with status %d\n", WEXITSTATUS(status));
    
    waitpid(pid2, &status, 0);
    printf("PARENT: Child2 exited with status %d\n", WEXITSTATUS(status));
    
    // Child3 (orphan) may still be running or finish separately
    printf("PARENT: All direct children finished\n");
    
    return 0;
}
