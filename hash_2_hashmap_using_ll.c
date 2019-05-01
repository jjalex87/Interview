#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH_TABLE_SIZE 5

typedef struct node_t_ {
    int key;
    int data;
    struct node_t_ *next;
} node_t;

node_t **hash_table = NULL;

int get_hash_index(int key)
{
    return (key % MAX_HASH_TABLE_SIZE);
}

void insert(int key, int data)
{
    if (hash_table) {
        int index = get_hash_index(key);
        node_t *list = hash_table[index];
        node_t *temp = list;
        while (temp != NULL) {
            if (temp->key == key) {
                temp->data = data;
                return;
            }
            temp = temp->next;
        }
        
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->key = key;
        new_node->data = data;
        new_node->next = list;
        hash_table[index] = new_node;
    }
}

node_t *search_node(int key)
{
    if (hash_table) {
        int index = get_hash_index(key);
        node_t *list = hash_table[index];
        node_t *temp = list;
        
        while (temp != NULL) {
            if (temp->key == key) {
                return (temp);
            }
            temp = temp->next;
        }
        return (temp);
    }
    return (NULL);
}

void display()
{
    node_t *list;
    int i;
    
    if (hash_table != NULL) {
        for (i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
            list = hash_table[i];
            printf("\nhash_table[%d]: [ ", i);
            while (list != NULL) {
                printf("%d ", list->data);
                list = list->next;
            }
            printf("]");
        }
    } else {
        printf("\nhash_table is NULL");
    }
}

void display_node(int key, node_t *node)
{
    if (node) {
        printf("\nnode found with key:%d, data: %d", key, node->data);
    } else {
        printf("\nnode not found with key:%d!", key);
    }
}

void main()
{
    int i;
    node_t *node;
    int key;
    
    printf("\nDisplaying hash table:");
    display();

    key = 6;    
    printf("\nSearching node with key:%d", key);
    node = search_node(key);
    display_node(key, node);
    
    hash_table = (node_t **)malloc(MAX_HASH_TABLE_SIZE * sizeof(node_t *));
    for (i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    
    for (i = 0; i < 20; i++) {
        insert(i, i);
    }
    printf("\nDisplaying hash table:");
    display();
    
    key = 6;
    node = search_node(key);
    display_node(key, node);
    
    key = 23;
    node = search_node(key);
    display_node(key, node);
}

Output:                                                                                                                                    
Displaying hash table:                                                                                                                           
hash_table is NULL                                                                                                                               
Searching node with key:6                                                                                                                        
node not found with key:6!                                                                                                                       
Displaying hash table:                                                                                                                           
hash_table[0]: [ 15 10 5 0 ]                                                                                                                     
hash_table[1]: [ 16 11 6 1 ]                                                                                                                     
hash_table[2]: [ 17 12 7 2 ]                                                                                                                     
hash_table[3]: [ 18 13 8 3 ]                                                                                                                     
hash_table[4]: [ 19 14 9 4 ]                                                                                                                     
node found with key:6, data: 6                                                                                                                   
node not found with key:23!   
