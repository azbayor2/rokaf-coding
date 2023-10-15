#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STORAGE_SIZE (65500)
#define STORAGE_NAME "storage"

typedef enum __BlockState{
    FREE_BLOCK = 0,
    ALLOC_BLOCK = 1
} BlockState;


int main()
{

    
    int fd;
    
    if(fd = open(STORAGE_NAME,O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR) < 0 )         
        printf("error");

    
    //파일 초기화

    unsigned char buf[MAX_STORAGE_SIZE];
    buf[0] = (char)FREE_BLOCK;
    buf[1] = (char)MAX_STORAGE_SIZE/256;
    buf[2] = (char)MAX_STORAGE_SIZE%256;

    buf[MAX_STORAGE_SIZE-2] = (char)MAX_STORAGE_SIZE/256;
    buf[MAX_STORAGE_SIZE-1] = (char)MAX_STORAGE_SIZE%256;


    write(fd, buf, sizeof(buf));


    return 0;
    

}