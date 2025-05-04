#include <stdio.h>

// Function prototype
void find_min_max(int arr[], int size);

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    find_min_max(arr, size);

    return 0;
}
 
// Function definition
void find_min_max(int arr[], int size)
{
    int min_val = arr[0];
    int max_val = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }

    printf("Minimum element: %d\n", min_val);
    printf("Maximum element: %d\n", max_val);
}