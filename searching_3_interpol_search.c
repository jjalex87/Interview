#include <stdio.h>
#include <stdlib.h>

#define ARR_MAX_SIZE 10

int interpol_search(int *arr, int low, int high, int data)
{
    int mid, index = -1;
    int comparisons = 0;
    
    while (low <= high) {
        comparisons++;
        /* IMPORTANT: Take care of braces as it makes a difference in 
         * computation. (double)x != (double)(x) */
        mid = low + (((double)(high - low)/(arr[high] - arr[low])) * (data - arr[low]));
        printf("high :%d arr[high] :%d\n", high, arr[high]);
        printf("low  :%d arr[low]  :%d\n", low, arr[low]);
        printf("mid:%d\n", mid);
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
high :9 arr[high] :99                                                                                                                          
low  :0 arr[low]  :33                                                                                                                          
mid:6                                                                                                                                          
high :5 arr[high] :78                                                                                                                          
low  :0 arr[low]  :33                                                                                                                          
mid:5                                                                                                                                          
Comparisons made: 2                                                                                                                            
Element found at index: 5
