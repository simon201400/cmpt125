BTnode_t* find(BTnode_t* node, int num) {
    if(node == NULL) return NULL;
    if(node->value == num) return node;
    BTnode_t* temp = NULL:
    temp = find(node->left, num);
    if(temp != NULL) return temp;
    temp = find(node->right, num);
    if(temp != NULL) return temp;
    return  NULL;
}