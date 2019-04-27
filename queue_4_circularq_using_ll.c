/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_QUEUE_SIZE  20
#define TRUE            1
#define FALSE           0

typedef struct q_node_ {
    int data;
    struct q_node_ *next;
} q_node_t;

q_node_t *front = NULL, *rear = NULL;

int queue_len()
{
    q_node_t *curr;
    int len = 0;
    
    if (front == NULL) {
        return 0;
    }
    
    for(curr = front; curr->next != front; curr = curr->next) {
        len++;
    }
    len++;
    return (len);
}

bool is_queue_full()
{
    return (queue_len() == MAX_QUEUE_SIZE);
}

bool is_queue_empty()
{
    return (front == NULL);
}

q_node_t *create_node(int num)
{
    q_node_t *node = (q_node_t *)malloc(sizeof(q_node_t));
    if (node != NULL) {
        node->data = num;
        node->next = NULL;
    }
    return (node);
}

bool enqueue(int num)
{
    bool rc = FALSE;
    
    if (!is_queue_full()) {
        q_node_t *node = create_node(num);
        if (node != NULL) {
            if (front == NULL) {
                front = rear = node;
            } else {
                rear->next = node;
                rear = node;
            }
            node->next = front;
            rc = TRUE;
        }
    } else {
        printf("\nERROR: Queue is full!");
    }
    return (rc);
}

int dequeue()
{
    int num = -1, i;
    q_node_t *temp = front;
    
    if (!is_queue_empty()) {
        num = temp->data;
        front = front->next;
        temp->next = NULL;
        free(temp);
        
        if (front == NULL) {
            rear = NULL;
        } else {
            rear->next = front;
        }
    } else {
        printf("\nERROR: Queue is empty!");
    }
    return num;
}

void print_queue()
{
    q_node_t *curr;
    if (is_queue_empty()) {
        printf("Queue is empty!");
        return;
    }
    
    for (curr = front; curr->next != front; curr = curr->next) {
        printf("%d->", curr->data);
    }
    printf("%d->", curr->data);
    printf("[front:%d]", front->data);
}


int main()
{
    int i;
    
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
Queue elements after insertion: 0->1->2->3->4->[front:0]                                                                                      
Dequeued 1 element: 0                                                                                                                         
Dequeued 1 element: 1                                                                                                                         
Dequeued 1 element: 2                                                                                                                         
Queue elements after dequeue: 3->4->[front:3]                                                                                                 
Queue elements after insertion: 3->4->0->1->2->3->4->[front:3]                                                                                
Dequeued 1 element: 3                                                                                                                         
Dequeued 1 element: 4                                                                                                                         
Queue elements after dequeue: 0->1->2->3->4->[front:0]  
