//Insertion sort in c
#include <stdio.h>

void Insertion_Sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
}
int main(){
    int arr[]={10,2,5,6,8,3,4,1,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Insertion_Sort(arr, n);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}