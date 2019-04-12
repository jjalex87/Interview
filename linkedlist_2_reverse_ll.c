#include <stdio.h>
#include <stdlib.h>

typedef struct node_t_ {
    int data;
    struct node_t_ *next;
} node_t;

node_t* insert_node(node_t *head, int data)
{
    node_t *node = head;
    node_t *last_node = head;

    while (node != NULL) {
        last_node = node;
        node = node->next;
    }

    node = malloc(sizeof(node_t));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    } else {
        printf("malloc failed! Cannot insert node!\n");
    }

    if (last_node != NULL) {
        last_node->next = node;
    }

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

int delete_node(node_t **head, node_t *node)
{
    node_t *temp_node = *head;
    node_t *prev_node = *head;
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
        *head = next_node;
    } else {
        prev_node->next = next_node;
    }
}

void main()
{
    node_t *head = NULL;
    node_t *node1, *node2, *node3 = NULL;
    node_t *curr_node;
    node_t *next_node;
    node_t *prev_node = NULL;

    head = insert_node(head, 3);

//    node1 = insert_node(head, 4);
    node2 = insert_node(head, 5);
//    node3 = insert_node(head, 6);

    print_list(head);

    //delete_node(&head, head);
    //delete_node(&head, node1);
    //delete_node(&head, node2);
    //delete_node(&head, node3);

    //print_list(head);

    curr_node = head;
    while (curr_node != NULL) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    head = prev_node;
    printf("Reversed List:\n");
    print_list(head);

}
