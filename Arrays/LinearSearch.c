// Objective: Implementation of Linear Search in C
// This program demonstrates a simple linear search algorithm to find an element in an array.

#include <stdio.h>

// Function prototype
void linear_search(int arr[], int size, int target);

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
    printf("Enter the element to search: ");
    scanf("%d", &target);

    linear_search(arr, size, target);

    return 0;
}

// Function definition
void linear_search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            printf("Element found at index: %d\n", i);
            return;
        }
    }
    printf("Element not found in the array\n");
}