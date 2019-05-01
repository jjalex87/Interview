#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a)>(b)?(a):(b))

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

int max_node_at_level(node_t *root, int level)
{
    int max_left = -1, max_right = -1;
    
    if (root == NULL) {
        return 0;
    }
    
    if (level == 0) {
        return (root->data);
    }
    
    max_left = max_node_at_level(root->left, level - 1);
    max_right = max_node_at_level(root->right, level - 1);
    return(max(max_left, max_right));
}

int main()
{
    node_t *root = NULL; 
    root = create_node(45); 
    root->left = create_node(46); 
    root->left->left = create_node(18); 
    root->left->left->left = create_node(16); 
    root->left->left->right = create_node(23); 
    root->left->right = create_node(17); 
    root->left->right->left = create_node(24); 
    root->left->right->right = create_node(21); 
    root->right = create_node(15); 
    root->right->left = create_node(22); 
    root->right->left->left = create_node(37); 
    root->right->left->right = create_node(41); 
    root->right->right = create_node(19); 
    root->right->right->left = create_node(49); 
    root->right->right->right = create_node(29); 
  
    int level = 3; 
    
    printf("\nMax node at level %d: %d", level, max_node_at_level(root, level));
    
    return 0;
}

Output:
Max node at level 3: 49   
