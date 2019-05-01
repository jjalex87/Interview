/* Return 1 if arr2[] is a subset of arr1[] */ 
bool isSubset(int arr1[], int arr2[], int m, int n) 
{ 
    int i = 0, j = 0; 
      
    if (m < n) 
       return 0; 
  
    sort(arr1, arr1 + m); 
    sort(arr2, arr2 + n); 
    while (i < n && j < m ) 
    { 
        if( arr1[j] <arr2[i] ) 
            j++; 
        else if( arr1[j] == arr2[i] ) 
        { 
            j++; 
            i++; 
        } 
        else if( arr1[j] > arr2[i] ) 
            return 0; 
    } 
   
    return  (i < n)? false : true; 
}  
  
/*Driver program to test above functions */
int main() 
{ 
    int arr1[] = {11, 1, 13, 21, 3, 7}; 
    int arr2[] = {11, 3, 7, 1}; 
    
    int m = sizeof(arr1)/sizeof(arr1[0]); 
    int n = sizeof(arr2)/sizeof(arr2[0]); 
  
    if(isSubset(arr1, arr2, m, n)) 
      printf("arr2[] is subset of arr1[] "); 
    else
      printf("arr2[] is not a subset of arr1[] ");       
  
    return 0; 
} 

/*
Other methods:
Method 1 (Simple)
Use two loops: The outer loop picks all the elements of arr2[] one by one. 
The inner loop linearly searches for the element picked by outer loop. 
If all elements are found then return 1, else return 0.

Method 2 (Use Sorting and Binary Search)
1) Sort arr1[] O(mLogm)
2) For each element of arr2[], do binary search for it in sorted arr1[].
         a) If the element is not found then return 0.
3) If all elements are present then return 1.
*/
