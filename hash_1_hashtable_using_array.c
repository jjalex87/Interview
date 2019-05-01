/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH_ARR_SIZE   20

typedef struct hash_elem_ {
    int key;
    int data;
} hash_elem_t;

hash_elem_t *hash_arr[MAX_HASH_ARR_SIZE];

int get_hash_index(int key) {
    return (key % MAX_HASH_ARR_SIZE);
}

hash_elem_t *insert(int key, int data)
{
    int index = get_hash_index(key);
    int orig_index = index;
    hash_elem_t *hash_elem = (hash_elem_t *)malloc(sizeof(hash_elem_t));
    
    if (hash_elem == NULL) {
        printf("\nERROR: Could not allocate memory!");
        return (NULL);
    }
    
    hash_elem->data = data;
    hash_elem->key = key;
    
    while(hash_arr[index] != NULL) {
        index = ((index + 1) % MAX_HASH_ARR_SIZE);
        if (index == orig_index) {
            break;
        }
    }
    
    if (hash_arr[index] == NULL) {
        hash_arr[index] = hash_elem;
        return (hash_elem);
    } else {
        printf("\nERROR: No free space in hash array!");
        free(hash_elem);
        return (NULL);
    }
}

hash_elem_t *hash_search(int key, int *hash_index)
{
    int index = get_hash_index(key);
    int orig_index = index;
    hash_elem_t *hash_elem = NULL;
    
    while(hash_arr[index] != NULL) {
        if (hash_arr[index]->key == key) {
            hash_elem = hash_arr[index];
            *hash_index = index;
            return (hash_elem);
        }
        
        index = ((index + 1) % MAX_HASH_ARR_SIZE);
        if (index == orig_index) {
            break;
        }
    }
    return (NULL);
}

void delete(hash_elem_t *hash_elem)
{
    int index = -1;
    hash_elem_t *temp_hash_elem = NULL;
    
    if (hash_elem == NULL) {
        printf("\nERROR: hash_elem is NULL!");
        return;
    }
    
    temp_hash_elem = hash_search(hash_elem->key, &index);
    
    if (temp_hash_elem != NULL && index != -1) {
        printf("\nDeleted item with given key:%d", temp_hash_elem->key);
        hash_arr[index] = NULL;
        free(temp_hash_elem);
    } else {
        printf("\nERROR: Cannot delete item with given key:%d", hash_elem->key);
    }
}

void hash_display()
{
    int index;
    
    printf("\nContents of hash array:\n");
    for (index = 0; index < MAX_HASH_ARR_SIZE; index++) {
        if (hash_arr[index] != NULL) {
            printf("(%d,%d) ", hash_arr[index]->key, hash_arr[index]->data);
        } else {
            printf("~~ ");
        }
    }
}

int main()
{
    hash_elem_t *item;
    int index;
    int i, key;
    
    for (i = 0; i < MAX_HASH_ARR_SIZE; i++) {
        hash_arr[i] = NULL;
    }
    
    for (i = 0; i < MAX_HASH_ARR_SIZE; i++) {
        insert(i, i);
    }
    
    hash_display();
    
    key = 37;
    item = hash_search(key, &index);

    if (item != NULL) {
        printf("\nElement found with given key:%d data:%d", key, item->data);
    } else {
        printf("\nERROR: Element not found with given key:%d", key);
    }
    
    key = 12;
    item = hash_search(key, &index);

    if (item != NULL) {
        printf("\nElement found with given key:%d data:%d", key, item->data);
    } else {
        printf("\nERROR: Element not found with given key:%d", key);
    }
    
    delete(item);
    item = hash_search(key, &index);
    
    if (item != NULL) {
        printf("\nElement found with given key:%d data:%d", key, item->data);
    } else {
        printf("\nERROR: Element not found with given key:%d", key);
    }
    
    hash_display();
    
    key = 14;
    item = hash_search(key, &index);

    if (item != NULL) {
        printf("\nElement found with given key:%d data:%d", key, item->data);
    } else {
        printf("\nERROR: Element not found with given key:%d", key);
    }

    return 0;
}

Output:
Contents of hash array:                                                                                                                     
(0,0) (1,1) (2,2) (3,3) (4,4) (5,5) (6,6) (7,7) (8,8) (9,9) (10,10) (11,11) (12,12) (13,13) (14,14) (15,15) (16,16) (17,17) (18,18) (19,19) 
ERROR: Element not found with given key:37                                                                                                  
Element found with given key:12 data:12                                                                                                     
Deleted item with given key:12                                                                                                              
ERROR: Element not found with given key:12                                                                                                  
Contents of hash array:                                                                                                                     
(0,0) (1,1) (2,2) (3,3) (4,4) (5,5) (6,6) (7,7) (8,8) (9,9) (10,10) (11,11) ~~ (13,13) (14,14) (15,15) (16,16) (17,17) (18,18) (19,19)      
Element found with given key:14 data:14
