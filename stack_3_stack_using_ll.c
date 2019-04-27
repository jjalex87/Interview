#include <stdio.h>
#include <stdlib.h>

typedef struct node_t_ {
    int data;
    struct node_t_ *next;
} node_t;
    

node_t *head = NULL;
node_t *tail = NULL;

node_t* insert_node(int data)
{
    node_t *node = NULL;

    node = (node_t *)malloc(sizeof(node_t));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    } else {
        printf("malloc failed! Cannot insert node!\n");
        return (NULL);
    }

    if (head == NULL) {
        head = node;
    }

    if (tail != NULL) {
        tail->next = node;
    }
    tail = node;
    return (node);
}

void print_list()
{
    node_t *curr = head;
    
    if (curr == NULL) {
        printf("Stack is empty! Nothing to print\n");
        return;
    }
    
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int delete_node(node_t *node)
{
    node_t *curr = head;
    node_t *prev = head;
    int data;
    
    if (node == NULL) {
        return (-1);
    }
    
    if (node == head) {
        data = node->data;
        head = head->next;
        free(node);
        if (head == NULL) {
            tail = NULL;
        }
        return data;
    }

    while (curr != NULL && curr != node) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        printf("ERROR: node not found!\n");
        return (-1);
    } else {
        data = curr->data;
        prev->next = curr->next;
        free(curr);
        if (prev->next == NULL) {
            tail = prev;
        }
        return data;
    }
}

void push(int a)
{
    insert_node(a);
}

int pop()
{
    int data = delete_node(tail);
    if (data == -1) {
        printf("Stack is empty! Nothing to pop!\n");
    }
    return (data);
}

void main()
{
    int i, data;
    
    print_list();
    pop();
    
    push(100);
    pop();
    push(200);
    print_list();
    
    for (i = 1; i <= 5; i++) {
        push(i);
        print_list();
    }
    
    for (i = 0; i < 2; i++) {
        printf("Pop 1 Element: %d\n", pop());
        print_list();
    }
    
    for (i = 6; i < 9; i++) {
        push(i);
        print_list();
    }
    
    for (i = 0; i < 10; i++) {
        data = pop();
        if (data == -1) {
            break;
        }
        printf("Pop 1 Element: %d\n", data);
        print_list();
    }
}

Output:
Stack is empty! Nothing to print                                                                                                               
Stack is empty! Nothing to pop!                                                                                                                
200->NULL                                                                                                                                      
200->1->NULL                                                                                                                                   
200->1->2->NULL                                                                                                                                
200->1->2->3->NULL                                                                                                                             
200->1->2->3->4->NULL                                                                                                                          
200->1->2->3->4->5->NULL                                                                                                                       
Pop 1 Element: 5                                                                                                                               
200->1->2->3->4->NULL                                                                                                                          
Pop 1 Element: 4                                                                                                                               
200->1->2->3->NULL                                                                                                                             
200->1->2->3->6->NULL                                                                                                                          
200->1->2->3->6->7->NULL                                                                                                                       
200->1->2->3->6->7->8->NULL                                                                                                                    
Pop 1 Element: 8                                                                                                                               
200->1->2->3->6->7->NULL                                                                                                                       
Pop 1 Element: 7                                                                                                                               
200->1->2->3->6->NULL                                                                                                                          
Pop 1 Element: 6                                                                                                                               
200->1->2->3->NULL                                                                                                                             
Pop 1 Element: 3                                                                                                                               
200->1->2->NULL                                                                                                                                
Pop 1 Element: 2                                                                                                                               
200->1->NULL                                                                                                                                   
Pop 1 Element: 1                                                                                                                               
200->NULL                                                                                                                                      
Pop 1 Element: 200                                                                                                                             
Stack is empty! Nothing to print                                                                                                               
Stack is empty! Nothing to pop! 
