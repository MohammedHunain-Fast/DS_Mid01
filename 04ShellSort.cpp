#include <iostream>

using namespace std;

void shellSort(int arr[], int n) {
    for(int gap = n / 2; gap >= 1; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int x = arr[i];
            int j = i - gap;
            while(j > -1 && arr[j] > x) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = x;
        }
    }
}

int main() {
    int a[] = {12, 3, 5, 1, 0, 23, 55, 11, 1, 9, 6};
    shellSort(a, size(a));
    for(int i = 0; i < size(a); i++) {
        cout << a[i] << " ";
    }
    return 0;
}