//Write a function that gets a binary tree and computes its depth.

//recursion
int depth(BT_t* tree)
{
    int depth = 0;
    BTnode_t* current = tree->root;
    if(current == NULL || (current->left == NULL && current->right == NULL)) return 0;
    BT_t* left = (BT_t*)malloc(sizeof(BT_t*));
    BT_t* right = (BT_t*)malloc(sizeof(BT_t*));
    left->root = current->left;
    right->root = current->right;
    left_value = depth(left);
    right_value = depth(right);
    free(left));
    free(right));
    if(left_value > right_value) return (left_value+1); else return return (right_value+1);
}

//iteration 用queue做level order traversal
int depth(BT_t* tree)
{
    int depth = 0;
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    BTnode_t* current = tree->root;
    enqueue(queue, current);
    while(!isEmpty(queue))
    {
        current = pop(queue);
        if(current->left != NULL)
        {
            enqueue(queue, current->left);
        }
        if(current->right != NULL)
        {
            enqueue(queue, current->right);
        }
        
    }
    free(queue)
    return depth;
}


