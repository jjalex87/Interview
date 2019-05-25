#include <stdio.h>
#include <stdlib.h>

typedef struct node_t_ {
    int data;
    struct node_t_ *next;
} node_t;

node_t *head = NULL;

void insert_node(int data)
{
    node_t *node = NULL;

    node = (node_t *)malloc(sizeof(node_t));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    } else {
        printf("malloc failed! Cannot insert node!\n");
        return;
    }

    if (head == NULL) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }
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

int delete_node()
{
    node_t *curr = head;
    int data;
    
    if (head == NULL) {
        return (-1);
    }
    
    data = curr->data;
    head = head->next;
    curr->next = NULL;
    free(curr);
    return (data);
}

void push(int a)
{
    insert_node(a);
}

int pop()
{
    int data = delete_node();
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
1->200->NULL                                                                                                                                     
2->1->200->NULL                                                                                                                                  
3->2->1->200->NULL                                                                                                                               
4->3->2->1->200->NULL                                                                                                                            
5->4->3->2->1->200->NULL                                                                                                                         
Pop 1 Element: 5                                                                                                                                 
4->3->2->1->200->NULL                                                                                                                            
Pop 1 Element: 4                                                                                                                                 
3->2->1->200->NULL                                                                                                                               
6->3->2->1->200->NULL                                                                                                                            
7->6->3->2->1->200->NULL                                                                                                                         
8->7->6->3->2->1->200->NULL                                                                                                                      
Pop 1 Element: 8                                                                                                                                 
7->6->3->2->1->200->NULL                                                                                                                         
Pop 1 Element: 7                                                                                                                                 
6->3->2->1->200->NULL                                                                                                                            
Pop 1 Element: 6                                                                                                                                 
3->2->1->200->NULL                                                                                                                               
Pop 1 Element: 3                                                                                                                                 
2->1->200->NULL                                                                                                                                  
Pop 1 Element: 2                                                                                                                                 
1->200->NULL                                                                                                                                     
Pop 1 Element: 1                                                                                                                                 
200->NULL                                                                                                                                        
Pop 1 Element: 200                                                                                                                               
Stack is empty! Nothing to print                                                                                                                 
Stack is empty! Nothing to pop! 
