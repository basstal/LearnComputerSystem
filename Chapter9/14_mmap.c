#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main()
{
    char * addr;
    struct stat st;
    int fd;

    fd = open("hello.txt", O_RDWR);
    if (fd == -1)
        handle_error("open");

    if (fstat(fd, &st) == -1)           /* To obtain file size */
        handle_error("fstat");
    
    addr = mmap(NULL, st.st_size - 1, PROT_READ, MAP_PRIVATE, fd, 1);
    write(fd, "J", 1);
    write(fd, addr, st.st_size - 1);
    close(fd);
    exit(EXIT_SUCCESS);
}