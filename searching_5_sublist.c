#include <stdio.h>
#include <stdlib.h>

typedef struct node_t_ {
    int data;
    struct node_t_ *next;
} node_t;

node_t *create_node(int data)
{
    node_t *node;

    node = malloc(sizeof(node_t));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    } else {
        printf("malloc failed! Cannot insert node!\n");
        return (NULL);
    }
    return (node);
}

void print_list(node_t *head)
{
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int is_sublist(node_t *list1, node_t *list2)
{
    node_t *ptr1 = list1;
    node_t *ptr2 = list2;
    int match_start = 0;
    
    while (ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            match_start = 1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr1 == NULL) {
                return (1);
            }
            continue;
        }
        if (match_start == 1) {
            ptr1 = list1;
            match_start = 0;
        } else {
            ptr2 = ptr2->next;
        }
    }
    return 0;
}

int main()
{
    node_t *list1;
    node_t *list2;
    int result = 0;
    
    list1 = create_node(1);
    list1->next = create_node(2);
    list1->next->next = create_node(3);
    list1->next->next->next = create_node(4);
    
    printf("List1: ");
    print_list(list1);

    list2 = create_node(1);
    list2->next = create_node(2);
    list2->next->next = create_node(1);
    list2->next->next->next = create_node(2);
    list2->next->next->next->next = create_node(3);
    list2->next->next->next->next->next = create_node(4);
    
    printf("List2: ");
    print_list(list2);
    
    result = is_sublist(list1, list2);
    printf("list1 %s sublist of list2", (result?"is":"is not"));
    
    return 0;
}

Output:
List1: 1->2->3->4->NULL                                                                                                                        
List2: 1->2->1->2->3->4->NULL                                                                                                                  
list1 is sublist of list2 
