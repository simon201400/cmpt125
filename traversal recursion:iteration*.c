//inorder iteration
//用stack做inorder
void inorder(BT_t* tree)
{
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    BTnode_t* current = tree->root;
    while(1)
    {
        while(current != NULL)
        {
            push(stack, current);//在这输出就是preorder? 不对吧这样不是右左中吗
            current = current->left;
        }
        if(current == NULL && !isEmpty(stack))
        {
            current = pop(stack);
            printf("%d", current->data);
            current = current->right;
        }
        if(current == NULL && isEmpty(stack))
        {
            break;
        }
    }
    free(stack);
}

//preorder iteration
//https://www.geeksforgeeks.org/iterative-preorder-traversal/
//用stack做preorder
void preorder(BT_t* tree)
{
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    BTnode_t* current = tree->root;
    push(stack, current);
    while(!isEmpty(stack))
    {
        current = pop(stack);
        printf("%d", current->data);
        if(current->right != NULL)
        {
            push(stack, current->right);
        }
        if(current->left != NULL)
        {
            push(stack, current->left);
        }        
    }
}

//level traversal   recursion
//https://www.geeksforgeeks.org/level-order-tree-traversal/
void print_specific_level(BT_t* tree, int level)
{
    BTnode_t* current = tree->root;
    if(current == NULL) return NULL;
    if(level == 1) printf("%d", root->data);
    BT_t* left =(BT_t*)malloc(sizeof(BT_t));
    BT_t* right =(BT_t*)malloc(sizeof(BT_t));
    left->root = current->left;
    right->root = current->right;
    print_specific_level(left, level-1);
    print_specific_level(right, level-1);
}

//level traversal   iteration
//用queue做BFS(把preorder换成queue，左右调换就好了)
void BFS(BT_t* tree)
{
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    BTnode_t* current = tree->root;
    enqueue(queue, current)
    while(!isEmpty(queue))
    {
        current = dequeue(queue);
        printf("%d", current->data);
        if(current->left != NULL)
        {
            enqueue(queue, current->left);
        }
        if(current->right != NULL)
        {
            enqueue(queue, current->right);
        }
    }
    free(queue);
}

//用两个stack做postorder
void postorder(BT_t* tree)
{
    int size = 0;
    BTnode_t* current = tree->root;
    stack_t* s1 = (stack_t*)malloc(sizeof(stack_t));
    stack_t* s2 = (stack_t*)malloc(sizeof(stack_t));
    push(s1, current);
    while(!isEmpty(s1))
    {
        current = pop(s1);
        push(s2, current->data);
        size++;
        if(current->left != NULL)
        {
            push(s1, current->left);
        }
        if(current->right != NULL)
        {
            push(s1, current->right);
        }
    }
    while(!isEmpty(s2))
    {
        int item = pop(s2);
        printf("%d", item);
    }
}