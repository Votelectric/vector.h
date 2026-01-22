#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vector_create(myvector *v, size_t item_size){ //item_size用sizeof(int/double/float/char)来表示类型
    v->size = 0;
    v->capacity = 4;
    v->item_size = item_size;
    v->data = malloc(v->capacity * v->item_size);
}

void vector_create_with(myvector *v, size_t item_size, size_t initial){ //item_size用sizeof(int/double/float/char)来表示类型
    v->size = initial;
    v->capacity = initial > 0 ? initial : 4; //用户瞎几把输个-1你总不能停摆吧
    v->item_size = item_size;
    v->data = calloc(v->capacity, v->item_size);
}

void vector_free(myvector *v){ //用完vector之后必须free
    if (v->data != NULL) {
        free(v->data);
        v->data = NULL;
    }
    v->size = 0;
    v->capacity = 0;
}

void vector_clear(myvector *v) {
    if (v->data != NULL) {
        memset(v->data, 0, v->capacity * v->item_size);
        v->size = 0; 
    }
}

void vector_push_back(myvector *v, const void *item){
    if (v->size == v->capacity){
        size_t new_capacity = v->capacity * 2;
        void *new_data = realloc(v->data, new_capacity * v->item_size);
        if (new_data == NULL) {
            printf("Error.No memory for realloc.\n");
            return;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }

    void *target = (char *)v->data + (v->size * v->item_size);
    memcpy(target, item, v->item_size);
    v->size++;
}

void vector_erase(myvector *v, int place){
    if (place < 0 || place >= v->size || v->data == NULL || v == NULL) {
        printf("Error,are you trying to move out of memory?\n");
        return;
    }

    char *target = (char *)v->data + (place * v->item_size); //target:被删除的内容 Address=Base+(Index×Item_Size)
    char *next = target + v->item_size;                      //next:下一个内容

    size_t item_move = v->size - place - 1; //需要移动的内容
    size_t bite_move = item_move * v->item_size;//需要移动的字节数

    if (bite_move > 0) {
        memmove(target, next, bite_move);
    }
    v->size--;
    memset((char*)v->data + v->size * v->item_size, 0, v->item_size);
}