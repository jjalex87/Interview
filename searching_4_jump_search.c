#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARR_MAX_SIZE 10
#define min(a,b) ((a < b) ? a : b)

int jump_search(int *arr, int size, int data) 
{ 
    // Finding block size to be jumped 
    int step = sqrt(size);
    int index = -1;
    int comparisons = 0;
    int block_start = step, prev_block_start = 0; 
  
    printf("Step size:%d\n", step);
    // Finding the block where element is 
    // present (if it is present) 
    
    while (arr[min(block_start,size)-1] < data) 
    {
        comparisons++;
        prev_block_start = block_start;
        block_start += step;
        if (prev_block_start >= (size - 1)) {
           return (-1); 
        }
    }
  
    // Doing a linear search for data in block 
    // beginning with block_start.
    while (arr[prev_block_start] < data) {
        prev_block_start++;
        comparisons++;
        if (prev_block_start == min(block_start, size)) {
            break;
        }
    }
    
    if (arr[prev_block_start] == data) {
        index = prev_block_start;
    }
    printf("Comparisons made: %d\n", comparisons);
    return (index); 
} 

int main()
{
    int arr[ARR_MAX_SIZE] = {33, 45, 48, 67, 74, 78, 84, 88, 90, 99};
    
    int index = jump_search(arr, ARR_MAX_SIZE, 78);
    
    if (index == -1) {
        printf("Element not found!");
    } else {
        printf("Element found at index: %d", index);
    }

    return 0;
}

Output:
Step size:3                                                                                                                                    
Comparisons made: 3                                                                                                                            
Element found at index: 5
