#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

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

//Q2
void pattern(int n) {
	int total = 1, x = n;
	char str[n];
	while(x--) {
		total*=2;
	}
	for(int i = 0; i < total; ++i) {
		x = i;
		memset(str, '0', sizeof(str));
		str[n] = '\0';
		for(int j = n-1; x != 0; --j) {
			str[j] = x%2 ? '1' : '0';
			x/=2;
		}
		printf("%s\n", str);
	}

}

//Q3
void current_date_time() {
	time_t now = time(0);
	struct tm* local = localtime(&now);
	char date[20];
	strftime(date, sizeof(date), "%d-%m-%Y", local);
	printf("%s\n", date);
	printf("%02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);
}

//Q4
void arr_reverse() {
	int n;
	int* arr = NULL;
	int tmp, i;
	printf("Enter arr size: ");
	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));
	if(arr) {
		printf("Enter %d number: ", n);
		for(i = 0; i < n; ++i) 
			scanf("%d", &arr[i]);
		for(i = 0; i < n/2; ++i) {
			tmp = arr[i];
			arr[i] = arr[n-1-i];
			arr[n-1-i] = tmp;
		}
		for(i = 0; i < n; ++i) 
			printf("%d ", arr[i]);
		free(arr);
	}
}

//Q5
void series(int n, int a, int b, int c) {
	if(n != 0) {
		int next_term = a + b + c;
		printf("%d ", next_term);
		series(n-1, b, c, next_term);
	}
}

void print_series() {
	int n;
	int start_no[3];
	printf("Enter terms series print: ");
	scanf("%d", &n);
	printf("Enter 3 starting series no's: ");
	for(int i = 0; i < 3; ++i)
		scanf("%d", &start_no[i]);
	series(n, start_no[0], start_no[1], start_no[2]);
	printf("\n");
}

//Q6
typedef struct {
	float side1, side2, side3;
	float area;
} triangle;

void f6() {
	int n, i, j;
	float s;
	printf("Enter number of triangles: ");
	scanf("%d", &n);
	triangle tri[n];
	triangle tmp;
	for(int i = 0; i < n; ++i) {
		printf("Enter triangle %d three sides: ", i+1);
		scanf("%f%f%f", &tri[i].side1, &tri[i].side2, &tri[i].side3);
		s = (tri[i].side1 + tri[i].side2 + tri[i].side3)/2;
		// tri[i].area = sqrt(s*(s-tri[i].side1)*(s-tri[i].side2)*(s-tri[i].side3));
	}

	for(i = 0; i < n-1; ++i) {
		for(j = 0; j < n-1-i; ++j) {
			if(tri[j].area > tri[j+1].area) {
				tmp = tri[j];
				tri[j] = tri[j+1];
				tri[j+1] = tmp;
			}
		}
	}

	for(i = 0; i < n; ++i) 
		printf("%f %f %f\n", tri[i].side1, tri[i].side2, tri[i].side3);
}

void remove_dublicate(int* arr, int n) {
	int tmp[n], c = -1, i, j;
	for(i = 0; i < n; ++i) {
		for(j = 0; j <= c; ++j) {
			if(arr[i] == tmp[j])
				break;
		}		
		if(j > c)
			tmp[++c] = arr[i];
	}
	for(i = 0; i <= n; ++i) {
		if(i <= c)
			arr[i] = tmp[i];
		else
			arr[i] = 0;
		printf("%d ", arr[i]);
	}
}

int max_frequency(int* arr, int n) {
	int i, j, tmp, max_i, count = 0, max_count = 0;
	for(i = 0; i < n-1; ++i) {
		for(j = 0; j < n-1-i; ++j) {
			if(arr[j] > arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	for(i = 0; i < n; i = j) {
		count = 1;
		for(j = i+1; j < n; ++j) {
			if(arr[i] != arr[j])
				break;
			count++;
		}
		if(count > max_count) {
			max_count = count;
			max_i = i;
		}
	}
	return arr[max_i];
}

int is_prime(int num) {
	
	for(int i = 2; i <= num/2; ++i) {
		if(num%i == 0)
			return 0;
	}
	return 1;
}
int* create_prime_arr(int n) {
	int* arr = (int*)calloc(n, sizeof(int));
	int num = 2;
	for(int i = 0; i < n; ++i) {
		while(!is_prime(num))
			num++;
		arr[i] = num++;
	}
	return arr;
}

int main() {
    // system("clear");
	// char str[] = "ABCDEFG";
	// int x = combination(strlen(str), 6);
	// char** arr = string_combination(str, 6);
	// print_strings(arr, x);
	// pattern(4);
	// current_date_time();
	// arr_reverse();
	// print_series();
	// f6();
	// int arr[] = {3, 2, 1, 3, 3, 2};
	// remove_dublicate(arr, 5);
	// printf("%d\n", max_frequency(arr, 6));
	int* arr = create_prime_arr(5);
	for(int i = 0; i < 5; ++i) 
		printf("%d ", arr[i]);
	free(arr);
	// getchar();
	return 0;
}