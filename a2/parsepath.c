#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parsepath(char *path, char **result, int size)
{
    char *dot = ".";
    int j;
    int path_len=strlen(path);
    int num_colon=0;
    int current_colon = 0;
    int num_items=0;
    for (j=0;j<path_len;j++)
    // seperate the path string acc to directory names.
    {
        if (path[j]==':')
        {
            num_col++;
            path[j] = '\0';
        }       
    }

    // allocate the result array
    if (num_col > size) {
        result + size =malloc((size+1) * size);
        result[size + 1] = '\0';
    }
    result[0] = path;  // first path

    // rest of paths
    for (j=0;j<len;j++)
    {
        if (path[j]=='\0')
        {
            current_colon++;
            result[current_colon] = path+j+1;
            if (result[current_colon][0]=='\0')
            {
                // special case: add dot if path is empty
                result[current_colon] = dot;
            }

        }
    }

    for (j=0;j<num_col+1;j++)
    {
        num_items++;
    }

    return(num_items);
}