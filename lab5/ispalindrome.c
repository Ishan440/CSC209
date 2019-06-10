
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 
#include <string.h>
  

int main (int argc, char * argv[]) 
{   
    int n;

    if (argc != 2 || (n = atoi(argv[1])) <= 0) {
        fprintf(stderr, "usage: %s n\nispalindrome sentence here\n", argv[0]);
        return(1);
    }

    char *p, *q, *s; 
    s = argv[1];
    p = s; 
    q = s + strlen(s);
  
    while (p < q) {
        if (!(isalnum(*p))){
            p++;
        } 
        else if (!(isalnum(*q))) { 
            --q;  
        }
        else if (tolower(*p) == tolower(*q)){
            p++;
            --q;
        }
        else{
            break; }
    } 
  
    if (p >= q){ 
        return 0; }
    else{
        return 1; }
} 
  
