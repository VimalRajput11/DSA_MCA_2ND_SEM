
#include <stdio.h>

int recursive_binary_search(int arr[], int start, int end, int target);

int main()
{
    int size, i, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements in sorted order: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = recursive_binary_search(arr, 0, size - 1, target);
    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array\n");
    }

    return 0;
}
 
int recursive_binary_search(int arr[], int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return recursive_binary_search(arr, mid + 1, end, target);
    }
    else
    {
        return recursive_binary_search(arr, start, mid - 1, target);
    }
}