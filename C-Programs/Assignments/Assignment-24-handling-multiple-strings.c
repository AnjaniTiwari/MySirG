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
void vowel_count(char (*p)[50], int size) {
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
    int i, j, k, len, null_count;
    for(i = 0; i < size; ++i) {
        j = i+1;
        while(j < size) {
            if(case_insensitive_compare(str[i], str[j])) {
                str[j][0] = '\0';
            }
            j++;
        }
        j = i+1;
        while(j < size) {
            if(str[j][0] == '\0') {
                k = j;
                null_count = 1;
                while(k < size-1) {
                    if(str[k+1] != '\0') 
                        strcpy(str[k], str[k+1]);
                    else
                        null_count++;
                    k++;   
                } 
                str[k][0] = '\0';
                size-=null_count;
            }
            j++;
        }
    }
}

//Q6
void spearate_ending_s_words(char* str1, char (*str2)[50], int size) {
    int f_pos = 0, i, j, k = 0, len = strlen(str1);
    for(i = 0; i < len; ++i) { 
        if(str1[i+1] == ' ' || str1[i+1] == '\0') {
            if(str1[i] == 'S' || str1[i] == 's') {
               j = 0;
                while(j <= i-f_pos) {
                   str2[k][j] = str1[f_pos+1+j];
                   j++;  
               }
               str2[k][j] = '\0';
               k++;
            }
            f_pos = i+1;
        }
    }
}

//Q7
void most_repeating(char (*str)[50], int size) {
    int i, j, len;
    char ch[128] = {'\0'};

    for(i = 0; i < size; ++i) {
        len = strlen(str[i]);
        for(j = 0; j < len; ++j) {
            ch[str[i][j]]++;
        }
    }

    len = 1;
    for(i = 0; i < 128; ++i) {
        if(len < ch[i]) {
            j = i;
            len = ch[i];
        }
    }
    printf("most repeated %c - %d", j, ch[j]);
}

//Q8
int anagram_string(char (*str)[50], int size) {
    int i, j, k, len;
    char ch[2][128] = {'\0'};

    for(i = 0; i < size; ++i) {
        len = strlen(str[i]);
        for(j = 0; j < len; ++j) {
            ch[i][str[i][j]]++;
        }
    }
    

    for(i = 0; i < 128; ++i) {
        if(ch[0][i] != '\0' || ch[1][i] != '\0')
            printf("%c - %d | %c - %d\n", i, ch[0][i], i, ch[1][i]);
        if(ch[0][i] != ch[1][i])
            return 0;
    }
    return 1;


}

//Q9
void spearate_start_a_words(char* str1, char (*str2)[50], int size) {
    int word_len, s_pos, i, j, k = 0, len = strlen(str1);
    for(i = 0; i < len; ++i) {
        while(str1[i] == ' ') ++i; 
        s_pos = i;
        word_len = 0;
        while(i <= len && str1[i+1] != ' ' && str1[i+1] != '\0') {
            i++;    
            word_len++;
        }
        if(str1[s_pos] == 'A' || str1[s_pos] == 'a') {
            for(j = 0; j <= word_len; ++j) {
                str2[k][j] = str1[s_pos+j];
            } 
            str2[k][j] = '\0';
            k++;
            i++;
        }
    }
}

//Q10
int gmail_count(char (*str)[50], int size) {
    int i, j, len, count = 0;
    char cmp[] = "gmail.com";
    for(i = 0; i < size; ++i) {
        len = strlen(str[i]);
        if(len-9 > 0) {
            if(case_insensitive_compare(&str[i][len-9], cmp))
                count++;
        }
    }
    return count;
}

int main() {
    char str[20][50] = {'\0'};
    char *str2 = "  ramesh likes cars    and   plays games  ";
    system("clear");
    input_string(str, 3);
    // vowel_count(str, 5);
    // sort_city_name(str, 5);
    // store_char(str, 20, str2, strlen(str2));
    // remove_duplicate(str, 5);
    // spearate_ending_s_words(str2, str, 20);
    // printf("anagram string %d\n", anagram_string(str, 2));
    // spearate_start_a_words(str2, str, 20);
    printf("Total gmail in list : %d", gmail_count(str, 3));;
    // print_string(str, 3);
    printf("\n");
    return 0;
}