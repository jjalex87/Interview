#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_SIZE    7
int arr[MAX_ARR_SIZE] = {4,6,3,2,1,9,7};

void display() {
   int i;
   printf("[");
	
   // navigate through all items 
   for(i = 0; i < MAX_ARR_SIZE; i++) {
      printf("%d ", arr[i]);
   }
	
   printf("]");
}

void insertion_sort ()
{
    int hole_pos;
    int value_to_insert;
    int i;

    for (i = 1; i < MAX_ARR_SIZE; i++) {
        hole_pos = i;
        value_to_insert = arr[i];
        
        while(hole_pos > 0 && arr[hole_pos-1] > value_to_insert) {
            arr[hole_pos] = arr[hole_pos - 1];
            hole_pos--;
            printf("\nItem moved: %d" , arr[hole_pos]);
        }
        
        if (hole_pos != i) {
            arr[hole_pos] = value_to_insert;
            printf("\nItem:%d inserted at position:%d", value_to_insert, hole_pos);
        }
        printf("\nIteration %d#: ", i);
        display();
    }
}

#define MAX_ARR_SIZE    7
void main()
{
    int i;
    printf("\nGiven array: ");
    display();
    
    insertion_sort();

    printf("\nSorted array is: ");
    display();
}

Output:
Given array: [4 6 3 2 1 9 7 ]                                                                                                                 
Iteration 1#: [4 6 3 2 1 9 7 ]                                                                                                                
Item moved: 6                                                                                                                                 
Item moved: 4                                                                                                                                 
Item:3 inserted at position:0                                                                                                                 
Iteration 2#: [3 4 6 2 1 9 7 ]                                                                                                                
Item moved: 6                                                                                                                                 
Item moved: 4                                                                                                                                 
Item moved: 3                                                                                                                                 
Item:2 inserted at position:0                                                                                                                 
Iteration 3#: [2 3 4 6 1 9 7 ]                                                                                                                
Item moved: 6                                                                                                                                 
Item moved: 4                                                                                                                                 
Item moved: 3                                                                                                                                 
Item moved: 2                                                                                                                                 
Item:1 inserted at position:0                                                                                                                 
Iteration 4#: [1 2 3 4 6 9 7 ]                                                                                                                
Iteration 5#: [1 2 3 4 6 9 7 ]                                                                                                                
Item moved: 9                                                                                                                                 
Item:7 inserted at position:5                                                                                                                 
Iteration 6#: [1 2 3 4 6 7 9 ]                                                                                                                
Sorted array is: [1 2 3 4 6 7 9 ]
