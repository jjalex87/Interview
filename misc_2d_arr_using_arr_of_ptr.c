int main() 
{ 
    int r = 3, c = 4, i, j, count; 
  
    int *arr[r]; 
    for (i=0; i<r; i++) 
         arr[i] = (int *)malloc(c * sizeof(int)); 
  
    // Note that arr[i][j] is same as *(*(arr+i)+j) 
    count = 0; 
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count 
  
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         printf("%d ", arr[i][j]); 
  
    /* Code for further processing and free the  
      dynamically allocated memory */
  
   return 0; 
}

Output:
1 2 3 4 5 6 7 8 9 10 11 12
