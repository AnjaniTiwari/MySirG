#include <stdio.h>
#include <string.h>
//Q1
int palindrome(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len/2; ++i) {
        if(str[i] != str[len-1-i])
            return 0;
    }
    return 1;
}

//Q2
void trim_spaces_both_end(char str[]) {
    int len = strlen(str);
    int non_space = 0, i = 0;
    while(str[non_space] == ' ') non_space++;
    while(non_space < len) {
        str[i++] = str[non_space++];
    }
    non_space = i-1;
    while(str[non_space] == ' ') non_space--;
    str[non_space+1] = '\0';
}

//Q3
int word_count(char* str) {
    int count = 0;
    int len = strlen(str);
    if(str[0] == ' ' || str[len-1] == ' ') {
        trim_spaces_both_end(str);
        len = strlen(str);
    }
    for(int i = 0; i < len; ++i) {
        if(str[i] == ' ') {
            count++;
            while(str[i+1] == ' ') i++;
        }
    }
    if(count > 0)
        return count+1;
    return 0;
}

//Q4
void swap_words(char* str) {
    int len = strlen(str);
    int i, j, x;
    if(str[0] == ' ' || str[len-1] == ' ') {
        trim_spaces_both_end(str);
        len = strlen(str);
    }
    
    char str2[len];
    strcpy(str2, str);
    i = 0;
    x = 0;
    while(x <= len) {
        while(len-i-x > 0 && str2[len-i-x-1] != ' ') {
            i++;
        }

        for(int j = len-i-x; i != 0; j++, i--) {
            str[x] = str2[j];
            x++;
        }
        
        if(x < len) 
            str[x] = ' ';
        else
            str[x] = '\0';
        x++;
    }
}

//Q5
int case_insensitive_compare(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);     

    if(len1 == len2) {
        for(int i = 0; i < len1; ++i) {
            if(str1[i]-str2[i] != 32 &&
               str1[i]-str2[i] != -32 && 
               str1[i]-str2[i] != 0)
            return 0;
        }
        return 1;
    }
    else
        return 0;
}

//Q6
void charector_frequency(char* str) {
    int len = strlen(str);
    char str2[len];
    int i, j, x = -1, y, count;
    printf("Charector Frequency.\n");
    for(i = 0; i < len; ++i) {
        for(j = 0; j <= x; ++j)
            if(str[i] == str2[j])
                break;
        if(j > x) {
            y = i+1;
            count = 1;
            while(y < len) {
                if(str[i] == str[y])
                    count++;
                y++;
            }
            printf("%c - %d\n", str[i], count);
            x++;
            str2[x] = str[i];
        }
    }
}

//Q7
int find_word(char* str, char* word) {
    int s_len = strlen(str);
    int w_len = strlen(word);
    int j, x;
    if(w_len <= s_len) {
        for(int i = 0; i < s_len; i=j+1) {
            j = i;
            while(j < s_len && str[j] != ' ') {
                j++;
            }
            if(j-i == w_len) {
                for(x = 0; x < j-i; ++x)
                    if(str[i+x] != word[x])
                        break;
                if(x == j-i)
                    return 1;
            }
        }
    }       
    return 0; 
}

//Q8
void first_word_capital(char* str) {
    int len = strlen(str);
    int i = 0;
    do {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i]-=32;
        i++;
        while(i < len && str[i] != ' ') i++;
        i++;
    } while(i < len);
}

//Q9
void acronym_name(char* str) {
    int len = strlen(str);
    int i = 0, j = 0, x;
    int count = word_count(str);
    while(count) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i]-=32;
        if(count > 1) {
                j = i;
            while(str[j] != ' ') j++;
            x = i+1;
            while(j < len) {
                str[x] = str[j];
                x++;
                j++;
            }
            str[x] = '\0';
            len = x;
        }
        i+=2;
        count--;
    }
}

void concatenate(char* str1, int l, char* str2) {
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int i;

    if(l2 < l-l1) {
        str1[l1] = ' ';
        for(i = 0; i < l2; ++i) {
            str1[l1+1+i] = str2[i];
        }
        str1[l1+1+i] = '\0';
    }
}

int main() { 
    char str[30];
    char str2[20] = "AbC";
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    // printf("Enter a find string: ");
    // fgets(str2, sizeof(str2), stdin);
    // str2[strlen(str2)-1] = '\0';
    // printf("%s %d", str, palindrome(str));
    // printf("%s\n", str);
    // trim_spaces_both_end(str); 
    // printf("%s", str);
    printf("%s total words %d", str, word_count(str)); //check
    // swap_words(str);
    // printf("%s", str);
    // printf("%d", case_insensitive_compare(str, str2));
    // charector_frequency(str);
    // printf("%s find %s result- %d", str, str2, find_word(str, str2));
    // first_word_capital(str);
    // acronym_name(str);
    // concatenate(str, 30, str2);
    // printf("%s", str);
    printf("\n");
    return 0; 
}