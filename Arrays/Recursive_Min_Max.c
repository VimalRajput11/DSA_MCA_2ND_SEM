#include <stdio.h>


void find_min_max_recursive(int arr[], int size, int index, int min, int max);

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

    int min = arr[0], max = arr[0];
    find_min_max_recursive(arr, size, 0, min, max);

    return 0;
}
    
void find_min_max_recursive(int arr[], int size, int index, int min, int max)
{
    if (index == size)
    {
        printf("Minimum element: %d\n", min);
        printf("Maximum element: %d\n", max);
        return;
    }

    if (arr[index] < min)
    {
        min = arr[index];
    }
    if (arr[index] > max)
    {
        max = arr[index];
    }

    find_min_max_recursive(arr, size, index + 1, min, max);
}