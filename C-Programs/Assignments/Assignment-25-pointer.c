#include <stdio.h>
#include <string.h>

//Q1
void swap(int* n1, int* n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

//Q2
void search_all_accurrences(char* str, char ch, int* arr) {
    int i, j = 0;
    for(i = 0; i < str[i]; ++i) {
        if(str[i] == ch) {
		    arr[j++] = i;            
        }
    }
    for(i = 0; i < j; ++i) {
        printf("%d ", arr[i]);
    }
}

//Q3
void uppercase(char* str) {
    int i;
    for(i = 0; i < str[i]; ++i) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i]-=32;
    }
    printf("%s", str);
}

//Q4
void lowercase(char* str) {
    int i;
    for(i = 0; i < str[i]; ++i) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i]+=32;
    }
    printf("%s", str);
}

//Q5
void extract_string(char* str, int start_index, int end_index, char* result) {
    int len = strlen(str);
    int i = 0;
    if(start_index < end_index && end_index <= len) {
        while(start_index != end_index) {
            result[i++] = str[start_index++];
        }
        printf("%s", result);
    }
    else {
        printf("index out of bound.\n");
    }

}

//Q6
void swap_string(char* str1, char* str2) {
    char temp[20];
    printf("%s %s\n", str1, str2);
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    printf("%s %s", str1, str2);
}

//Q7
void sort(int* ptr, int size) {
    int i, j, temp;
    for(i = 0; i < size-1; ++i) 
        for(j = 0; j < size-1-i; ++j) {
            if(ptr[j] > ptr[j+1]) {
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
    
    for(i = 0; i < size; ++i) 
        printf("%d ", ptr[i]);
}

//Q8
void marge(int* num1, int size1, int* num2, int size2, int* num3) {
    int i;
    for(i = 0; i < size1; ++i) {
        num3[i] = num1[i];
    }
    for(i = 0; i < size2; ++i) {
        num3[size1+i] = num2[i];
    }
    for(i = 0; i < size1+size2; ++i)
        printf("%d ", num3[i]);
}

//Q9
print_arr(int* arr, int size) {
    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
void move_first_index(int* arr, int size) {
    int i, j, flag;
    int m = size/2;
    
    print_arr(arr, size);
    swap(&arr[0], &arr[m]);

    j = m+1;
    for(i = m-1; i >= 0; --i)  {
        flag = 0;
        if(arr[i] > arr[m]) {
            while(j < size) {
                if(arr[j] < arr[m]) {
                    swap(&arr[i], &arr[j]);
                    flag = 1;
                    break;
                }
                j++;
            }
            if(j == size) {
                swap(&arr[i], &arr[m]);
                m = i;
            }
        }
    }
    while(j < size) {
        if(arr[j] < arr[m]) {
            swap(&arr[j], &arr[m]);
            m = j;
        }
        j++;
    }
    print_arr(arr, size);

}

int main() {
    system("clear");
    int n1 = 10, n2 = 20;
    char arr[20] = "AXY";
    char str[] = "Programming";
    int num[] = {5, 8, 2, 7, 3, 9, 1};
    int num2[] = {8, 9, 7, 0, 10};
    int num3[20] = {0};

    // swap(&n1, &n2);
    // printf("%d %d", n1, n2);

    // search_all_accurrences(str, 'g', arr);
    // uppercase(str);
    // lowercase(str);
    // extract_string(str, 2, 5, arr);
    // swap_string(str, arr);
    // sort(num, sizeof(num)/sizeof(*num));
    // marge(num, sizeof(num)/sizeof(*num), num2, sizeof num2/sizeof *num2, num3);
    move_first_index(num, sizeof(num)/sizeof(*num));
    printf("\n");
    return 0;
}
