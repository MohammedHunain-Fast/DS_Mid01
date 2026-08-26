#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int j = i - 1;
        int x = arr[i];
        while(arr[j] > x && j > -1) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int main() {
    int a[] = {4, 11, 10, 0};
    insertionSort(a, size(a));
    for(int i = 0; i < size(a); i++) 
        cout << a[i] << " ";
    return 0;
}