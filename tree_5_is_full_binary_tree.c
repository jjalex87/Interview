#include <stdio.h>
#include <stdlib.h>

/*
A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes. 
*/

typedef struct node_ {
    int data;
    struct node_ *left;
    struct node_ *right;
} node_t;

node_t *create_node(int data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return(new_node);
}

int is_full_binary_tree(node_t *root)
{
    if (root == NULL) {
        return 1;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    if (root->left == NULL || root->right == NULL) {
        return 0;
    }
    
    return(is_full_binary_tree(root->left) && is_full_binary_tree(root->right));
}

void main()
{
    node_t *root = NULL; 
    root = create_node(10); 
    root->left = create_node(20); 
    root->right = create_node(30); 
  
    root->left->right = create_node(40); 
    root->left->left = create_node(50); 
    root->right->left = create_node(60); 
    root->right->right = create_node(70); 
  
    root->left->left->left = create_node(80); 
    root->left->left->right = create_node(90); 
    root->left->right->left = create_node(80); 
    root->left->right->right = create_node(90); 
    root->right->left->left = create_node(80); 
    root->right->left->right = create_node(90); 
    root->right->right->left = create_node(80); 
    root->right->right->right = create_node(90); 
  
    if (is_full_binary_tree(root)) 
        printf("The Binary Tree is full\n"); 
    else
        printf("The Binary Tree is not full\n"); 
}

Output:
The Binary Tree is full 
