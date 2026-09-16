#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Q1
int fact(int num) {
    if(num == 0)
        return 1;
    return num*fact(num-1);
}

int combination(int n, int r) {
    return fact(n)/(fact(r)*fact(n-r));
}

void left_shift(char* arr, int i, int* len) {
	if(i-1 >= 0) {
		while(i < *len)
			arr[i-1] = arr[i++];
		arr[i-1] = '\0';
		*len = i-1;
	}
	else
		*len = 0;
}

void str_cpy(char* str, char* str2, int i, int j) {
	int x = 0;
	while(i < j) {
		str[x++] = str2[i++];
	}
}

void cpy(char* temp, int *len, char* str, int r) {
	int i, j, len2 = strlen(str);
	int x = (*len)-2;
	RECHECK:
	for(i = 0; (x >= 0) && (i < len2); ++i) {
		if(temp[x] == str[i]) {
			if((len2-(i+1))+x >= r) {
				for(j = x, ++i; i < len2; ++i, ++j)
					temp[j] = str[i];
				*len = strlen(temp);
			}
			else {
            	--x;
            	goto RECHECK;
			}
		}
	}
}

char** string_combination(char* str, int r) {
	int len = strlen(str);
	int x = combination(len, r);
	char** arr = (char**)calloc(x, sizeof(char*));
	int i, j, z = 0;
	char temp[len];

	strcpy(temp, str);
	while(len >= r) {
		while(len >= r) {
			for(j = r-1; j < len; ++j) {
				arr[z] = (char*)calloc(r+1, sizeof(char));
				str_cpy(arr[z], temp, 0, r-1);
				arr[z++][r-1] = temp[j];
			}
			left_shift(temp, r-1, &len);
		}
		cpy(temp, &len, str, r);
	}

	return arr;
}

void print_strings(char** str, int x) {
    for(int i = 0; i < x; ++i) {
		printf("%2d - %s\n", i+1, str[i]);
        free(str[i]);
        str[i] = NULL;
    }
    free(str);
    str = NULL;
}

int main() {
    system("clear");
	char str[] = "ABCDEFG";
	int x = combination(strlen(str), 6);
	char** arr = string_combination(str, 6);
	print_strings(arr, x);
	getchar();
	return 0;
}