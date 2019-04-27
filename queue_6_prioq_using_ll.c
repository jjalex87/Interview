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
    int prio; /*lower the number, higher the priority*/
    struct q_node_ *next;
} q_node_t;

q_node_t *front = NULL;

int queue_len()
{
    q_node_t *curr;
    int len = 0;
    
    for(curr = front; curr != NULL; curr = curr->next) {
        len++;
    }
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

q_node_t *create_node(int num, int prio)
{
    q_node_t *node = (q_node_t *)malloc(sizeof(q_node_t));
    if (node != NULL) {
        node->data = num;
        node->prio = prio;
        node->next = NULL;
    }
    return (node);
}

bool enqueue(int num, int prio)
{
    bool rc = FALSE;
    q_node_t *curr = front;
    
    if (!is_queue_full()) {
        q_node_t *node = create_node(num, prio);
        if (node != NULL) {
            if (front == NULL) {
                front = node;
            } else {
                /* If priority of front is less than new node priority,
                 * new node becomes the front and its next ptr points to 
                 * old front */
                if (front->prio > prio) {
                    node->next = front;
                    front = node;
                } else {
                    while (curr->next != NULL && curr->next->prio <= prio) {
                        curr = curr->next;
                    }
                    node->next = curr->next;
                    curr->next = node;
                }
            }
            rc = TRUE;
        }
    } else {
        printf("\nERROR: Queue is full!");
    }
    return (rc);
}

int dequeue(int *num, int *prio)
{
    q_node_t *temp = front;
    *num = *prio = -1;
    
    if (!is_queue_empty()) {
        *num = temp->data;
        *prio = temp->prio;
        front = front->next;
        temp->next = NULL;
        free(temp);
    } else {
        printf("\nERROR: Queue is empty!");
    }
}

void print_queue()
{
    q_node_t *curr;
    if (is_queue_empty()) {
        printf("Queue is empty!");
        return;
    }
    
    for (curr = front; curr != NULL; curr = curr->next) {
        printf("[%d,%d]->", curr->data, curr->prio);
    }
    printf("NULL");
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
Queue elements after insertion: [0,0]->NULL                                                                                                   
Queue elements after insertion: [0,0]->[1,1]->NULL                                                                                            
Queue elements after insertion: [0,0]->[1,1]->[2,2]->NULL                                                                                     
Queue elements after insertion: [0,0]->[1,1]->[2,2]->[3,3]->NULL                                                                              
Queue elements after insertion: [0,0]->[1,1]->[2,2]->[3,3]->[4,4]->NULL                                                                       
Dequeued 1 element: [0,0]                                                                                                                     
Dequeued 1 element: [1,1]                                                                                                                     
Dequeued 1 element: [2,2]                                                                                                                     
Queue elements after dequeue: [3,3]->[4,4]->NULL                                                                                              
Queue elements after insertion: [0,0]->[3,3]->[4,4]->NULL                                                                                     
Queue elements after insertion: [0,0]->[1,1]->[3,3]->[4,4]->NULL                                                                              
Queue elements after insertion: [0,0]->[2,0]->[1,1]->[3,3]->[4,4]->NULL                                                                       
Queue elements after insertion: [0,0]->[2,0]->[1,1]->[3,1]->[3,3]->[4,4]->NULL                                                                
Queue elements after insertion: [0,0]->[2,0]->[4,0]->[1,1]->[3,1]->[3,3]->[4,4]->NULL                                                         
Dequeued 1 element: [0,0]                                                                                                                     
Dequeued 1 element: [2,0]                                                                                                                     
Queue elements after dequeue: [4,0]->[1,1]->[3,1]->[3,3]->[4,4]->NULL 
