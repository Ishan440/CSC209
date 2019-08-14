#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LENGTH 100
/* Program to fix files for the strains so that the format is as needed. Use OGkush.txt for practice.*/

/*
1. Open the file with proper error handling.
2. Read the file and edit it if any words have more than one spacebar space between them.
3. Read the file and edit it if any words of each effect are not in the same line as the effect.
 */
int main() {
    //opening the file
    FILE *fr, *fw; // file pointer
    char s[LINE_LENGTH];
    char *p;
    fr = fopen("OGkush.txt", "r+");
    fw = fopen("out.txt", "w");
    if (fr == NULL || fw == NULL) {
        fprintf(stderr, "Error opening file");
        return 1;
    }
    else {
        while (fgets(s, LINE_LENGTH + 1, fr) != NULL){
             p = strstr(s, "Effects"); 
             if (p){
                    fwrite(s, LINE_LENGTH, sizeof(char), fw);
             }
        };

    }
    if(fclose(fw) != 0 && fclose(fr) != 0) {
        // fprintf(stderr, "Error closing the file");  209 uses perror.
        perror("close error");  // used to send a message to stderr corresponding to errno
        return 1;
        }
    return 0;
}