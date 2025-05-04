//implementation of recursive linear search in linked list
#include <stdio.h>

 // Function prototype
void linear_search(int arr[], int size, int target, int index);

int main()
{
    int size, i, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements in the array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be Search: ");
    scanf("%d", &target);
    linear_search(arr, size, target, 0);
    return 0;
}

// Function definition
void linear_search(int arr[], int size, int target, int index)
{
    if (index >= size)
    {
        printf("Element not found in the array\n");
        return;
    }
    if (arr[index] == target)
    {
        printf("Element found at index: %d\n", index);
        return;
    }
    linear_search(arr, size, target, index + 1);
}