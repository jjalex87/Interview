/* Given the address of the node to be deleted, delete it from the linked list. 
 * Head pointer is not given. Assume that the node to be deleted is not the last node.
 */
 
int delete_node (node_t *node)
{
    node_t *next_node;
    int data = 0;
    if (!node) {
        return -1;
    }
    
    next_node = node->next;
    if (next_node) {
        data = node->data;
        node->data = next_node->data;
        node->next = next_node->next;
        next_node->next = NULL;
        free(next_node);
        return(data);
    } else {
        return -1;
    }
}
