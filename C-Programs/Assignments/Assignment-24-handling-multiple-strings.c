#include <stdio.h>
#include <string.h>
#include "Assignment-23-string-and-function.c"

//Q1
void print_string(char(*p)[50], int total_string) {
   for(int i = 0; i < total_string; ++i) {
        printf("%s\n", p[i]);
    }
}
void input_string(char(*p)[50], int total_string) {
    int i;
    for(i = 0; i < total_string; ++i) {
        printf("Enter %d string: ", i+1);
        fgets(p[i], 50, stdin);
        p[i][strlen(p[i])-1] = '\0';
        printf("\n");
    }
}

//Q2
void find_vowels(char (*p)[50], int size) {
    int i, vowels, len;
    for(i = 0; i < size; ++i) {
        vowels = 0; 
        len = strlen(p[i]);
        for(int j = 0; j < len; ++j) {
            switch(p[i][j]) {
                case 'A' :
                case 'a' :
                case 'E' :
                case 'e' :
                case 'I' :
                case 'i' :
                case 'O' :
                case 'o' :
                case 'U' :
                case 'u' :
                    vowels++;
            }
        }
        printf("%s vowels = %d\n", p[i], vowels);
    }
}

//Q3
void sort_city_name(char (*p)[50], int size) {
    int i, j;
    char temp[50] = {'\0'};
    for(i = 0; i < size-1; ++i) {
        for(j = 0; j < size-1-i; ++j) {
            if(!i) {
                if(p[j][0] >= 'a' && p[j][0] <= 'z')
                    p[j][0]-=32;
                if(p[j+1][0] >= 'a' && p[j+1][0] <= 'z')
                    p[j+1][0]-=32;
            }
            if(p[j][0] > p[j+1][0]) {
                strcpy(temp, p[j]);
                strcpy(p[j], p[j+1]);
                strcpy(p[j+1], temp);
            }
        }
    }
}

//Q4
void store_char(char (*str1)[50], int str1_size, char* str2, int str2_size) {
    if(str2_size <= str1_size) {
        for(int i = 0; i < str2_size; ++i) { 
            str1[i][0] = str2[i];
            str1[i][1] = '\0';
        }
    }
    else
        printf("size overflow.\n");
}

//Q5
void remove_duplicate(char (*str)[50], int size) {
    int i, j, k, len;
    for(i = 0; i < size-1; ++i) {
        len = strlen(str[i]);
        for(j = i+1; j < size-1; ++j) {
            if(len == strlen(str[j]) && case_insensitive_compare(str[i], str[j])) {
                for(k = j; k < size-1-i; ++k) {
                    strcpy(str[k], str[k+1]);
                }
                str[k][0] = '\0'; 
                size--;
            }
        }
    }
}

int main() {
    char str[20][50] = {'\0'};
    char *str2 = " My name is anjani";
    system("clear");
    input_string(str, 5);
    // find_vowels(str, 5);
    // sort_city_name(str, 5);
    // store_char(str, 20, str2, strlen(str2));
    remove_duplicate(str, 5);
    print_string(str, 20);
    printf("\n");
    return 0;
}