#include <stdio.h>

//Q1
int str_len(char* str) {
    int len;
    for(len = 0; str[len]; ++len);
    return len;
}

//Q2
void reverse(char* str) {
    int len = str_len(str);
    char ch;
    for(int i = 0; i < len/2; ++i) {
        ch = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = ch;
    }
} 

//Q3
int compare(char* str1, char* str2) {
    int len1 = str_len(str1);
    int len2 = str_len(str2);
    int i;

    for(i = 0; i <= len1 && i <= len2; ++i) 
        if(str1[i] != str2[i]) 
            return str1[i]-str2[i];
    return 0;
}

//Q4
void uppercase(char* str) {
    int len = str_len(str);
    for(int i = 0; i < len; ++i) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i]-=32;
    }
}


//Q5
void lowercase(char* str) {
    int len = str_len(str);
    for(int i = 0; i < len; ++i) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i]+=32;
    }
}

//Q6
int vowel(char* str) {
    int len = str_len(str);
    int count = 0;
    char vowels_list[] = "AEIOUaeiou";
    
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(str[i] == vowels_list[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

//Q7
int first_occurrence(char* str, char ch) {
    int len = str_len(str);

    for(int i = 0; i < len; ++i) 
        if(str[i] == ch)
            return i;
    return -1;
}

//Q8
int find_char(char* str, char ch, int s_index, int e_index) {
    int len = str_len(str);
    if(s_index < len && e_index < len) {
        for(int i = s_index; i < e_index; ++i) 
            if(str[i] == ch)
                return i;
    }
    return -1;
}

//Q9
void swap(char* str, int f_index, int s_index) {
    int len = str_len(str);
    if(f_index < len && s_index < len) {
        char ch = str[f_index];
        str[f_index] = str[s_index];
        str[s_index] = ch;
    }
}

//Q10
int alphanumeric(char* str) {
    int apha = 0, num = 0;
    int len = str_len(str);
    for(int i = 0; i < len; ++i) {
        switch (str[i]) {
            case 'A' ... 'Z':
            case 'a' ... 'z':
                apha = 1;
            break;
            case '0' ... '9':
                num = 1;
            break;
        }
        if(apha && num)
            return 1;
    }
    return 0;
}

int main() { 
    char str1[] = "Anjani 1Tiawri";
    char str2[] = "Abc";
    char ch = 'T';
    // printf("compare %s and %s %d", str1, str2, compare(str1, str2));
    // uppercase(str1);
    // lowercase(str1);
    // printf("%s", str1);
    // printf("%s total vowels %d", str1, vowel(str1));
    // printf("%s first occurrence %c index %d", str1, ch, first_occurrence(str1, ch));
    // printf("%s %c %d", str1, ch, find_char(str1, ch, 10, 19));
    // swap(str1,n 0, 13);
    // printf("%s", str1);
    printf("aphanumeric %d", alphanumeric(str1));
    printf("\n");
    return 0;
}