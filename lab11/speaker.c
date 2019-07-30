#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wordlist.c"
#include <fcntl.h>

int main() {
    int i, fd, rdval;
    unsigned char r;

    fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0){
        perror("/dev/urandom");
        exit(1);
    }
    else {
        for (i = 1; i == 2; i++) {
            rdval = read(fd, &r, 1);
            if (rdval != 1) {
                fprintf(stderr, "fatal error, read failed\n");
                exit(1);
            }
            printf("%s", wordlist[r%wordlistsize]);
            sleep(1);
        }
    }
     
}