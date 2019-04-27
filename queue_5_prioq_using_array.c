#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE  20
#define TRUE            1
#define FALSE           0

// Array element  
typedef struct q_elem_ { 
    int data;    
    int prio; /* Lower values indicate higher priority */
} q_elem_t; 

q_elem_t queue[MAX_QUEUE_SIZE];

int front = 0;
int rear = 0;

bool is_queue_full()
{
    return (rear == MAX_QUEUE_SIZE);
}

bool is_queue_empty()
{
    return (front == rear);
}

bool enqueue(int data, int prio)
{
    int i, j;
    
    if (is_queue_full()) {
        printf("\nERROR: Queue is full!");
        return (FALSE);
    }
    
    if (is_queue_empty()) {
        queue[rear].data = data;
        queue[rear].prio = prio;
        rear++;
        return (TRUE);
    }
    
    for (i = 0; i < rear; i++) {
        if (queue[i].prio > prio) {
            /* i is the index where the new element should be inserted 
             * All existing elements starting from index i should be 
             * shifted by one position right */
            for (j = rear; j > i; j--) {
                queue[j].data = queue[j-1].data;
                queue[j].prio = queue[j-1].prio;
            }
            queue[j].data = data;
            queue[j].prio = prio;
            rear++;
            return (TRUE);
        }
    }
    queue[i].data = data;
    queue[i].prio = prio;
    rear++;
    return (TRUE);
}

void dequeue(int *data, int *prio)
{
    int i;
    
    if (is_queue_empty()) {
        printf("\nERROR: Queue is empty!");
        return;
    }
    
    
    *data = queue[front].data;
    *prio = queue[front].prio;
    
    for (i = 0; i < rear - 1; i++) {
        queue[i].data = queue[i + 1].data;
        queue[i].prio = queue[i + 1].prio;
    }
    rear--;
}

void print_queue()
{
    int i;
    if (is_queue_empty()) {
        printf("Queue is empty!");
        return;
    }
    
    for (i = 0; i < rear; i++) {
        printf("[%d,%d] ", queue[i].data, queue[i].prio);
    }
    printf("\nfront:%d rear:%d", front, rear);
}


int main()
{
    int i, num, prio;
    
    printf("Queue elements: ");
    print_queue();
    
    for (i = 0; i < 5; i++) {
        enqueue(i , i);
        printf("\nQueue elements after insertion: ");
        print_queue();
    }
    
    for (i = 0; i < 3; i++) {
        dequeue(&num, &prio);
        printf("\nDequeued 1 element: [%d,%d]", num, prio);
    }
    
    printf("\nQueue elements after dequeue: ");
    print_queue();
    
    for (i = 0; i < 5; i++) {
        enqueue(i, i%2);
        printf("\nQueue elements after insertion: ");
        print_queue();
    }
    
    for (i = 0; i < 2; i++) {
        dequeue(&num, &prio);
        printf("\nDequeued 1 element: [%d,%d]", num, prio);
    }

    printf("\nQueue elements after dequeue: ");
    print_queue();

    return 0;
}

Output:
Queue elements: Queue is empty!                                                                                                                 
Queue elements after insertion: [0,0]                                                                                                           
front:0 rear:1                                                                                                                                  
Queue elements after insertion: [0,0] [1,1]                                                                                                     
front:0 rear:2                                                                                                                                  
Queue elements after insertion: [0,0] [1,1] [2,2]                                                                                               
front:0 rear:3                                                                                                                                  
Queue elements after insertion: [0,0] [1,1] [2,2] [3,3]                                                                                         
front:0 rear:4                                                                                                                                  
Queue elements after insertion: [0,0] [1,1] [2,2] [3,3] [4,4]                                                                                   
front:0 rear:5                                                                                                                                  
Dequeued 1 element: [0,0]                                                                                                                       
Dequeued 1 element: [1,1]                                                                                                                       
Dequeued 1 element: [2,2]                                                                                                                       
Queue elements after dequeue: [3,3] [4,4]                                                                                                       
front:0 rear:2                                                                                                                                  
Queue elements after insertion: [0,0] [3,3] [4,4]                                                                                               
front:0 rear:3                                                                                                                                  
Queue elements after insertion: [0,0] [1,1] [3,3] [4,4]                                                                                         
front:0 rear:4                                                                                                                                  
Queue elements after insertion: [0,0] [2,0] [1,1] [3,3] [4,4]                                                                                   
front:0 rear:5                                                                                                                                  
Queue elements after insertion: [0,0] [2,0] [1,1] [3,1] [3,3] [4,4]                                                                             
front:0 rear:6                                                                                                                                  
Queue elements after insertion: [0,0] [2,0] [4,0] [1,1] [3,1] [3,3] [4,4]                                                                       
front:0 rear:7                                                                                                                                  
Dequeued 1 element: [0,0]                                                                                                                       
Dequeued 1 element: [2,0]                                                                                                                       
Queue elements after dequeue: [4,0] [1,1] [3,1] [3,3] [4,4]
front:0 rear:5
