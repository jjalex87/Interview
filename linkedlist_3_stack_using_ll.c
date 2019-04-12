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

void print_list(node_t *head)
{
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int delete_node(node_t *node)
{
    node_t *temp_node = head;
    node_t *prev_node = head;
    node_t *next_node;
    int data;
    int count = 0;

    while (temp_node != NULL) {
        if (temp_node == node) {
            next_node = node->next;
            data = node->data;
            free(node);
            break;
        } else {
            prev_node = temp_node;
            temp_node = temp_node->next;
            count++;
        }
    }
    if (count == 0) {
        head = next_node;
    } else {
        prev_node->next = next_node;
    }
}

void push(int a)
{
    insert_node(a);
}

int pop()
{
    delete_node(tail);
}

void main()
{
    node_t *node1, *node2, *node3 = NULL;

    head = insert_node(head, 3);

    node1 = insert_node(head, 4);
    node2 = insert_node(head, 5);
    node3 = insert_node(head, 6);

    print_list(head);

    delete_node(&head, head);
    //delete_node(&head, node1);
    //delete_node(&head, node2);
    delete_node(&head, node3);

    print_list(head);
}
