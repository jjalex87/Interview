#include <stdio.h>
#include <stdlib.h>

/*
Merge sort is an out of place sorting technique based on divide and conquer technique. 
With worst-case time complexity being Ο(n log n), it is one of the most respected algorithms.

Merge sort first divides the whole array iteratively into equal halves unless the atomic values are achieved.
By definition, if there is only one element in the list, it is sorted.
Then, merge sort combines the smaller sorted lists keeping the new list sorted too.
*/

#define MAX_ARR_SIZE    7

int temp_arr[MAX_ARR_SIZE];

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *arr) {
   int i;
   printf("[");
	
   // navigate through all items 
   for(i = 0; i < MAX_ARR_SIZE; i++) {
      printf("%d ", arr[i]);
   }
	
   printf("]");
}

void display_range(int *arr, int low, int high)
{   
    int i;
    printf("[");
    
    // navigate through all items 
    for(i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("]");
}

void merge_list(int *arr, int low, int mid, int high)
{
    int l1, l2, i;
    for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if (arr[l1] <= arr[l2]) {
            temp_arr[i] = arr[l1++];
        } else {
            temp_arr[i] = arr[l2++];
        }
    }
    
    while(l1 <= mid) {
        temp_arr[i++] = arr[l1++];
    }
    
    while(l2 <= high) {
        temp_arr[i++] = arr[l2++];
    }
    
    for (i = low; i <= high; i++) {
        arr[i] = temp_arr[i];
    }
}

void merge_sort (int *arr, int low, int high)
{
    int i;
    if (low < high) {
        int mid = (low + high)/2;
        
        printf("\nComplete list before dividing: ");
        display_range(low, high);
        
        printf("\nFirst List: ");
        display_range(low, mid);
        
        printf("\nSecond List: ");
        display_range(mid + 1, high);
        
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge_list(low, mid, high);
        
        printf("\nList after merge: ");
        display_range(low, high);
    }
}

void main()
{
    int arr[MAX_ARR_SIZE] = {4,6,3,2,1,9,7};
    printf("\nGiven array: ");
    display(arr);
    
    merge_sort(arr, 0, MAX_ARR_SIZE - 1);

    printf("\nSorted array is: ");
    display(arr);
}

Output:
Given array: [4 6 3 2 1 9 7 ]                                                                                                                 
Complete list before dividing: [4 6 3 2 1 9 7 ]                                                                                               
First List: [4 6 3 2 ]                                                                                                                        
Second List: [1 9 7 ]                                                                                                                         
Complete list before dividing: [4 6 3 2 ]                                                                                                     
First List: [4 6 ]                                                                                                                            
Second List: [3 2 ]                                                                                                                           
Complete list before dividing: [4 6 ]                                                                                                         
First List: [4 ]                                                                                                                              
Second List: [6 ]                                                                                                                             
List after merge: [4 6 ]                                                                                                                      
Complete list before dividing: [3 2 ]                                                                                                         
First List: [3 ]                                                                                                                              
Second List: [2 ]                                                                                                                             
List after merge: [2 3 ]                                                                                                                      
List after merge: [2 3 4 6 ]                                                                                                                  
Complete list before dividing: [1 9 7 ]                                                                                                       
First List: [1 9 ]                                                                                                                            
Second List: [7 ]                                                                                                                             
Complete list before dividing: [1 9 ]                                                                                                         
First List: [1 ]                                                                                                                              
Second List: [9 ]                                                                                                                             
List after merge: [1 9 ]                                                                                                                      
List after merge: [1 7 9 ]                                                                                                                    
List after merge: [1 2 3 4 6 7 9 ]                                                                                                            
Sorted array is: [1 2 3 4 6 7 9 ]
