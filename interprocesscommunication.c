#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];  // pipefd[0] = read end, pipefd[1] = write end
    pid_t pid;
    char parent_msg[] = "Hello from PARENT process (PID: XXXXX)";
    char child_msg[] = "Hello from CHILD process (PID: XXXXX)";
    char buffer[100];
    
    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        exit(1);
    }
    
    printf("=== PIPE IPC Demo ===\n");
    printf("Pipe created: Read=%d, Write=%d\n", pipefd[0], pipefd[1]);
    
    pid = fork();
    
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // CHILD PROCESS
        close(pipefd[0]);  // Child closes read end
        
        // Get own PID for message
        sprintf(child_msg + 27, "%d", getpid());
        
        printf("CHILD (PID: %d): Sending message to parent...\n", getpid());
        
        // Send message to parent
        write(pipefd[1], child_msg, strlen(child_msg) + 1);
        close(pipefd[1]);
        
        exit(0);
    }
    else {
        // PARENT PROCESS
        close(pipefd[1]);  // Parent closes write end
        
        // Get own PID for message
        sprintf(parent_msg + 27, "%d", getpid());
        
        printf("PARENT (PID: %d): Sending message to child...\n", getpid());
        
        // Send message to child first
        write(pipefd[0], parent_msg, strlen(parent_msg) + 1);
        
        // Wait for child's response
        wait(NULL);
        
        printf("PARENT: Reading child's response...\n");
        read(pipefd[0], buffer, sizeof(buffer));
        printf("PARENT received: %s\n", buffer);
        
        close(pipefd[0]);
    }
    
    printf("\n=== Communication Complete ===\n");
    return 0;
}
