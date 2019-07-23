#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char c;

    if (argc < 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]); /*fprintf will redirect error to stderr with a 
        better usage message */
        return(1); }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror(argv[1]);
        return(0);
        }
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);}
    fclose(fp);

    return(1);
}
