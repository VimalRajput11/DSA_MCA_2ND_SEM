#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10
void bucketSort(float arr[], int n);
void printArray(float arr[], int n);
void insertionSort(float arr[], int n);

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float* buckets[BUCKET_SIZE];
    int bucketCount[BUCKET_SIZE];

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
        bucketCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int idx = arr[i] * BUCKET_SIZE;
        buckets[idx][bucketCount[idx]++] = arr[i];
    }

    for (int i = 0; i < BUCKET_SIZE; i++)
        insertionSort(buckets[i], bucketCount[i]);

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}
