#include <stdio.h>
#include "Assignment-18-array.c"

void arr_print(int* arr, int size) {
    for(int j = 0; j < size; ++j) {
        printf("%d ", arr[j]);
    }
} 

//Q1
int gratest(int* arr, int size) {
    int max = arr[0];
    for(int i = 1; i < size; ++i) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

//Q2
int smallest(int* arr, int size) {
    int small = arr[0];
    for(int i = 1; i < size; ++i) {
        if(arr[i] < small)
            small = arr[i];
    }
    return small;
}

//Q3
void array_short(int* arr, int size) {
    int index = 0, temp;
    for(int i = 0; i < size-1; ++i) {
        index = i;
        for(int j = i+1; j < size; ++j) {
            if(arr[j] < arr[index])
                index = j;
        }
        if(i != index) {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
    arr_print(arr, size);
}

//Q4
void array_rotation(int* arr, int size, int rotation_num, int direction) {
    int temp;
    for(int r = 1; r <= rotation_num; ++r) {
        //Left shift
        if(!direction) {
            temp = arr[0];
            for(int i = 0; i < size-1; ++i) {
                arr[i] = arr[i+1];
            }
            arr[size-1] = temp;
        }
        else {
            temp = arr[size-1];
            for(int i = size-1; i > 0; --i) {
                arr[i] = arr[i-1];
            }
            arr[0] = temp;
        }
    } 
    arr_print(arr, size);
}

//Q5
void adjacent_duplicate(int* arr, int size) {
    int i;
    for(i = 0; i < size-1; ++i) {
        if(arr[i] == arr[i+1])
            break;
    }
    
    if(i == size-1)
        printf("Not adjacent duplicate.");
    else
        printf("%d adjacent duplicate.", arr[i]);

}

//Q6
void swap_element(int* arr, int size, int index1, int index2) {
    if(index1 <= size-1 && index2 <= size-1) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    arr_print(arr, size);
}

//Q7
int check_duplicate(int* arr, int size, int element) {
    for(int i = 0; i < size; ++i)
        if(arr[i] == element)
            return 0;
    return 1;

}
int duplicate_count(int* arr, int size) {
    int i, count = 0;
    int doubly[size/2];

    for(i = 0; i < size-1; ++i) {
        for(int j = i+1; j < size; ++j) {
            if(arr[i] == arr[j]) {
                if(check_duplicate(doubly, count, arr[i]))
                    doubly[count++] = arr[i];
            }
        }
    }
    return count;
}

void print_unique_elemets(int* arr, int size) {
    int count = 0, j = 0;
    array_sort(arr, size);
    for(int i = 0; i < size; ++i) {
        j = i+1;
        if(arr[i] == arr[j]) {
            while(arr[i] == arr[j+1])
                j++;
            i = j;
        }
        count++;
    }    
}

int main() {
    int size = 5;
    int arr[size];

    printf("Enter %d numbers: ", size);
    for(int i = 0; i < size; ++i) {
        scanf("%d", arr+i);
    }

    // printf("gratest: %d\n", gratest(arr, size));
    // printf("smallest: %d\n", smallest(arr, size));
    // array_short(arr, size);
    // array_rotation(arr, size, 2, 1);
    // adjacent_duplicate(arr, size);
    // swap_element(arr, size, 0, 3);
    printf("duplicate count %d", duplicate_count(arr, size));
    printf("\n");
    return 0;
}