 #include <stdio.h>

// Function prototype
void Binary_Search(int arr[], int size, int target);

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

    Binary_Search(arr, size, target);

    return 0;
}

// Function definition
void Binary_Search(int arr[], int size, int target)
{
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            printf("Element found at index: %d\n", mid);
            return;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("Element not found in the array\n");
}
