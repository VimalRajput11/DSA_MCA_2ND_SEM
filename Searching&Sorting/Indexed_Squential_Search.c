#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
void indexed_sequential_Search(int arr[], int n, int k);

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    printf("Enter the element to be searched: ");
    scanf("%d",&k);
    indexed_sequential_Search(arr,n,k);
    return 0;
}

void indexed_sequential_Search(int arr[],int n,int k){
    
    int gn = (int)sqrt(n); 
    if (gn < 1)
       gn = 1;
    int elements[gn+1], indices[gn+1], i, set = 0;
    int j = 0, ind = 0, start, end;
    for(i = 0; i < n; i += gn){
        elements[ind] = arr[i];
        indices[ind] = i;
        ind++;
    }
    if (indices[ind-1] != n-1) {
        elements[ind] = arr[n-1];
        indices[ind] = n-1;
        ind++;
    }
    if(k < elements[0]){
        printf("Element is not found");
        exit(0);
    } else {
        for(i = 1; i < ind; i++){
            if(k <= elements[i]){
                start = indices[i-1];
                end = indices[i]+1;
                set = 1;
                break;
            }
        }
    }
    if(set == 0){
        start = indices[ind-1];
        end = n;
    }
    for(i = start; i < end; i++){
        if(arr[i] == k){
            j = 1;
            break;
        }
    }
    if(j == 1){
        printf("Element is found at index %d", i);
    } else {
        printf("Element is not found");
    }
}