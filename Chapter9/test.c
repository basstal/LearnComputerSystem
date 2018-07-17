#include "csapp.h"

int main(int argc, char ** argv)
{
    FILE * fd = fopen(argv[1], "a+");
    mmap(stdout, fd->_bf._size, PROT_WRITE, MAP_PRIVATE, fd->_file, 0);
    fflush(stdout);
    exit(0);
}