#include <stdio.h>

#define ARR_MAX_SIZE 10

int binary_search(int *arr, int low, int high, int data)
{
    int mid, index = -1;
    int comparisons = 0;
    
    while (low <= high) {
        comparisons++;
        mid = (low + high)/2;
        if (data == arr[mid]) {
            index =mid;
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
    
    int index = binary_search(arr, 0, (ARR_MAX_SIZE - 1), 78);
    
    if (index == -1) {
        printf("Element not found!");
    } else {
        printf("Element found at index: %d", index);
    }

    return 0;
}

Output:
Comparisons made: 3                                                                                                                            
Element found at index: 5 
