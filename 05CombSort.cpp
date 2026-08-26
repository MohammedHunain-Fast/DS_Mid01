#include <iostream>

using namespace std;

void combSort(int arr[], int n) {
    int gap = n;
    bool flag = false;
    while(gap > 1 || flag == true) {
        gap /= 1.3;
        if(gap < 1) gap = 1;
        flag = false;
        for(int j = 0; j < n - gap; j++) {
            if(arr[j] > arr[j + gap]) {
                int temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;
                flag = true;
            }
        }
    }
}

int main() {
    int a[] = {5, 2, 3, 7, 1, 8, 6, 9, 0};
    combSort(a, size(a));
    for(int i = 0; i < size(a); i++) {
        cout << a[i] << " ";
    }
    return 0;
}