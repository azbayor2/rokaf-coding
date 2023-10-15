#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "hw1.h"

#define MAX_BLOCK_NUM      (1024)
#define ALLOCATED_SIZE  (7)

void Init(void)
{
    extern int fd;
    extern Block buf[MAX_BLOCK_NUM];

  

}

int InsertData(char* key, int keySize, char* pBuf, int bufSize)   //-1일 때 처리하기
{
    int num_block = GetBlocks(buf, MAX_BLOCK_NUM);
    int offset=0;

    int real_size = keySize+bufSize+ALLOCATED_SIZE;
    char block_buf[real_size];
    int block_size;

    for(int i = 0; i<num_block; i++)
    {
       
        if(buf[i].blockState == FREE_BLOCK)
            if(buf[i].sizeHead - ALLOCATED_SIZE >= keySize+bufSize )
            {
                
                offset = buf[i].blockOffset;
                block_size = buf[i].sizeHead;

                block_buf[0] = ALLOC_BLOCK;
                block_buf[1] = (int)real_size/256;
                block_buf[2] = (int)real_size%256;
                block_buf[3] = keySize;
                block_buf[4] = bufSize;
                
                for(int x=0; x<keySize; x++)
                    block_buf[5+x] = key[x];

                for(int x=0; x<bufSize ; x++)
                    block_buf[5+keySize+x] = pBuf[x];
                
                block_buf[real_size-2] = (int)real_size/256;
                block_buf[real_size-1] = (int)real_size%256;

                break;
             }
    }

    //예외처리 하기

    lseek(fd, offset, SEEK_SET);
    write(fd, block_buf, sizeof(block_buf));

    //쪼개진 block 설정하기
    int temp2_size = block_size - real_size;
    char temp2[temp2_size];

    temp2[0] = FREE_BLOCK;
    temp2[1] = (int)temp2_size/256;
    temp2[2] = (int)temp2_size%256;
    temp2[temp2_size-2] = (int)temp2_size/256;
    temp2[temp2_size-1] = (int)temp2_size%256;

    return 0;

}

int GetDataByKey(char* key, int keySize, char* pBuf, int bufSize)
{
    Block temp[MAX_BLOCK_NUM];
    int num_block = GetBlocks(temp, MAX_BLOCK_NUM);
    int block_offset;
    int key_offset;

    for(int i = 0; i<num_block ; i++)
    {
        if(temp[i].blockState=ALLOC_BLOCK)
        

    }

}

int RemoveDataByKey(char* key, int keySize)
{

}

int GetBlocks(Block* pBuf, int bufSize)    //반환 값으로 block의 개수 반환
{


}

void InitStorage(void)        //저장소 초기화
{
    //파일 열기 또는 생성
   
    if(fd = open(STORAGE_NAME, O_RDWR) < 0 )         
        if(fd = open(STORAGE_NAME, O_CREAT) < 0)
            perror("ERROR HANDLING FILE");

    
    //파일 초기화

    char buf[MAX_STORAGE_SIZE];
    buf[0] = FREE_BLOCK;
    buf[1] = (int)MAX_STORAGE_SIZE/256;
    buf[2] = (int)MAX_STORAGE_SIZE%256;

    buf[MAX_STORAGE_SIZE-2] = (int)MAX_STORAGE_SIZE/256;
    buf[MAX_STORAGE_SIZE-1] = (int)MAX_STORAGE_SIZE%256;


    return;
    
    
}

