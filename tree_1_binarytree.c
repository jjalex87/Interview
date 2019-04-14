#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int data;
    struct node_ *left;
    struct node_ *right;
} node_t;;

node_t *root = NULL;

void insert_node(int data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
        
    if (root == NULL) {
        root = new_node;
        return;
    }

    node_t *current = root;
    node_t *parent = NULL;
    while (1) {
        parent = current;
        if (data <= current->data) {
            current = current->left;
            if (current == NULL) {
                parent->left = new_node;
                return;
            }
        } else {
            current = current->right;
            if (current == NULL) {
                parent->right = new_node;
                return;
            }
        }
    }
}

#define ARR_SIZE 10
int arr[ARR_SIZE] = {8,3,6,9,4,10,1,5,7,2};
int main()
{
    int i;

    for (i = 0; i < ARR_SIZE; i++) {
        insert_node(arr[i]);
    }
    return 0;
}
