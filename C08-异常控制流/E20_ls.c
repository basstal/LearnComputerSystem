#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>


// #define MAX_PATH 200

int main(int argc, char * argv[], char * envp[])
{
    // DIR * dp;
    // struct dirent * dirp;

    // char path[MAX_PATH];
    
    // if (getcwd(path, MAX_PATH) == NULL)
    //     return 1;

    // if ((dp = opendir(path)) == NULL)
    //     return 1;
    // while((dirp = readdir(dp)) != NULL)
    //     printf("%s\n", dirp->d_name);
    
    // closedir(dp);
    // return 0;
    char * pcolumns = getenv("COLUMNS");
    int i = 0;
    while(envp[i] != NULL) ++i;
    envp[i] = pcolumns;
    execve("/bin/ls", argv, envp);
    perror("execve");
    exit(EXIT_FAILURE);
}