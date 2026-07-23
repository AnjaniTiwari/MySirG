#include <stdio.h>



//Q6
void array_sort(int* arr, int size) {
    int swap, j, index;
    for(int i = 0; i < size-1; ++i) {
        index = i;
        for(j = i+1; j < size; ++j) {
            if(arr[j] < arr[index]) 
                index = j;
        }
        if(i != index) {
            swap = arr[i];
            arr[i] = arr[index];
            arr[index] = swap;
        }
    }
    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
} 

//Q7
void second_largest(int* arr, int size) {
    int max, second_max;
    if(arr[0] > arr[1]) {
        max = arr[0];
        second_max = arr[1];
    }
    else {
        max = arr[1];
        second_max = arr[0];
    }

    for(int i = 2; i < size; ++i) {
        if(arr[i] > max) {
            second_max = max;
            max = arr[i];
        }
        else {
            if(arr[i] > second_max)
                second_max = arr[i];
        }
    }

    printf("Second largest element : %d\n", second_max);
}

//Q8
void second_smallest(int* arr, int size) {
    int min, second_min;
    if(arr[0] < arr[1]) {
        min = arr[0];
        second_min = arr[1];
    }
    else {
        min = arr[1];
        second_min = arr[0];
    }

    for(int i = 2; i < size; ++i) {
        if(arr[i] < min) {
            second_min = min;
            min = arr[i];
        }
        else {
            if(arr[i] < second_min)
                second_min = arr[i];
        }
    }
    printf("Second smallest element : %d\n", second_min);
}

//Q9
void array_sort_descending(int* arr, int size) {
    int swap, j, index;
    for(int i = 0; i < size-1; ++i) {
        index = i;
        for(j = i+1; j < size; ++j) {
            if(arr[j] > arr[index]) 
                index = j;
        }
        if(i != index) {
            swap = arr[i];
            arr[i] = arr[index];
            arr[index] = swap;
        }
    }
    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
} 

//Q10
void arr_cpy(int* arr1, int* arr2, int size) {
    for(int i = 0; i < size; ++i) {
        arr2[i] = arr1[i];
    }
    printf("Array1: ");
    for(int i = 0; i < size; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\nArray2: ");
    for(int i = 0; i < size; ++i) {
        printf("%d ", arr2[i]);
    }
}

void sum_of_array(int size) {
    int arr[size], arr2[size];
    int sum = 0;
    int even_sum = 0, odd_sum = 0;
    int gratest = 1;
    int smallest = 1;

    printf("Enter %d numbers\n", size);
    for(int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
        
        sum+=arr[i];
        
        if(arr[i]&1)
            odd_sum+=arr[i]; 
        else
            even_sum+=arr[i];

        if(arr[i] > gratest)
            gratest = arr[i];
        if(arr[i] < smallest)
            smallest = arr[i];
    }

    // printf("Sum is %d\n", sum); //Q1
    // printf("Average is %.2f\n", sum/(float)size); //Q2
    // printf("Even sum %d Odd sum %d\n", even_sum, odd_sum); //Q3
    // printf("Gratest num is %d\n", gratest); //Q4
    // printf("Smallest num is %d\n", smallest); //Q5

    // array_sort(arr, size); //Q6
    second_largest(arr, size); //Q7
    // second_smallest(arr, size); //Q8
    // array_sort_descending(arr, size);//Q9
    // arr_cpy(arr, arr2, size);
}

int main() {
    sum_of_array(5);

    printf("\n");
    return 0;
}