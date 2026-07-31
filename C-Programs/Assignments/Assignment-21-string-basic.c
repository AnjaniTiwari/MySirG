#include <stdio.h>

//Q1
int str_len(char* str) {
    int len;
    for(len = 0; str[len]; ++len);
    return len;
}

//Q2
int occurrence_count(char* str, char ch) {
    int count = 0;
    for(int i = 0; str[i]; ++i) {
        if(str[i] == ch)
            count++;
    }
    return count;
}

//Q3
int vowels_count(char* str) {
    int count = 0;
    char vowels_list[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    for(int i = 0; str[i]; ++i) {
        for(int j = 0; j < str_len(vowels_list); ++j) {
            if(str[i] == vowels_list[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

//Q4
int space_count(char* str) {
    int count = 0;
    for(int i = 0; str[i]; ++i) {
        if(str[i] == ' ')
            count++;
    }
    return count;
}

//Q5
void uppercase(char* str, char* str2) {
    int i;
    for(i = 0; str[i]; ++i) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str2[i] = str[i]-32;
        else
            str2[i] = str[i];
    }
    str2[i] = '\0';
}

//Q6
void lowercase(char* str, char* str2) {
    int i;
    for(i = 0; str[i]; ++i) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str2[i] = str[i]+32;
        else
            str2[i] = str[i];
    }
    str2[i] = '\0';
}

//Q7
void reverse(char* str) {
    char temp;
    int len = str_len(str);
    for(int i = 0; i < len/2; ++i) {
        temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

//Q8
void alphabets_digit_special_charector_count(char* str) {
    int alphabets = 0, digits = 0, special = 0;
    for(int i = 0; str[i]; ++i) {
        switch (str[i]) {
            case 'A' ... 'Z':
            case 'a' ... 'z':
                alphabets++;
            break;
            case '0' ... '9':
                digits++;
            break;
            default:
                special++;
        }
    }
    printf("alphabets = %d\ndigits = %d\nspecial charectors = %d\n", alphabets, digits, special);
}

//Q9
void str_cpy(char* src, char* dst, int dst_len) {
    int i;
    for(i = 0; i < str_len(src) && i < dst_len-1; ++i)
        dst[i] = src[i];
    dst[i] = '\0';
}

//Q10
int first_occurrence(char* str, char ch) {
    for(int i = 0; str[i]; ++i) {
        if(str[i] == ch)
            return i+1;
    }
    return -1;
}

int main() {
    char str[] = "Anjan0i Tiwa2ri1";
    char str2[str_len(str)+1];
    char ch = 'i';
    system("clear");
    // printf("len = %d\n", str_len(str));
    // printf("charector \'%c\' occurrence in \"%s\" = %d\n", ch, str, occurrence_count(str, ch));
    // printf("%s  vowels count %d\n", str, vowels_count(str));
    // printf("%s  space count %d\n", str, space_count(str));
    // uppercase(str, str2);
    // printf("%s to uppercase %s\n", str, str2);
    // lowercase(str, str2);
    // printf("%s to lowercase %s\n", str, str2);
    // reverse(str);
    // printf("%s\n", str);
    alphabets_digit_special_charector_count(str);
    // str_cpy(str, str2, str_len(str)+1);
    // printf("src %s dst %s\n", str, str2);
    // printf("First occurrence of %c index is %d\n", ch, first_occurrence(str, ch));
    return 0;
}