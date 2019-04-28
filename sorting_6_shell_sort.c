#include <stdio.h>
#include <stdlib.h>

/*
Shell Sort is mainly a variation of Insertion Sort. 
In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved. 
The idea of shell sort is to allow exchange of far items. In shell sort, we make the array gap-sorted for a large value of gap. 
We keep reducing the value of gap until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element is sorted.

Worst case time complexity is O(n2) and best case complexity is O(nlog(n)).
*/

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

/* function to sort arr using shellSort */
int shell_sort() 
{
    int gap, i, hole_pos, value_to_insert;
    // Start with a big gap, then reduce the gap 
    for (gap = MAX_ARR_SIZE/2; gap > 0; gap /= 2) { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (i = gap; i < MAX_ARR_SIZE; i++) {
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            value_to_insert = arr[i];
            hole_pos = i;
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found
            for (;hole_pos >= gap && arr[hole_pos - gap] > value_to_insert; hole_pos -= gap) {
                printf("\nMoving item:%d to index:%d", arr[hole_pos - gap], hole_pos);
                arr[hole_pos] = arr[hole_pos - gap];
            }
              
            //  put temp (the original a[i]) in its correct location 
            printf("\nItem:%d inserted in hole position:%d", value_to_insert, hole_pos);
            arr[hole_pos] = value_to_insert; 
            
            printf("\nArray: ");
            display();
        } 
    } 
    return 0; 
} 

void main()
{
    printf("\nGiven array: ");
    display();
    
    shell_sort();

    printf("\nSorted array is: ");
    display();
}

Output:
Given array: [4 6 3 2 1 9 7 ]                                                                                                                                                  
Moving item:4 to index:3                                                                                                                                                       
Item:2 inserted in hole position:0                                                                                                                                             
Array: [2 6 3 4 1 9 7 ]                                                                                                                                                        
Moving item:6 to index:4                                                                                                                                                       
Item:1 inserted in hole position:1                                                                                                                                             
Array: [2 1 3 4 6 9 7 ]                                                                                                                                                        
Item:9 inserted in hole position:5                                                                                                                                             
Array: [2 1 3 4 6 9 7 ]                                                                                                                                                        
Item:7 inserted in hole position:6                                                                                                                                             
Array: [2 1 3 4 6 9 7 ]                                                                                                                                                        
Moving item:2 to index:1                                                                                                                                                       
Item:1 inserted in hole position:0                                                                                                                                             
Array: [1 2 3 4 6 9 7 ]                                                                                                                                                        
Item:3 inserted in hole position:2                                                                                                                                             
Array: [1 2 3 4 6 9 7 ]                                                                                                                                                        
Item:4 inserted in hole position:3                                                                                                                                             
Array: [1 2 3 4 6 9 7 ]                                                                                                                                                        
Item:6 inserted in hole position:4                                                                                                                                             
Array: [1 2 3 4 6 9 7 ]                                                                                                                                                        
Item:9 inserted in hole position:5                                                                                                                                             
Array: [1 2 3 4 6 9 7 ]                                                                                                                                                        
Moving item:9 to index:6                                                                                                                                                       
Item:7 inserted in hole position:5                                                                                                                                             
Array: [1 2 3 4 6 7 9 ]                                                                                                                                                        
Sorted array is: [1 2 3 4 6 7 9 ]  
