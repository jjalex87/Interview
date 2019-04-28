#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_SIZE    7

void swap (int *a, int *b)
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

int partition (int arr[], int low, int high, int pivot)
{
    int left = low - 1, right = high;

    printf("\nEnter partition(), low:%d high:%d pivot:%d", low,high,pivot);
    while (1) {
        while(arr[++left] < pivot);
        while(right > 0 && arr[--right] > pivot);
        
        printf("\nleft:%d right:%d", left, right);
        if (left >= right) {
            break;
        } else {
            printf("\nItem swapped :%d,%d", arr[left], arr[right]);
            swap(&arr[left], &arr[right]);
        }
    }
    printf("\nPivot swapped :%d,%d", arr[left], arr[high]);
    swap(&arr[left], &arr[high]);
    
    printf("\nUpdated Array: "); 
    display(arr);
   
    return (left);
}

void quicksort (int arr[], int low, int high)
{
    int pivot;
    int partition_point;

    if (low < high) {
        pivot = arr[high];
        partition_point = partition(arr, low, high, pivot);
        quicksort(arr, low, partition_point - 1);
        quicksort(arr, partition_point + 1, high);
    }
}

#define MAX_ARR_SIZE    7
void main()
{
    int i, arr[MAX_ARR_SIZE] = {4,6,3,2,1,9,7};

    quicksort(arr, 0, MAX_ARR_SIZE-1);

    printf("\nSorted array is: ");
    for (i = 0; i < MAX_ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

Output:
Enter partition(), low:0 high:6 pivot:7                                                                                                          
left:5 right:4                                                                                                                                   
Pivot swapped :9,7                                                                                                                               
Updated Array: [4 6 3 2 1 7 9 ]                                                                                                                  
Enter partition(), low:0 high:4 pivot:1                                                                                                          
left:0 right:0                                                                                                                                   
Pivot swapped :4,1                                                                                                                               
Updated Array: [1 6 3 2 4 7 9 ]                                                                                                                  
Enter partition(), low:1 high:4 pivot:4                                                                                                          
left:1 right:3                                                                                                                                   
Item swapped :6,2                                                                                                                                
left:3 right:2                                                                                                                                   
Pivot swapped :6,4                                                                                                                               
Updated Array: [1 2 3 4 6 7 9 ]                                                                                                                  
Enter partition(), low:1 high:2 pivot:3                                                                                                          
left:2 right:1                                                                                                                                   
Pivot swapped :3,3                                                                                                                               
Updated Array: [1 2 3 4 6 7 9 ]                                                                                                                  
Sorted array is: 1 2 3 4 6 7 9  
