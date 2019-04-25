#include <stdio.h>
#include <stdlib.h>

typedef struct node_t_ {
    int data;
    struct node_t_ *next;
} node_t;

/* Insert new node at the end of the list */
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

/* Insert new node at the beginning of the list */
node_t* insert_first(node_t *head, int data) {
   node_t *node;
	
   node = malloc(sizeof(node_t));
   if (node != NULL) {
       node->data = data;
       node->next = head;
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
    node_t *curr_node = *head;
    node_t *prev_node = *head;
    int data;
	
	if (head == NULL || *head == NULL) {
		printf("Invalid arg or list is empty!");
		return -1;
	}

	while (curr_node != node) {
		prev_node = curr_node;
		curr_node = curr_node->next
		if (curr_node == NULL) {
			printf("Node to be deleted not found, exiting!");
			return -1;
		}
	}
	
	if (curr_node == *head) {
		*head = curr_node->next;
	} else {
		prev_node->next = curr_node->next;
	}
	data = curr_node->data;
	curr_node->next = NULL;
	free(curr_node);
	return (data);
}

void reverse(node_t** head) {
   node_t* prev   = NULL;
   node_t* current = *head;
   node_t* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head = prev;
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
    
    reverse(&head);
    printf("Reversed List:\n");
    print_list(head);

}
