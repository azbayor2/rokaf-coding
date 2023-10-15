#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "hw1.h"

#define MAX_BLOCK_NUM      (1024)
#define ALLOCATED_SIZE  (7)

int fd =0;

void Init(void)
{


}

int InsertData(char* key, int keySize, char* pBuf, int bufSize)  
{
    int length = ALLOCATED_SIZE + keySize + bufSize;
    
    unsigned char insertkey[length]; //잠재적 오류
    insertkey[0] = ALLOC_BLOCK;
    insertkey[1] = length/256;
    insertkey[2] = length%256;
    insertkey[3] = keySize;
    insertkey[4] = bufSize;

    for(int i =0; i<keySize; i++)
    {
        insertkey[5+i] = key[i];
    }

    for(int i =0; i<bufSize; i++)
    {
        insertkey[5+keySize+i] = pBuf[i];
    }

    insertkey[length-2]= length/256;
    insertkey[length-1] = length%256;

    //빈 공간 찾기


    unsigned char head_temp[5];
    int offset =0;


    while(1)
    {
        lseek(fd, offset, SEEK_SET);
        read(fd, head_temp, sizeof(head_temp));
        if(head_temp[0] == FREE_BLOCK)
        {
            int temp_length = head_temp[1]*256 + head_temp[2];
            if(temp_length >= length)
            {
                lseek(fd, offset, SEEK_SET);
                write(fd, insertkey, sizeof(insertkey));

                int leftover = temp_length - length;

                if(leftover==0)
                    break;

                char leftover_temp[2];
                leftover_temp[0] = leftover/256;
                leftover_temp[1] = leftover % 256;

                write(fd, FREE_BLOCK, 1);
                write(fd, leftover_temp, sizeof(leftover_temp));

                lseek(fd, offset+temp_length-2, SEEK_SET);
                write(fd, leftover_temp, sizeof(leftover_temp));


                break;

                

            }
        }
        

    }

    return 0;




}

int GetDataByKey(char* key, int keySize, char* pBuf, int bufSize)  //인자: key, key size, data, data size
{

    int offset = 0;           //offset 저장 할 변수
    unsigned char temp_head[5];    //처음 5개의 정보 저장 용도
    int length=0;          //block 의 길이 저장 용도          
    
    
    while(1)
    {
        
        if(offset == MAX_STORAGE_SIZE)    //offset 이 storage max size 인 경우
            return -1;
        
        
        
        lseek(fd, offset, SEEK_SET);    //offset 설정하기
        
        read(fd, temp_head, sizeof(temp_head));
        length = temp_head[1]*256 + temp_head[2];   //block 길이 저장

        offset+=length;   //offset 설정

        if(temp_head[0] == FREE_BLOCK)    //free block 일 경우 skip
        {  
            continue;
        }

        

        int temp_keysize = temp_head[3];   //keysize 저장
        char *temp_key = (char*)malloc(temp_keysize+1);     //key 값 동적할당
        temp_key[temp_keysize] = '\0';
        
        read(fd, temp_key, sizeof(temp_key)-1);    //읽기

        if(strcmp(temp_key, key) ==0)    //문자열이 같을 경우
        {
            int temp_datasize = temp_head[4];
            char *temp_data = (char*)malloc(temp_datasize +1);        //data 값 동적할당
            temp_data[temp_datasize] = '\0';

            read(fd, temp_data, sizeof(temp_data)-1);
            pBuf = temp_data;
            free(temp_key);    //key 값 동적할당 해지

            return 0;
        }

        else
        {
            free(temp_key);
            continue;
        }
        
    }


}

int RemoveDataByKey(char* key, int keySize)
{
    int offset = 0;           //offset 저장 할 변수
    unsigned char temp_head[5];    //처음 5개의 정보 저장 용도
    int length=0;          //block 의 길이 저장 용도      
    int origin_length=0;    

    while(1)
    {
        
        if(offset == MAX_STORAGE_SIZE)    //offset 이 storage max size 인 경우
            return -1;
        
        
        
        lseek(fd, offset, SEEK_SET);    //offset 설정하기
        
        read(fd, temp_head, sizeof(temp_head));
        length = temp_head[1]*256 + temp_head[2];   //block 길이 저장

        offset+=length;   //offset 설정

        if(temp_head[0] == FREE_BLOCK)    //free block 일 경우 skip
        {  
            continue;
        }

        

        int temp_keysize = temp_head[3];   //keysize 저장
        char *temp_key = (char*)malloc(temp_keysize+1);     //key 값 동적할당
        temp_key[temp_keysize] = '\0';
        
        read(fd, temp_key, sizeof(temp_key)-1);    //읽기

        if(strcmp(temp_key, key) ==0)    //문자열이 같을 경우
        {
           lseek(fd, offset-length, SEEK_SET);   //현재 cursor 위치에서 블록의 시작 지점으로 감.
           write(fd, FREE_BLOCK, 1);
           origin_length = length;
           break;
        }

        else
        {
            free(temp_key);
            continue;
        }

    }


    ////////////////////////////////////////////////
    //빈 블록 합하기


    //뒷 블록 합하기


    lseek(fd, offset, SEEK_SET);          //현재 offset 위치는 없앤 블록의 다음 블록임.
    read(fd, temp_head, sizeof(temp_head));

    if(temp_head[0] == FREE_BLOCK)
    {
        int next_block_size = temp_head[1]*256 + temp_head[2];
        lseek(fd, offset+next_block_size-2, SEEK_SET);    //tail 로 이동

        length+=next_block_size;    //block 길이 추가하기
            
        char temp_tail_length[2];
        temp_tail_length[0] = length/256;
        temp_tail_length[1] = length%256;

        write(fd, temp_tail_length, sizeof(temp_tail_length));   //위치 저장하기


        lseek(fd, -length+1, SEEK_CUR);
        write(fd, temp_tail_length, sizeof(temp_tail_length));

            
    }



    //앞 블록 합하기

    offset-=origin_length;    //offset 위치를 처음 지운 block 의 위치로 설정

    lseek(fd, offset-2, SEEK_SET);    //앞 블록의 tail 설정
    char temp_tail_length[2];
    read(fd, temp_tail_length, sizeof(temp_tail_length));  

    int prev_block_size = temp_tail_length[0]*256 + temp_tail_length[1]; //앞 블록의 길이 저장하기

    lseek(fd, offset-prev_block_size, SEEK_SET);    //앞 블록의 head 로 이동
    read(fd, temp_head, sizeof(temp_head));          //앞 블록 정보 읽기



    if(temp_head[0] == FREE_BLOCK)
    {
        int next_block_size = temp_head[1]*256 + temp_head[2];
        lseek(fd, offset+length-2, SEEK_SET);    //tail 로 이동

        length+=next_block_size;    //block 길이 추가하기
            
        char temp_tail_length[2];
        temp_tail_length[0] = length/256;
        temp_tail_length[1] = length%256;

        write(fd, temp_tail_length, sizeof(temp_tail_length));   //위치 저장하기


        lseek(fd, -length+1, SEEK_CUR);
        write(fd, temp_tail_length, sizeof(temp_tail_length));
    }


    return 0;


}

int GetBlocks(Block* pBuf, int bufSize)   
{
    int num_block =0;
    int i =0;
    int offset =0;

    unsigned char head[5];
    unsigned char tail[2];
    while(1)
    {
        if(offset == MAX_STORAGE_SIZE)
            break;

        if(i>MAX_BLOCK_NUM)
            return -1;
        
        lseek(fd, offset, SEEK_SET);
        read(fd, head, sizeof(head));
        pBuf[i].blockState = head[0];
        pBuf[i].sizeHead = head[1]*256 + head[2];
        pBuf[i].keySize = head[3];
        pBuf[i].dataSize = head[4];
        pBuf[i].blockOffset = offset;

        lseek(fd, offset+pBuf[i].sizeHead-2, SEEK_SET);

        read(fd, tail, sizeof(tail));
        pBuf[i].sizeTail = tail[0]*256 + tail[1];

        offset+=pBuf[i].sizeHead;
        i++;



    }

    return i;

}

void InitStorage(void)        //저장소 초기화
{
    //파일 열기 또는 생성
   
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


    return;
    
    
}

