/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int find(int *arr, int size, int data)
{
    int i = 0;
    
    for (i = 0; i < size; i++) {
        if (arr[i] == data) {
            return (i);
        }
    }
    return (-1);
}

int main()
{
    int size, *arr, i, data;
    printf("\nEnter array size: ");
    scanf("%d", &size);
    printf("\nEnter array elements (press enter after each element):\n");
    
    arr = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nEnter element to search: ");
    scanf("%d", &data);
    
    //find location of 1
    int location = find(arr, size, data);
    
    // if element was found 
    if(location != -1) {
        printf("\nElement found at index: %d" ,(location));
    } else {
        printf("Element not found.");
    }

    return 0;
}

Output:
Enter array size: 5                                                                                                                              
                                                                                                                                                 
Enter array elements (press enter after each element):                                                                                           
1                                                                                                                                                
2                                                                                                                                                
3                                                                                                                                                
4                                                                                                                                                
5                                                                                                                                                
                                                                                                                                                 
Enter element to search: 4                                                                                                                       
                                                                                                                                                 
Element found at index: 3  
