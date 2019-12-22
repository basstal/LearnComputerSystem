#include <stdlib.h>
#include <stdio.h>

int good_echo()
{
    char *cache = malloc(100);

    cache = fgets(cache, 100, stdin);
    while(!feof(stdin))
    {
        if (fputs(cache, stdout) > 0){
            cache = fgets(cache, 100, stdin);
        }else{
            return ferror (stdout);
        }
    }
    fputs(cache, stdout);
    return 0;
}