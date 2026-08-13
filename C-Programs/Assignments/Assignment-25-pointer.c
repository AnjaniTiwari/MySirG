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
        result[i] = '\0';
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
    int i, x, temp;
    int m = 0;
    
    print_arr(arr, size);

    for(i = m+1; i < size; ++i) {
        if(arr[m] >= arr[i]) {
            temp = arr[i];
            for(x = i; x > m; --x) 
                arr[x] = arr[x-1];
            arr[m] = temp;
            m++;
        }
    }
    
    print_arr(arr, size);

}

//Q10
int highest_marks(int** class, int n_class, int* len) {
    int max = class[0][0];
    int i = 0, j = 0;
    
    while(i < n_class) {
        j = 0;
        while(j < len[i]) {
            if(max < class[i][j])
                max = class[i][j];
            ++j;
        }
        ++i; 
    }
    return max;
}

int main() {
    system("clear");
    int n1 = 10, n2 = 20;
    char arr[20] = "AXY";
    char str[] = "Programming";
    int num[] = {23, 67, 89, 11, 23, 35, 42, 59, 16, 8, 81};
    int num2[] = {5, 4, 3, 2, 1};
    int num3[20] = {0};
    
    
    int class1_student_marks[3] = {21, 24, 29};
    int class2_student_marks[2] = {22, 25};
    int class3_student_marks[1] = {30};
    int class4_student_marks[2] = {19, 23};
    int class5_student_marks[3] = {26, 27, 19};
    int* class[5] = {class1_student_marks,
                     class2_student_marks,
                     class3_student_marks,
                     class4_student_marks,
                     class5_student_marks};

    int student_marks_arr_len[] = {3, 2, 1, 2, 3};

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
    // printf("Highest mark - %d", highest_marks(class, 5, student_marks_arr_len));
    printf("\n");
    return 0;
}
