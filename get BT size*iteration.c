//Write a function that gets a binary tree and computes its size.

//recursion
 int size(BT_t* tree)
{
int size = 0;
if(tree == NULL) return 0;
BTnode_t* current = tree->root;
BT_t* left = (BT_t*)malloc(sizeof(BT_t*));
BT_t* right = (BT_t*)malloc(sizeof(BT_t*));
left->root = current->left;
right->root = current->right;
size = 1 + size(left) + size(right);
free(left);
free(right);
return size;
}

//iteration❗️❗️❗️❗️❗️❗️❗️❗️❗️level traversal
int size(BT_t* tree)
{
    BTnode_t* array[10000];
    int head = 0, tail = 0;//head, tail是array的index
    array[0] = tree->root;
    BTnode_t* current;
    int tsize = 1;
    while(head <= tail)//❗️❗️❗️❗️❗️
    {
        current = array[head];
        if(current->left != NULL)
        {
            tsize++;
            tail ++;
            array[tail] = current->left;
        }
        if(current->right != NULL)
        {
            tsize++;
            tail ++;
            array[tail] = current->right;
        }
        head ++;
    }
    return tsize;
}

//用stack做inorder
int size(BT_t* tree)
{
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    int size = 0;
    BTnode_t* current = tree->root;
    while(1)
    {
        while(current != NULL)
        {
            push(stack, current);
            size++;
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
    return size;
}

//用stack做preorder
int size(BT_t* tree)
{
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    int size = 0;
    BTnode_t* current = tree->root;
    push(stack, current);
    while(!isEmpty(stack))
    {
        current = pop(stack);
        //printf("%d", current->data);
        size++;
        if(current->right != NULL)
        {
            push(stack, current->right);
        }
        if(current->left != NULL)
        {
            push(stack, current->left);
        }        
    }
    return size;
}

//用queue做BFS(把preorder换成queue，左右调换就好了)
int size(BT_t* tree)
{
    int size = 0;
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    BTnode_t* current = tree->root;
    enqueue(queue, current)
    while(!isEmpty(queue))
    {
        // int item = dequeue(queue);
        // printf("%d", item);
        current = dequeue(queue);
        size++;
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
    return size;
}

//用两个stack做postorder❗️❗️❗️❗️❗️❗️❗️
int size(BT_t* tree)
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
    // while(!isEmpty(s2))
    // {
    //     int item = pop(s2);
    //     printf("%d", item);
    // }
    return size;
}