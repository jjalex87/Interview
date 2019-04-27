/******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <stdio.h>

#define ARR_MAX_SIZE    10

int linear_search(int *arr, int size, int data)
{
    int i = 0, comparisons = 0;
    int index = -1;
    
    for (i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == data) {
            index = i;
            break;
        }
    }
    
    printf("Comparisons made: %d\n", comparisons);
    return (index);
}

int main()
{
    int arr[ARR_MAX_SIZE] = {33, 45, 48, 67, 74, 78, 84, 88, 90, 99};
    
    int index = linear_search(arr, ARR_MAX_SIZE, 78);
    
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
