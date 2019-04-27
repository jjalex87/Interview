#include <stdio.h>
#include <stdlib.h>

#define ARR_MAX_SIZE 10

int interpol_search(int *arr, int low, int high, int data)
{
    int mid, index = -1;
    int comparisons = 0;
    
    while (low <= high) {
        comparisons++;
        mid = low + (((double)((high - low)/(arr[high] - arr[low]))) * (data - arr[low]));
        if (data == arr[mid]) {
            index = mid;
            break;
        } else if (data > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Comparisons made: %d\n", comparisons);
    return (index);
}

int main()
{
    int arr[ARR_MAX_SIZE] = {33, 45, 48, 67, 74, 78, 84, 88, 90, 99};
    
    int index = interpol_search(arr, 0, (ARR_MAX_SIZE - 1), 78);
    
    if (index == -1) {
        printf("Element not found!");
    } else {
        printf("Element found at index: %d", index);
    }

    return 0;
}

Output:
Comparisons made: 6                                                                                                                              
Element found at index: 5
