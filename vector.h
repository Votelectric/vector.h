#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

// 结构体定义
typedef struct {
    void *data;         //指针    
    size_t size;        //已存放数据  
    size_t capacity;    //已分配内存
    size_t item_size;   //每个元素的大小
} myvector;

// 函数原型声明
void vector_create(myvector *v, size_t item_size);
void vector_create_with(myvector *v, size_t item_size, size_t initial);
void vector_free(myvector *v);
void vector_clear(myvector *v);
void vector_push_back(myvector *v, const void *item);
void vector_erase(myvector *v, int place);

// 宏封装，让调用更方便
#define VEC_PUSH(v, val) do { \
    __typeof__(val) _temp = (val); \
    vector_push_back((v), &_temp); \
} while(0)

#endif