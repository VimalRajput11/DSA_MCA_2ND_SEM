
#include<stdio.h>
void Merge_sort(int arr[], int left, int right);
void Merge(int arr[], int left, int mid, int right);

int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    Merge_sort(arr, 0, n - 1);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void Merge_sort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        Merge_sort(arr, left, mid);
        Merge_sort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}
void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}