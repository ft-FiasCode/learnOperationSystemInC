#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2];  // Two pipes: fd1 (parent→child), fd2 (child→parent)
    pid_t pid;
    char buffer[100];
    
    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("pipe failed");
        exit(1);
    }
    
    pid = fork();
    
    if (pid == 0) {
        // CHILD: Read from fd1, Write to fd2
        close(fd1[1]);  // Close write end of pipe1
        close(fd2[0]);  // Close read end of pipe2
        
        read(fd1[0], buffer, sizeof(buffer));
        printf("CHILD received from parent: %s\n", buffer);
        
        strcpy(buffer, "CHILD RESPONSE");
        write(fd2[1], buffer, strlen(buffer) + 1);
        
        close(fd1[0]);
        close(fd2[1]);
    }
    else {
        // PARENT: Write to fd1, Read from fd2
        close(fd1[0]);  // Close read end of pipe1
        close(fd2[1]);  // Close write end of pipe2
        
        strcpy(buffer, "PARENT MESSAGE");
        write(fd1[1], buffer, strlen(buffer) + 1);
        
        wait(NULL);
        
        read(fd2[0], buffer, sizeof(buffer));
        printf("PARENT received from child: %s\n", buffer);
        
        close(fd1[1]);
        close(fd2[0]);
    }
    
    return 0;
}
