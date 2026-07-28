#include <stdio.h>

//Q1
void add_matrics(int (*arr1)[3], int size, int (*arr2)[3]) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%d ", arr1[i][j]+arr2[i][j]);
        }
        printf("\n");
    }
}

//Q2
void product_matrics(int (*arr1)[3], int size, int (*arr2)[3]) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%d ", arr1[i][j]*arr2[i][j]);
        }
        printf("\n");
    }
}

//Q3
void transpose_matrics(int (*arr1)[3], int size, int (*arr2)[3]) {
    printf("arr1\n");
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            arr2[j][i] = arr1[i][j];
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("\narr2\n");
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 3;
    int arr1[3][3] = { {1, 2, 3},  {4, 5, 6}, {7, 8, 9} };
    
    int arr2[3][3] = { {1, 2, 1}, {1, 2, 1}, {1, 2, 1} };

    // add_matrics(arr1, size, arr2);
    // product_matrics(arr1, size, arr2);
    transpose_matrics(arr1, size, arr2);

    return 0;
}