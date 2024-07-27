#ifndef __HW1_H__

#define __HW1_H__

#define MAX_STORAGE_SIZE (65536)
#define STORAGE_NAME "storage"

typedef enum __BlockState{
    FREE_BLOCK = 0,
    ALLOC_BLOCK = 1
} BlockState;

typedef struct{
    unsigned short blockOffset;
    char blockState;
    unsigned short keySize;
    unsigned short dataSize;
    unsigned short tailSize;
    unsigned short headSize;
} Block;


extern void Init(void);
extern int InsertData(char* key, int keySize, char* pBuf, int bufSize);
extern int getDataByKey(char* key, int keySize, char* pBuf, int bufSize);
extern int RemoveDataByKey(char* key, int keySize);
extern void InitStorage(void);


#endif