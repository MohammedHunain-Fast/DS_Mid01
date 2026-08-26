#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int k = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[k]) {
                k = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
         
    }
}

int main() {
    int a[] = {11, 1, 9, 12,6};
    selectionSort(a, size(a));
    for(int i = 0; i < size(a); i++) {
        cout << a[i] << " ";
    }
    return 0;
}