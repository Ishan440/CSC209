#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int x = fork(); 
    if (x == -1) {
        perror("fork");
        return(1);
    } else if (x == 0) {
        /* child */
        close(1);
        if (open("file", O_WRONLY|O_CREAT|O_TRUNC, 0666) < 0) {
            perror("file");
            return(1);
        }
        execl("/bin/ls", "ls", (char *)NULL);
        perror("/bin/ls");
        return(1);
    } else {
        /* parent */
        int status, pid;
        pid = wait(&status);
        printf("pid %d exit status %d\n", pid, WEXITSTATUS(status));
        return(0);
    }
}