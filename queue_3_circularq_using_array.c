/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE  5
#define TRUE            1
#define FALSE           0

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

bool is_queue_full()
{
    if ((front == 0 && rear == MAX_QUEUE_SIZE - 1) || (rear == front - 1)) {
        return (TRUE);
    }
    return (FALSE);
}

bool is_queue_empty()
{
    return (front == -1);
}

bool enqueue(int num)
{
    if (!is_queue_full()) {
        if (front == -1) { 
            front = rear = 0;
        } else if (rear == MAX_QUEUE_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = num;
        return (TRUE);
    } else {
        printf("\nERROR: Queue is full!");
        return (FALSE);
    }
}

int dequeue()
{
    int num = -1;
    if (!is_queue_empty()) {
        num = queue[front];
        queue[front] = -1;
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_QUEUE_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    } else {
        printf("\nERROR: Queue is empty!");
    }
    return (num);
}

void print_queue()
{
    int i;
    if (is_queue_empty()) {
        printf("Queue is empty!");
        return;
    }

    if (front <= rear) {    
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (i = front; i < MAX_QUEUE_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\nfront:%d rear:%d", front, rear);
}


int main()
{
    int i, size = 0, result;
    char infix[30], postfix[30];
    
    printf("Queue elements: ");
    print_queue();
    for (i = 0; i < 5; i++) {
        enqueue(i);
    }
    printf("\nQueue elements after insertion: ");
    print_queue();
    
    printf("\nDequeued 1 element: %d", dequeue());
    printf("\nDequeued 1 element: %d", dequeue());
    printf("\nDequeued 1 element: %d", dequeue());
    printf("\nQueue elements after dequeue: ");
    print_queue();
    
    for (i = 0; i < 5; i++) {
        enqueue(i);
    }
    printf("\nQueue elements after insertion: ");
    print_queue();
    printf("\nDequeued 1 element: %d", dequeue());
    printf("\nDequeued 1 element: %d", dequeue());
    printf("\nQueue elements after dequeue: ");
    print_queue();

    return 0;
}

Output:
Queue elements: Queue is empty!                                                                                                               
Queue elements after insertion: 0 1 2 3 4                                                                                                     
front:0 rear:4                                                                                                                                
Dequeued 1 element: 0                                                                                                                         
Dequeued 1 element: 1                                                                                                                         
Dequeued 1 element: 2                                                                                                                         
Queue elements after dequeue: 3 4                                                                                                             
front:3 rear:4                                                                                                                                
ERROR: Queue is full!                                                                                                                         
ERROR: Queue is full!                                                                                                                         
Queue elements after insertion: 3 4 0 1 2                                                                                                     
front:3 rear:2                                                                                                                                
Dequeued 1 element: 3                                                                                                                         
Dequeued 1 element: 4                                                                                                                         
Queue elements after dequeue: 0 1 2                                                                                                           
front:0 rear:2  
