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
#define N 20
node_t *queue[N];
int front = -1;
int rear = 0;

int is_queue_full()
{
    return (rear == N);
}

int is_queue_empty()
{
    return (front == -1);
}

void enqueue(node_t *item)
{
    if (!is_queue_full()) {
        queue[rear++] = item;
        if (front == -1) {
            front = 0;
        }
    }
}

node_t *dequeue()
{
    node_t *item = NULL;
    
    if (!is_queue_empty()) {
        item = queue[front++];
        if (front == rear) {
            front = -1;
            rear = 0;
        }
    }
    return (item);
}

node_t *peek()
{
    if (!is_queue_empty()) {
        return(queue[front]);
    }
}

int size_of_queue() {
    if (is_queue_empty()) {
        return 0;
    } else {
        return(rear - front);
    }
}

int get_max_node_level(node_t *root) {
    int level = 0;
    int max_level_num = -1;
    int node_count = 0;
    int max_node_count = 0;
    node_t *temp_node;
    
    if (root == NULL) {
        return (max_level_num);
    }
    
    enqueue(root);
    
    while (1) {
        node_count = size_of_queue();
        
        if (node_count == 0) {
            break;
        }
        
        if (node_count > max_node_count) {
            max_node_count = node_count;
            max_level_num = level;
        }
        
        while (node_count > 0) {
            temp_node = dequeue();
            if (temp_node->left != NULL) {
                enqueue(temp_node->left);
            }
            if (temp_node->right != NULL) {
                enqueue(temp_node->right);
            }
            node_count--;
        }
        level++;
    }
    return (max_level_num);
}

void main()
{
    node_t *root = NULL;
    
    root              = create_node(2);      /*        2      */
    root->left        = create_node(1);      /*      /   \    */
    root->right       = create_node(3);      /*     1     3      */
    root->left->left  = create_node(4);      /*   /   \    \  */
    root->left->right = create_node(6);      /*  4     6    8 */
    root->right->right  = create_node(8);    /*       /       */
    root->left->right->left = create_node(5);/*      5        */
  
    printf("Level having maximum number of Nodes : %d", 
            get_max_node_level(root)); 
}

Output:
Level having maximum number of Nodes : 2 
