#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char ** argv) {
    int fd, size;
    char *data, *output;
    fd = open(argv[1],O_RDWR);
    size = lseek(fd,0,SEEK_END);
    data = malloc(size*sizeof(char));
    output = malloc(size*sizeof(char));
    lseek(fd,0,SEEK_SET);
    read(fd,data,size);
    for(int i = 0 ; i < size ; i++)
        output[i] = data[size-1-i];
    lseek(fd,0,SEEK_SET);
    write(fd,output,size);
    close(fd);
    return 0;
}
