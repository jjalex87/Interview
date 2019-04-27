#include <stdio.h>

#define ARR_MAX_SIZE 10

int binary_search(int *arr, int low, int high, int data)
{
    int mid;
    
    while (low <= high) {
        mid = (low + high)/2;
        if (data == arr[mid]) {
            return (mid);
        } else if (data > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return (-1);
}

int main()
{
    int arr[ARR_MAX_SIZE] = {33, 45, 48, 67, 74, 78, 84, 88, 90, 99};
    
    int index = binary_search(arr, 0, (ARR_MAX_SIZE - 1), 45);
    
    if (index == -1) {
        printf("Element not found!");
    } else {
        printf("Element found at index: %d", index);
    }

    return 0;
}

Output:
Element found at index: 1
