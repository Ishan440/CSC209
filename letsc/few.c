#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{   printf("About to start my pid is %d\n", getpid());
    int x = fork(); // new process created. This is the child process.
    if (x == -1) {
        perror("fork");
        return(1);
    } else if (x == 0) {
        /* child */
        printf("About to call exec my pid is %d\n", getpid()); // will give id of the child process.
        execl("/bin/ls", "ls", (char *)NULL);
        printf("called exec my pid is %d\n", getpid()); // won't execute because on calling exec, PCB was updated w ls code.
        perror("/bin/ls");
        return(1);
    } else {
        /* parent */
        int status, pid;
        pid = wait(&status); // wait makes the parent kill itself until child terminates (that is when wait return child pid)
        printf("pid %d exit status %d\n", pid, WEXITSTATUS(status));
        return(0);
    }
}
