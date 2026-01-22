#include "vector.h"
#include <stdio.h>

int main(void){
    myvector test1;
    vector_create_with(&test1, sizeof(double), 5);
    
    double *ptr = test1.data;
    for (int i = 0; i < test1.size; i++) {
        ptr[i] = i + 0.1;
        printf("%.2lf ", ptr[i]);
    }
    printf("\n");
    
    vector_erase(&test1, 2);
    for (int i = 0; i < test1.size; i++) {
        printf("%.2lf ", ptr[i]);
    }
    printf("\n");
    vector_clear(&test1);
    vector_free(&test1);
    return 0;
}