/*
Define a struct Strains which has information about different cannabis strains and their effects.
 */
#define LINE_LENGTH 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Strains 
{
    char **info;
};

int main() {
    struct Strains *weed;
    // weed.info = malloc(70*sizeof(char));
    weed->info = "Pineapple Express\n";
    printf("%s\n", weed->info[0]);
    printf("%s\n", weed->info[1]);
    printf("%s\n", weed->info[0][0]);  
}