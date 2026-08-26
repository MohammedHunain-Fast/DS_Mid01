#include <iostream>

using namespace std;


void BubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        bool flag = false;                          // adding flag for swap, to make it adaptive
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;                
            }
        }
        if(flag == false) break;            // if now swaps are performed the loop breaks
    }
}
int main() {
    int a[] = {5, 2, 3, 7, 1, 8};
    BubbleSort(a, size(a));
    for(int i = 0; i < size(a); i++) {
        cout << a[i] << " ";
    }
    return 0;
}