#include <iostream>
#include <cstring>

using namespace std;

void sort(int arr[], int size, bool asc = true) {
    int lastIndex = size-1;
    int index, tmp;
    
    while(lastIndex) {
        index = 0;
        for(int i = 0; i < lastIndex; ++i) {
            if(asc) {
                if(arr[index] < arr[i+1])
                    index = i+1;
            }
            else {
                if(arr[index] > arr[i+1])
                    index = i+1;
            }   
        }
        if(index < lastIndex) {
            tmp = arr[lastIndex];
            arr[lastIndex] = arr[index];
            arr[index] = tmp;
        }
        lastIndex--;
    }
    for(index = 0; index < size; ++index)
        cout << arr[index] << " ";
    cout << endl;
}

void sortStrings(char (*arr)[20], int size, bool asc = true) {
    int lastIndex = size-1;
    int index;
    char tmp[20] = {'\0'};
    
    while(lastIndex) {
        index = 0;
        for(int i = 0; i < lastIndex; ++i) {
            if(asc) {
                if(strcmp(arr[index], arr[i+1]) < 0)
                    index = i+1;
            }
            else {
                if(strcmp(arr[index], arr[i+1]) > 0)
                    index = i+1;
            }   
        }
        if(index < lastIndex) {
            strcpy(tmp, arr[lastIndex]);
            strcpy(arr[lastIndex], arr[index]);
            strcpy(arr[index], tmp);
        }
        lastIndex--;
    }
    for(index = 0; index < size; ++index)
        cout << arr[index] << " ";
    cout << endl;
}

void rotate(int* arr, int size, int position = 1, int direction = 1) {
    int tmp;
    if(direction == 1) {
        while(position) {
            tmp = arr[size-1];
            for(int i = size-1; i > 0; --i) {
                arr[i] = arr[i-1];
            }
            arr[0] = tmp;
            position--;
        }
    }
    else if(direction == -1){
        while(position) {
            tmp = arr[0];
            for(int i = 0; i < size-1; ++i) {
                arr[i] = arr[i+1];
            }
            arr[size-1] = tmp;
            position--;
        }
    }

    for(int index = 0; index < size; ++index)
        cout << arr[index] << " ";
    cout << endl;

}

int LCM(int n1, int n2, int n3) {
    int d;
    if(n1 > n2) {
        if(n1 > n3)
            d = n1;
        else
            d = n3;
    }
    else if(n2 < n3) {
        d = n2;
    }
    else
        d = n3;

    while(d) {
        if(d%n1 == 0 && d%n2 == 0 && d%n3 == 0)
            break;
        d++;
    }
    return d;
}

int nextPrime(int num) {
    int i;
    num++;
    while(true) {
        for(i = 2; i < num; ++i) {
            if(num%i == 0)
                break;
        }
        if(i == num)
            break;
        num++;
    }
    return num;
}

void primeFactors(int num) {
    for(int i = 2; i <= num; i = nextPrime(i)) {
        if(num%i == 0)
            cout << i << " "; 
    }
}

int HCF(int n1, int n2) {
    int d;
    d = n1 < n2 ? n1/2 : n2/2;

    while(d > 1) {
        if(n1%d == 0 && n2%d == 0)
            break;
        --d;
    }
    return d;
}

//cuboid volume
int volume(int l, int b, int h) {
    return l*b*h;
}

//cone volume
float volume(int r, int h) {
    return (1/3.0f) * 3.14 * r * r * h;
}

//sphere volume
float volume(int r) {
    return (4/3.0f) * 3.14 * r * r * r;
}



int main() {
    // int arr[10] = {3, 7, 2, 0, 6, -3, 12, -1, 1, 5};
    int arr[10] = {3, 7, 2, 0, 1};
    // sort(arr, sizeof(arr)/sizeof(*arr), 0);

    // char arr[3][20] = { "shonu", "sella", "amish"}; 
    // sortStrings(arr, 3, 1);
    
    // rotate(arr, 5, 2, -1);
    // cout << LCM(12, 16, 19);
    // primeFactors(36);
    cout << HCF(13, 15);
    return 0;
}