#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE  20
#define TRUE            1
#define FALSE           0

int queue[MAX_QUEUE_SIZE];
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

bool enqueue(int num)
{
    if (!is_queue_full()) {
        queue[rear++] = num;
        return (TRUE);
    } else {
        printf("\nERROR: Queue is full!");
        return (FALSE);
    }
}

int dequeue()
{
    int num = -1, i;
    if (!is_queue_empty()) {
        num = queue[front];
        for (i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
    } else {
        printf("\nERROR: Queue is empty!");
    }
    return num;
}

void print_queue()
{
    int i;
    if (is_queue_empty()) {
        printf("Queue is empty!");
        return;
    }
    
    for (i = 0; i < rear; i++) {
        printf("%d ", queue[i]);
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
