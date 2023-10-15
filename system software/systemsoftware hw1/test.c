#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "hw1.h"

#define MAX_BLOCK_NUM (1024)
#define MAX_STORAGE_SIZE (65500)
#define STORAGE_NAME "storage"

int fd;

typedef struct {
    unsigned char blockState;
    unsigned short sizeHead;
    unsigned short sizeTail;
    unsigned char keySize;
    unsigned char dataSize;

    char *key;
    char *pBuf;
} Block2;

Block2 blk;

Block storage[MAX_BLOCK_NUM];

void Init(void);
void InitStorage(void);
int InsertData(char* key, int keySize, char* pBuf, int bufSize);
int GetDataByKey(char *key, int keySize, char *pBuf, int bufSize);
int RemoveDataByKey(char *key, int Keysize);
int GetBlocks(Block *pBuf, int bufNum);
int FindFreeBlock(char* key, int keySize);
void WriteBlock(char *key, int keySize, char *pBuf, int bufSize);
char CheckBehind(int checkpoint);
void SetFreeBlock();
void Read();
int FindKey(char *key, int keySize);
void rp();

void Init(void)
{
    fd = 0;

    for (int i = 0; i < MAX_BLOCK_NUM; i++)
    {
        storage[i].blockOffset = 0;
        storage[i].blockState = FREE_BLOCK;
        storage[i].dataSize = 0;
        storage[i].keySize = 0;
        storage[i].sizeHead = 0;
        storage[i].sizeTail = 0;
    }


    blk.key = (char *)malloc(255 * sizeof(char));
    blk.pBuf = (char *)malloc(255 * sizeof(char));

}

void InitStorage(void)
{
    fd = open(STORAGE_NAME,O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    if(fd == -1){
      perror("Failed to open file");
    };

    char freeblock = FREE_BLOCK;

    ssize_t StateWrite = write(fd, &freeblock, sizeof(char));

    unsigned short move = MAX_STORAGE_SIZE;

    ssize_t HeadWrite = write(fd, &move, sizeof(unsigned short));

    off_t offset = lseek(fd, MAX_STORAGE_SIZE, SEEK_SET); // 3번째 바이트로 이동 (0부터 시작하므로 offset은 2)
    if (offset == -1) {
        perror("오프셋 이동 실패1");
        close(fd);
        return;
    }

    ssize_t TailWrite = write(fd, &move, sizeof(unsigned short));

}

int InsertData(char* key, int keySize, char* pBuf, int bufSize)
{
    //찾는 기능

    if(fd == -1){
      perror("Failed to open file");
    };

    int check = FindFreeBlock(key, keySize);


    if(check == -1){
        return -1;
    }

    WriteBlock(key, keySize, pBuf, bufSize);

    SetFreeBlock();

    return 0;
    // close(fd);
}


int FindFreeBlock(char* key, int keySize ) {
    int pass_size = 0;

    off_t offset = lseek(fd, pass_size, SEEK_SET);

    ssize_t StateRead = read(fd, &blk.blockState, sizeof(blk.blockState));
    ssize_t HeadRead = read(fd, &blk.sizeHead, sizeof(blk.sizeHead));
    ssize_t ksRead = read(fd, &blk.keySize, sizeof(blk.keySize));

    if (StateRead == -1) {
        perror("읽기 실패");
        close(fd);
        return -1;
    }

    while(blk.blockState != FREE_BLOCK){
        if(blk.keySize == keySize){
            offset = lseek(fd, 1, SEEK_CUR);
            ssize_t keyRead = read(fd, blk.key, blk.keySize);
            if(strcmp(blk.key, key) == 0){
                return -1;
            }
        }
        pass_size += blk.sizeHead;
        offset = lseek(fd, pass_size, SEEK_SET);
        StateRead = read(fd, &blk.blockState, sizeof(blk.blockState));
        HeadRead = read(fd, &blk.sizeHead, sizeof(blk.sizeHead));
        ksRead = read(fd, &blk.keySize, sizeof(blk.keySize));
    }

    offset = lseek(fd, pass_size, SEEK_SET);

    return 0;
}

void WriteBlock(char* key, int keySize, char* pBuf, int bufSize){

    char Allocblock = ALLOC_BLOCK;

    unsigned short totalSize = keySize + bufSize + 7;

    ssize_t StateWrite = write(fd, &Allocblock, sizeof(Allocblock));

    ssize_t HeadWrite = write(fd, &totalSize, sizeof(unsigned short));

    ssize_t ksWrite = write(fd, &keySize, sizeof(char));

    ssize_t bsWrite = write(fd, &bufSize, sizeof(char));

    ssize_t keyWrite = write(fd, key, keySize);

    ssize_t bufWrite = write(fd, pBuf, bufSize);

    ssize_t TailWrite = write(fd, &totalSize, sizeof(unsigned short));

}

char CheckBehind(int checkpoint){


    char buffer[0];

    off_t offset = lseek(fd, checkpoint, SEEK_SET); // 3번째 바이트로 이동 (0부터 시작하므로 offset은 2)
    if (offset == -1) {
        perror("오프셋 이동 실패3");
        close(fd);
        return '\0';
    }

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));

    // close(fd);

    return buffer[0];
}

void SetFreeBlock(){

    off_t currentOffset = lseek(fd, 0, SEEK_CUR);
    if (currentOffset == -1) {
        perror("Failed to get current offset");
        return ;
    }

    if(CheckBehind(currentOffset) == ALLOC_BLOCK){
        return;
    };

    char freeblock = FREE_BLOCK;

    unsigned short totalSize = MAX_STORAGE_SIZE-(unsigned short)currentOffset;

    // printf("free: %d, c: %d, t: %d\n", freeblock,currentOffset, totalSize);

    ssize_t StateWrite = write(fd, &freeblock, sizeof(char));

    ssize_t HeadWrite = write(fd, &totalSize, sizeof(unsigned short));


    off_t offset = lseek(fd, MAX_STORAGE_SIZE-2, SEEK_SET);
    if (offset == -1) {
        perror("오프셋 이동 실패4");
        close(fd);
        return;
    }

    ssize_t TailWrite = write(fd, &totalSize, sizeof(unsigned short));

}


int GetDataByKey(char* key, int keySize, char* pBuf, int bufSize)
{
    off_t a = lseek(fd, 0, SEEK_SET);

    if(fd == -1){
      perror("Failed to open file");
    };

    int check = FindKey(key, keySize);

    if(check == 1){
        return -1;
    }

    a = lseek(fd, 1, SEEK_CUR);
    ssize_t bufSizeRead = read(fd, &blk.dataSize, sizeof(unsigned char));
    bufSize = (int)blk.dataSize;
    ssize_t keyRead = read(fd, blk.key, blk.keySize);
    ssize_t pBufRead = read(fd, pBuf, blk.dataSize);


    return bufSize;
}

int FindKey(char* key, int keySize) {
    int pass_size = 3;
    while (1) {
        off_t offset = lseek(fd, pass_size, SEEK_SET);
        ssize_t keySizeRead = read(fd, &blk.keySize, sizeof(blk.keySize));


        if(offset >= MAX_STORAGE_SIZE){
            return 1;
        }

        if (keySizeRead <= 0) { // EOF에 도달하거나 오류 발생시 반복문 종료
            printf("File read error or EOF reached.1\n");
            break;
        }

        if (blk.keySize == keySize) {
            offset = lseek(fd, 1, SEEK_CUR);
            ssize_t keyRead = read(fd, blk.key, blk.keySize);
            // tempKey[blk.keySize] = '\0'; // null 종료 문자 추가

            if (strcmp(blk.key, key) == 0) { // 찾는 키와 일치하면 반복문 종료
                offset = lseek(fd, pass_size, SEEK_SET);
                break;
            }

            if (keyRead <= 0) { // EOF에 도달하거나 오류 발생시 반복문 종료
                printf("File read error or EOF reached.2\n");
                break;
            }

        }

        offset = lseek(fd, pass_size-2, SEEK_SET);
        ssize_t HeadRead = read(fd, &blk.sizeHead, sizeof(blk.sizeHead));

        if (HeadRead <= 0) {
             printf("File read error or EOF reached.3\n");
             break;
         }

         pass_size += blk.sizeHead;
    }
    return 0;
}

int RemoveDataByKey(char *key, int Keysize)
{
    char freeblock = FREE_BLOCK;
    FindKey(key, Keysize);
    off_t offset = lseek(fd, -3, SEEK_CUR);
    ssize_t StateWrite = write(fd, &freeblock, sizeof(freeblock));


}

char FrontCheckFree() {
    off_t offset = lseek(fd, -2, SEEK_CUR);
    ssize_t TailRead = read(fd, &blk.sizeTail, sizeof(blk.sizeTail));
    offset = lseek(fd, -(blk.sizeTail), sizeof(blk.sizeTail));
    ssize_t StateRead = read(fd, &blk.blockState, sizeof(blk.blockState));
    if(blk.blockState == FREE_BLOCK){
        return FREE_BLOCK;
    }
    else{
        return ALLOC_BLOCK;
    }
}

char BehindCheckFree() {
    ssize_t HeadRead = read(fd, &blk.sizeHead, sizeof(blk.sizeHead));
    off_t offset = lseek(fd, blk.sizeHead-2, SEEK_CUR);
    ssize_t StateRead = read(fd, &blk.blockState, sizeof(blk.blockState));
    if(blk.blockState == FREE_BLOCK){
        return FREE_BLOCK;
    }
    else{
        return ALLOC_BLOCK;
    }
}


int GetBlocks(Block* pBuf, int bufNum)
{
    int count = 0;

    int pass_size = 0;

    off_t offset = lseek(fd, pass_size, SEEK_SET);

    ssize_t StateRead = read(fd, &blk.blockState, sizeof(char));
    ssize_t HeadRead = read(fd, &blk.sizeHead, sizeof(blk.sizeHead));
    ssize_t keySizeRead = read(fd, &blk.keySize, sizeof(blk.keySize));
    ssize_t bufSizeRead = read(fd, &blk.dataSize, sizeof(blk.dataSize));
    ssize_t keyRead = read(fd, blk.key, blk.keySize);
    ssize_t bufRead = read(fd, blk.pBuf, blk.dataSize);
    ssize_t TailRead = read(fd, &blk.sizeTail, sizeof(blk.sizeTail));

    if (StateRead == -1) {
        perror("읽기 실패");
        close(fd);
        return 0;
    }
//blk.blockState != FREE_BLOCK
    while(1){

        if(offset == MAX_STORAGE_SIZE)
            break;

        if(count>MAX_BLOCK_NUM)
            return -1;


        pBuf[count].blockOffset = pass_size;
        pBuf[count].blockState = (int)blk.blockState;
        pBuf[count].sizeHead = (int)blk.sizeHead;
        pBuf[count].keySize = (int)blk.keySize;
        pBuf[count].dataSize = (int)blk.dataSize;
        pBuf[count].sizeTail = (int)blk.sizeTail;


        pass_size += blk.sizeHead;
        offset = lseek(fd, pass_size, SEEK_SET);
        StateRead = read(fd, &blk.blockState, sizeof(char));
        HeadRead = read(fd, &blk.sizeHead, sizeof(blk.sizeHead));
        keySizeRead = read(fd, &blk.keySize, sizeof(blk.keySize));
        bufSizeRead = read(fd, &blk.dataSize, sizeof(blk.dataSize));
        keyRead = read(fd, blk.key, blk.keySize);
        bufRead = read(fd, blk.pBuf, blk.dataSize);
        TailRead = read(fd, &blk.sizeTail, sizeof(blk.sizeTail));

        count++;
    }
    if(blk.blockState == FREE_BLOCK){
        pBuf[count].blockOffset = pass_size;
        pBuf[count].blockState = (int)blk.blockState;
        pBuf[count].sizeHead = (int)blk.sizeHead;
        pBuf[count].keySize = (int)blk.keySize;
        pBuf[count].dataSize = (int)blk.dataSize;
        pBuf[count].sizeTail = (int)blk.sizeTail;

        count++;
    }

    return count; // 읽은 블록 수 반환
}





void Read(){
    // fd = open(STORAGE_NAME,O_RDWR);

    off_t a = lseek(fd, 0, SEEK_SET);

    if(fd == -1){
      perror("Failed to open file");
    };

    rp();
    rp();
    rp();


    // close(fd);
}

void rp(){
    ssize_t StateRead = read(fd, &blk.blockState, sizeof(blk.blockState));
    ssize_t HeadRead = read(fd, &blk.sizeHead, sizeof(blk.sizeHead));
    ssize_t keySizeRead = read(fd, &blk.keySize, sizeof(blk.keySize));
    ssize_t bufSizeRead = read(fd, &blk.dataSize, sizeof(blk.dataSize));
    ssize_t keyRead = read(fd, blk.key, blk.keySize);
    ssize_t pBufRead = read(fd, blk.pBuf, blk.dataSize);
    ssize_t TailRead = read(fd, &blk.sizeTail, sizeof(blk.sizeTail));

    printf("State: %d\n", blk.blockState);
   printf("HeadSize: %d\n", blk.sizeHead);
   printf("KeySize: %d\n", blk.keySize);
   printf("DataSize: %d\n", blk.dataSize);
   printf("Key: %s\n", blk.key);
   printf("Data: %s\n", blk.pBuf);
   printf("TailSize: %d\n", blk.sizeTail);
    printf("\n");
}


#define KEY_SIZE 4
#define DATA_SIZE 5

int keySize[KEY_SIZE] = { 6, 5, 4, 2 };
int dataSize[DATA_SIZE] = { 2, 19, 52, 15, 5 };

char* key[KEY_SIZE] = { "system",
                          "token",
                          "card",
                          "ID" };

char* data[DATA_SIZE] = { "Hi",
                          "KwangwoonUniversity",
                          "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
                          "OperatingSystem",
                          "Apple" };




int PrintBlocks(void)
{

    Block pBuf[MAX_BLOCK_NUM];
    int numBlocks = 0;

    printf("Blocks: ");
    numBlocks = GetBlocks(pBuf, MAX_BLOCK_NUM);
    for(int i = 0; i < numBlocks; i++)
    {
        printf("[%d %d %d %d %d %d], ",
            pBuf[i].blockOffset, pBuf[i].blockState,
            pBuf[i].sizeHead, pBuf[i].sizeTail,
            pBuf[i].keySize, pBuf[i].dataSize);
    }
    printf("\n");
    return 0;

}

void testcase1(void)
{
    int pKeySize, pBufSize, pTempSize;
    char* pKey = NULL;
    char* pBuf = NULL;
    char* pTemp = NULL;
    int i, j, c;

    printf("=======TestCase1=======\n");

    for(i = 0; i < 10; ++i) {
        for(j = 0; j < 10; ++j) {
            pKeySize = keySize[i % KEY_SIZE] + 2;
            pBufSize = dataSize[j % DATA_SIZE] + 2;

            pKey = (char*)malloc(pKeySize);
            pBuf = (char*)malloc(pBufSize);

            sprintf(pKey, "%s%d%d", key[i % KEY_SIZE], i, j);
            sprintf(pBuf, "%s%d%d", data[j % DATA_SIZE], i, j);

            if(-1 == InsertData(pKey, pKeySize, pBuf, pBufSize)) {
                printf("TestCase 1: Fail1\n");
                return;
            }

            free(pKey);
            free(pBuf);
        }
    }
    PrintBlocks();

    for(i = 9; i >= 0; --i) {
        for(j = 0; j < 10; ++j) {
            pKeySize = keySize[i % KEY_SIZE] + 2;
            pBufSize = dataSize[j % DATA_SIZE] + 2;
            pTempSize = dataSize[j % DATA_SIZE] + 2;

            pKey = (char*)malloc(pKeySize);
            pBuf = (char*)malloc(pBufSize);
            pTemp = (char*)malloc(pTempSize);

            sprintf(pKey, "%s%d%d", key[i % KEY_SIZE], i, j);
            sprintf(pBuf, "%s%d%d", data[j % DATA_SIZE], i, j);

            GetDataByKey(pKey, pKeySize, pTemp, pTempSize);

            for(c = 0;c < pTempSize; ++c)
            {
                if (pBuf[c] != pTemp[c])
                {
                    printf("%s, %s\n", pBuf, pTemp);
                    printf("TestCase 1: Fail2\n");
                    return ;
                }
            }

            free(pKey);
            free(pBuf);
            free(pTemp);
        }
    }
    PrintBlocks();

    printf("TestCase 1: Finish\n");
}


int main() {
    Init();
    InitStorage();

    testcase1();
    // char* key = "Hello";
    // int keySize = strlen(key);


    // char* pBuf = "World";
    // int bufSize = strlen(pBuf);

    // InsertData(key, keySize, pBuf, bufSize);

    // key = "myKey";
    // char* data = "myData";

    // keySize = strlen(key); // +1은 null 종료 문자를 포함하기 위함입니다.
    // int dataSize = strlen(data);

    // InsertData(key, keySize, data, dataSize);

    // key = "myKey";
    // keySize = strlen(key);


    // pBuf = "World";
    // bufSize = strlen(pBuf);

    // char* pf;
    // pf = (char *)malloc(255 * sizeof(char));
    // int pfSize;
    // Read();

    // pfSize = GetDataByKey(key, keySize, pf, pfSize);

    // printf("%s, %d\n", pf, pfSize);

    // int num = GetBlocks(storage, MAX_BLOCK_NUM);
    // printf("%d\n", num);

}