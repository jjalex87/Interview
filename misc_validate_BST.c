int validate (node *testNode) {
    // Terminal case, empty sub-tree is valid.

    if (testNode == NULL)
        return 1;

    // Left node >= current means invalid

    if (testNode->lchild != NULL)
        if (testNode->lchild->data >= testNode->data)
            return 0;

    // Right node <= current means invalid

    if (testNode->rchild != NULL)
        if (testNode->rchild->data <= testNode->data)
            return 0;

    // Invalid entire left subtree means invalid.

    if (! validate (testNode->lchild))
        return 0;

    // Otherwise return state of entire right subtree.
    return validate (testNode->rchild);
}
