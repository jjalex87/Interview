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

void store_inorder(node_t *root, int *in_arr, int *num_nodes)
{
    if (root == NULL) {
        return;
    }
    store_inorder(root->left, in_arr, num_nodes);
    in_arr[(*num_nodes)++] = root->data;
    store_inorder(root->right, in_arr, num_nodes);
}


void store_preorder(node_t *root, int *pre_arr, int *num_nodes)
{
    if (root == NULL) {
        return;
    }
    pre_arr[(*num_nodes)++] = root->data;
    store_preorder(root->left, pre_arr, num_nodes);
    store_preorder(root->right, pre_arr, num_nodes);
}

int is_subarray(int *arr1, int size_arr1, int *arr2, int size_arr2)
{
    int i, j;
    
    for (i = 0; i < size_arr1; i++) {
        if (arr1[i] == arr2[0]) {
            break;
        }
    }
    
    if (i == size_arr1) {
        return 0;
    } else {
        for (j = 0; i < size_arr1 && j < size_arr2; i++, j++) {
            if (arr1[i] != arr2[j]) {
                return 0;
            }
        }
        if (j != size_arr2) {
            return 0;
        }
    }
}

/*checks if tree2 is a subtree of tree1 */
int is_subtree(node_t *tree1, node_t *tree2)
{
    int num_nodes_tree1 = 0, num_nodes_tree2 = 0;
        
    int inorder_tree1[MAX_NUM_NODES];
    int preorder_tree1[MAX_NUM_NODES];
    int inorder_tree2[MAX_NUM_NODES];
    int preorder_tree2[MAX_NUM_NODES];
    
    int i, j;
    
    if (tree2 == NULL) {
        return (1);
    }
    
    if (tree1 == NULL) {
        return 0;
    }
    
    store_inorder(tree1, inorder_tree1, &num_nodes_tree1);
    store_inorder(tree2, inorder_tree2, &num_nodes_tree2);
    
    printf("\ninorder of tree1: [ ");
    for (i = 0; i < num_nodes_tree1; i++) {
        printf("%d ", inorder_tree1[i]);
    }
    printf("]");
    
    printf("\ninorder of tree2: [ ");
    for (i = 0; i < num_nodes_tree2; i++) {
        printf("%d ", inorder_tree2[i]);
    }
    printf("]");
    
    if (!is_subarray(inorder_tree1, num_nodes_tree1, inorder_tree2, num_nodes_tree2)) {
        return 0;
    }
    
    num_nodes_tree1 = num_nodes_tree2 = 0;
    store_preorder(tree1, preorder_tree1, &num_nodes_tree1);
    store_preorder(tree2, preorder_tree2, &num_nodes_tree2);
    
        
    printf("\npreorder of tree1: [ ");
    for (i = 0; i < num_nodes_tree1; i++) {
        printf("%d ", preorder_tree1[i]);
    }
    printf("]");
    
    printf("\npreorder of tree2: [ ");
    for (i = 0; i < num_nodes_tree2; i++) {
        printf("%d ", preorder_tree2[i]);
    }
    printf("]");
    
    return (is_subarray(preorder_tree1, num_nodes_tree1, preorder_tree2, num_nodes_tree2));
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
    
    subtree = is_subtree(tree1, tree2);
    printf("\nTree2 %s subtree of Tree1", (subtree?"is a":"is not a"));
}

Output:
Both trees are empty                                                                                                                             
Tree2 is a subtree of Tree1                                                                                                                      
Tree1 is not empty and Tree2 is empty                                                                                                            
Tree2 is a subtree of Tree1                                                                                                                      
inorder of tree1: [ 1 2 3 4 5 6 7 8 9 10 ]                                                                                                       
inorder of tree2: [ 4 5 6 7 8 ]                                                                                                                  
preorder of tree1: [ 8 3 1 2 6 4 5 7 9 10 ]                                                                                                      
preorder of tree2: [ 6 4 5 7 8 ]                                                                                                                 
Tree2 is not a subtree of Tree1       
