#include "hw1.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
    Init();
    InitStorage();

    int fd = open(STORAGE_NAME, O_RDWR);

    Block block;

    read(fd, &(block.blockState), 1);
    read(fd, &(block.headSize), 2);
    
    printf("%d %d", block.blockState, block.headSize);


    return 0;
}