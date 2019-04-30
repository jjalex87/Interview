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

void inorder_traversal(node_t *root)
{
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}


void preorder_traversal(node_t *root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}


void postorder_traversal(node_t *root)
{
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

node_t *search(int data)
{
    node_t *curr = root;
    
    if (root == NULL) {
        return (root);
    }
    
    while (curr != NULL) {
        if (data == curr->data) {
            break;
        } else if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    
    return (curr);
}

#define ARR_SIZE 10
int arr[ARR_SIZE] = {8,3,6,9,4,10,1,5,7,2};
int main()
{
    int i;
    node_t *temp;
    
    printf("Searching for node with value 9:\n");
    temp = search(9);
    if (temp == NULL) {
        printf("Node not found!\n");
    } else {
        printf("Node found: %d\n", temp->data);
    }

    printf("Creating binary search tree from given array:\n");
    for (i = 0; i < ARR_SIZE; i++) {
        printf("Inserting node with value:%d\n", arr[i]);
        insert_node(arr[i]);
    }
    
    printf("In-order traversal: [");
    inorder_traversal(root);
    printf("]\n");
    
    printf("Pre-order traversal: [");
    preorder_traversal(root);
    printf("]\n");
    
    printf("Post-order traversal: [");
    postorder_traversal(root);
    printf("]\n");
    
    printf("Searching for node with value 9:\n");
    temp = search(9);
    if (temp == NULL) {
        printf("Node not found!\n");
    } else {
        printf("Node found: %d\n", temp->data);
    }
    
    printf("Searching for node with value 12:\n");
    temp = search(12);
    if (temp == NULL) {
        printf("Node not found!\n");
    } else {
        printf("Node found: %d\n", temp->data);
    }
    
    return 0;
}

Output:
Searching for node with value 9:                                                                                                                 
Node not found!                                                                                                                                  
Creating binary search tree from given array:                                                                                                    
Inserting node with value:8                                                                                                                      
Inserting node with value:3                                                                                                                      
Inserting node with value:6                                                                                                                      
Inserting node with value:9                                                                                                                      
Inserting node with value:4                                                                                                                      
Inserting node with value:10                                                                                                                     
Inserting node with value:1                                                                                                                      
Inserting node with value:5                                                                                                                      
Inserting node with value:7                                                                                                                      
Inserting node with value:2                                                                                                                      
In-order traversal: [1 2 3 4 5 6 7 8 9 10 ]                                                                                                      
Pre-order traversal: [8 3 1 2 6 4 5 7 9 10 ]                                                                                                     
Post-order traversal: [2 1 5 4 7 6 3 10 9 8 ]                                                                                                    
Searching for node with value 9:                                                                                                                 
Node found: 9                                                                                                                                    
Searching for node with value 12:                                                                                                                
Node not found!
