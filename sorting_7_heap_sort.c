#include <stdio.h>
#include <stdlib.h>

/*
Heap sort is a comparison based sorting technique based on Binary Heap data structure. 
It is similar to selection sort where we first find the maximum element and place the maximum element at the end. 
We repeat the same process for remaining element.

What is Binary Heap?
Let us first define a Complete Binary Tree. A complete binary tree is a binary tree in which every level, 
except possibly the last, is completely filled, and all nodes are as far left as possible (Source Wikipedia)

A Binary Heap is a Complete Binary Tree where items are stored in a special order such that value in a parent 
node is greater(or smaller) than the values in its two children nodes. The former is called as max heap and 
the latter is called min heap. The heap can be represented by binary tree or array.

Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap 
followed by reducing the size of heap by 1. Finally, heapify the root of tree.
3. Repeat above steps while size of heap is greater than 1.

How to build the heap?
Heapify procedure can be applied to a node only if its children nodes are heapified. 
So the heapification must be performed in the bottom up order.
*/

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

void heapify(int arr_size, int index)
{
    int l = 2*index + 1;
    int r = 2*index + 2;
    int largest = index;
    
    if (l < arr_size && arr[l] > arr[largest]) {
        largest = l;
    }
    
    if (r < arr_size && arr[r] > arr[largest]) {
        largest = r;
    }
    
    if (largest != index) {
        swap(&arr[largest], &arr[index]);
        heapify(arr_size, largest);
    }
}

/* function to sort arr using shellSort */
void heap_sort() 
{
    int i;
    int n = MAX_ARR_SIZE;
    
    for (i = n/2 - 1; i >= 0; i--) {
        heapify(n, i);
    }
    
    for (i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
} 

void main()
{
    printf("\nGiven array: ");
    display();
    
    heap_sort();

    printf("\nSorted array is: ");
    display();
}

Output:
Given array: [4 6 3 2 1 9 7 ]                                                                                                                                                  
Sorted array is: [1 2 3 4 6 7 9 ]
