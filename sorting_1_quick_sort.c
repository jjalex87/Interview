#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high)
{
    int pivot, i, j;

    pivot = arr[high];
    i = low - 1;

    for (j = low; j <= high -1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

void quicksort (int arr[], int low, int high)
{
    int pivot;

    if (low < high) {
        pivot = partition(arr, low, high);

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void main()
{
    int n, arr[20], i;

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1);

    printf("\nSorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
