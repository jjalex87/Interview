#include <stdio.h>
#include <stdlib.h>

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

void preorder_traversal(node_t *root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void mirror(node_t *root)
{
    node_t *temp;
    
    /* Base condition: if leaf node, no more mirror required */
    if (root->left == NULL && root->right == NULL) {
        return;
    }
    
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    if (root->left) {
        mirror(root->left);
    }
    if (root->right) {
        mirror(root->right);
    }
}

int main()
{
    int i;
    node_t *tree1 = NULL;
    
    tree1 = create_node(1);
    tree1->left = create_node(2);
    tree1->right = create_node(3);
    tree1->left->left = create_node(4);
    tree1->left->right = create_node(5);
    tree1->right->right = create_node(6);
    
    printf("\nPreorder traversal of tree1: [ ");
    preorder_traversal(tree1);
    printf("]");
    
    mirror(tree1);
    printf("\nPreorder traversal of tree1 after mirroring: [ ");
    preorder_traversal(tree1);
    printf("]");
    
    return 0;
}

Output:
Preorder traversal of tree1: [ 1 2 4 5 3 6 ]                                                                                                   
Preorder traversal of tree1 after mirroring: [ 1 3 6 2 5 4 ]  
