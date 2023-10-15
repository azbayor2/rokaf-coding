#ifndef __HW1_H__

#define __HW1_H__

#define MAX_STORAGE_SIZE (65500)
#define STORAGE_NAME "storage"

typedef enum __BlockState{
    FREE_BLOCK = 0,
    ALLOC_BLOCK = 1
} BlockState;


typedef struct __Block {
    int blockOffset;    //블록 위치
    int blockState;     //상태
    int sizeHead;      //head 크기
    int sizeTail;       //tail 크기
    int keySize;        //key 값 크기
    int dataSize;        //data 값 크기
} Block;


extern void Init(void);
extern int InsertData(char* key, int keySize, char* pBuf, int bufSize);
extern int GetDataByKey(char* key, int keySize, char* pBuf, int bufSize);
extern int RemoveDataByKey(char* key, int keySize);
extern void InitStorage(void);
extern int GetBlocks(Block* pBuf, int bufSize);


#endif

