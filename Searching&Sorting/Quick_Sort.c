#include<stdio.h>
void Quick_Sort(int arr[], int low, int high);
int Hoare_partition(int arr[], int low, int high);

int main(){
    int arr[]={10,2,5,6,8,3,4,1,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Quick_Sort(arr, 0, n-1);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void Quick_Sort(int arr[], int low, int high){
    if(low < high){
        int p = Hoare_partition(arr, low, high);
        Quick_Sort(arr, low, p);
        Quick_Sort(arr, p + 1, high);
    }
}

int Hoare_partition(int arr[], int low, int high){
    int x = arr[low];
    int i = low - 1;
    int j = high + 1;
    while(1){
        do{
            j = j - 1;
        } while(arr[j] > x);
        do{
            i = i + 1;
        } while(arr[i] < x);
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }else{
            return j;
        }
    }
}