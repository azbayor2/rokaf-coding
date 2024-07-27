#include <stdio.h>
#include <unistd.h>
#include "hw1.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>




void Init(void)
{
    int fd;
    if(fd = open(STORAGE_NAME, O_CREAT)<0)
        perror("make file error 0");
    
    close(fd);

    return;
}

int InsertData(char* key, int keySize, char* pBuf, int bufSize)
{
    int fd;
    if(fd = open(STORAGE_NAME, O_RDWR)<0)
        perror("error opening 1");
    
    int cursor = lseek(fd, 0 , SEEK_SET);

    int block_size = keySize + bufSize + 5;
    Block block;

    while(1)  //빈 공간 찾기
    {
        block.blockOffset = cursor;

        if(read(fd, &block.blockState, sizeof(block.blockState))<0)
            perror("read error 1");
        else if(read, &block.headSize, sizeof(block.headSize)<0)
            perror("read error 2");
        else if(lseek(fd, cursor+block.headSize, SEEK_SET)<0)
            perror("seek error 1")
        if((block.blockState == FREE_BLOCK) && (block.headSize<=block_size))
            break;
    }
}

int getDataByKey(char* key, int keySize, char* pBuf, int bufSize)
{

}

int RemoveDataByKey(char* key, int keySize)
{

}

void InitStorage(void)
{
    int fd;
    if(fd = open(STORAGE_NAME, O_RDWR)<0)
        perror("open error 0");

    Block block;
    block.blockOffset = 0;
    block.blockState = FREE_BLOCK;
    block.headSize = (unsigned short)(MAX_STORAGE_SIZE-1);
    block.tailSize = (unsigned short)(MAX_STORAGE_SIZE-1);

    lseek(fd, block.blockOffset, SEEK_SET);
    if(write(fd, &(block.blockState), sizeof(char))<0)
        perror("write error 1");
    else if(write(fd, &(block.headSize), sizeof(block.headSize))<0)
        perror("write error 2");
    else if(lseek(fd, block.headSize, SEEK_SET)<0)
        perror("lseek error 1");
    else if(lseek(fd, -2, SEEK_CUR)<0)
        perror("lseek error 2");
    else if(write(fd, &(block.tailSize), sizeof(block.tailSize))<0)
        perror("write error 3");

    close(fd);

    return;

}

