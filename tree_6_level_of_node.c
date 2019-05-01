#include <stdio.h>
#include <stdlib.h>

/*
Given a binary tree and a key, write a function that returns level of the key.
Root is at level 1, its children at level 2 and so on.
For a key which is not present in tree, then the function should return 0.
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

int get_level(node_t *root, int data, int level)
{
    if (root == NULL) {
        return 0;
    }
    
    if (root->data == data) {
        return (level);
    }
    
    int temp_level = get_level(root->left, data, level+1);
    if (temp_level == 0) {
        temp_level = get_level(root->right, data, level+1);
    }
    return (temp_level);
}

int get_node_level(node_t *root, int data) {
    return(get_level(root, data, 1));
}

void main()
{
    node_t *root = NULL; 
    int x;
    
    root = create_node(3); 
    root->left = create_node(2); 
    root->right = create_node(5); 
    root->left->left = create_node(1); 
    root->left->right = create_node(4); 
  
    for (x = 1; x <= 5; x++) { 
        int level = get_node_level(root, x); 
        if (level) {
            printf("\nLevel of %d is %d", x, level); 
        } else {
            printf("\n%d is not present in tree", x);
        }
    } 
}

Output:
Level of 1 is 3                                                                                                                               
Level of 2 is 2                                                                                                                               
Level of 3 is 1                                                                                                                               
Level of 4 is 3                                                                                                                               
Level of 5 is 2    
