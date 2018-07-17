#include "csapp.h"

int main(int argc, char ** argv)
{
    int fileno = open(argv[1], O_RDWR);
    // printf(fd)
    void * bufp = mmap(NULL, 1, PROT_READ, MAP_PRIVATE, fileno, 0);
    printf("%s", bufp);
    exit(0);
}