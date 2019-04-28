/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int list[MAX] = {1,8,4,6,0,3,5,2,7,9};

void display() {
   int i;
   printf("[");
	
   // navigate through all items 
   for(i = 0; i < MAX; i++) {
      printf("%d ",list[i]);
   }
	
   printf("]");
}

void bubbleSort() {
    int i, j, k, temp;
    int swapped = 0;
    
    for (i = 0, k = MAX-1; i < MAX - 1; i++) {
        swapped = 0;
        for (j = 0; j < k; j++) {
            if (list[j] > list[j+1]) {
                temp = list[j];
                list[j] = list[j+1]; 
                list[j+1] = temp;
                swapped = 1;
            }
        }
        k--;
        
        if (!swapped) {
            printf("\nArray is sorted now, breaking out of loop");
            break;
        }
        printf("\nIteration:%d Output Array: ", i+1);
        display();
    }
}

void main() {
   printf("Input Array: ");
   display();
	
   bubbleSort();
   printf("\nOutput Array: ");
   display();
}

Output:
Input Array: [1 8 4 6 0 3 5 2 7 9 ]                                                                                                          
Iteration:1 Output Array: [1 4 6 0 3 5 2 7 8 9 ]                                                                                             
Iteration:2 Output Array: [1 4 0 3 5 2 6 7 8 9 ]                                                                                             
Iteration:3 Output Array: [1 0 3 4 2 5 6 7 8 9 ]                                                                                             
Iteration:4 Output Array: [0 1 3 2 4 5 6 7 8 9 ]                                                                                             
Iteration:5 Output Array: [0 1 2 3 4 5 6 7 8 9 ]                                                                                             
Array is sorted now, breaking out of loop                                                                                                    
Output Array: [0 1 2 3 4 5 6 7 8 9 ] 
