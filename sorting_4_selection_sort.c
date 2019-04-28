#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_SIZE    7
int arr[MAX_ARR_SIZE] = {4,6,3,2,1,9,7};

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void display() {
   int i;
   printf("[");
	
   // navigate through all items 
   for(i = 0; i < MAX_ARR_SIZE; i++) {
      printf("%d ", arr[i]);
   }
	
   printf("]");
}

void selection_sort ()
{
    int i, j, min, min_index;

    for (i = 0; i < MAX_ARR_SIZE-1; i++) {
        min_index = i + 1;
        min = arr[min_index];
        for (j = i+1; j < MAX_ARR_SIZE; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        
        if (arr[i] > arr[min_index]) {
            printf("\nSwapping %d and %d", arr[i], arr[min_index]);
            swap(&arr[i], &arr[min_index]);
        }
        
        printf("\nIteration %d#: ", i+1);
        display();
    }
}

void main()
{
    printf("\nGiven array: ");
    display();
    
    selection_sort();

    printf("\nSorted array is: ");
    display();
}

Output:
Given array: [4 6 3 2 1 9 7 ]                                                                                                                 
Swapping 4 and 1                                                                                                                              
Iteration 1#: [1 6 3 2 4 9 7 ]                                                                                                                
Swapping 6 and 2                                                                                                                              
Iteration 2#: [1 2 3 6 4 9 7 ]                                                                                                                
Iteration 3#: [1 2 3 6 4 9 7 ]                                                                                                                
Swapping 6 and 4                                                                                                                              
Iteration 4#: [1 2 3 4 6 9 7 ]                                                                                                                
Iteration 5#: [1 2 3 4 6 9 7 ]                                                                                                                
Swapping 9 and 7                                                                                                                              
Iteration 6#: [1 2 3 4 6 7 9 ]                                                                                                                
Sorted array is: [1 2 3 4 6 7 9 ]
