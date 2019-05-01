#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_NODES 100

typedef struct node_ {
    int data;
    struct node_ *left;
    struct node_ *right;
} node_t;

void insert_node(node_t **root, int data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
        
    if (*root == NULL) {
        *root = new_node;
        return;
    }

    node_t *current = *root;
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

int are_identical(node_t *node1, node_t *node2)
{
    if (node1 == NULL && node2 == NULL) {
        return (1);
    }
    
    if (node1 == NULL || node2 == NULL) {
        return (0);
    }
    
    return ((node1->data == node2->data) &&
            (are_identical(node1->left, node2->left)) &&
            (are_identical(node1->right, node2->right)));
}

/*checks if tree2 is a subtree of tree1 */
int is_subtree(node_t *tree1, node_t *tree2)
{
    int i, j;
    
    if (tree2 == NULL) {
        return (1);
    }
    
    if (tree1 == NULL) {
        return (0);
    }

    if (are_identical(tree1, tree2)) {
        return (1);
    }
    
    return(is_subtree(tree1->left, tree2) || is_subtree(tree1->right, tree2));
}

#define ARR1_SIZE 10
#define ARR2_SIZE 5

int main()
{
    int i;
    node_t *tree1 = NULL, *tree2 = NULL;
    int subtree = 0;
    int arr1[ARR1_SIZE] = {8,3,6,9,4,10,1,5,7,2};
    int arr2[ARR2_SIZE] = {6,7,4,5,8};
    
    printf("\nBoth trees are empty");
    subtree = is_subtree(tree1, tree2);
    printf("\nTree2 %s subtree of Tree1", (subtree?"is a":"is not a"));
    
    for (i = 0; i < ARR1_SIZE; i++) {
        insert_node(&tree1, arr1[i]);
    }
    
    printf("\nTree1 is not empty and Tree2 is empty");
    subtree = is_subtree(tree1, tree2);
    printf("\nTree2 %s subtree of Tree1", (subtree?"is a":"is not a"));
    
    for (i = 0; i < ARR2_SIZE; i++) {
        insert_node(&tree2, arr2[i]);
    }
    
    printf("\nBoth Tree1 and Tree2 are not empty");
    subtree = is_subtree(tree1, tree2);
    printf("\nTree2 %s subtree of Tree1", (subtree?"is a":"is not a"));
}

Output:
Both trees are empty                                                                                                                             
Tree2 is a subtree of Tree1                                                                                                                      
Tree1 is not empty and Tree2 is empty                                                                                                            
Tree2 is a subtree of Tree1                                                                                                                      
Both Tree1 and Tree2 are not empty                                                                                                               
Tree2 is not a subtree of Tree1
