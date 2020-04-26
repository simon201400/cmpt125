// Questions on Binary Trees:
struct BTnode{
    BTnode* parent;
    int data;
    BTnode* left;
    BTnode* right;
}
typedef struct BTnode BTnode_t;

struct BT{
    BT* root;
}
typedef struct BT BT_t;
// Implement the following functions in C:

//Q1
// Write an algorithm that given two Binary Trees checks if they are equal.
//recursion
bool BT_equal(BT_t* tree1, BT_t* tree2)
{
    BTnode_t* current1 = tree1->root;
    BTnode_t* current2 = tree2->root;
    BT_t* left1 = (BT_t*)malloc(sizeof(BT_t));
    BT_t* right1 = (BT_t*)malloc(sizeof(BT_t));
    BT_t* left2 = (BT_t*)malloc(sizeof(BT_t));
    BT_t* right2 = (BT_t*)malloc(sizeof(BT_t));
    if(tree1 == NULL && tree2 == NULL)
    {
        free(left1);
        free(left2);
        free(right1);
        free(right2);
        return 1;
    }
    left1->root = current1->left;
    right1->root = current1->right;
    left2->root = current2->left;
    right2->root = current2->right;
    if(current1->data == current2->data && BT_equal(BT_t* left1, BT_t* left2) && BT_equal(BT_t* right1, BT_t* right2))
    {
        free(left1);
        free(left2);
        free(right1);
        free(right2);
        return 1;
    }
    free(left1);
    free(left2);
    free(right1);
    free(right2);
    return 0;
}

//Q2
// Write an algorithm that gets two Binary Trees and checks if they have the same InOrder traversal. Write it as efficient as possible. (For example, if the inorders differ in the second position, then the algorithm will stop after exploring O(1) nodes.

//O(n)time
queue_t* inorder(BT_t* tree)
{
    queue_t* inorder = (queue_t*)malloc(sizeof(queue_t));
    BTnode_t* current = tree->root;
    BT_t* left = (BT_t*)malloc(sizeof(BT_t));
    BT_t* right = (BT_t*)malloc(sizeof(BT_t));
    left->root = current->left;
    right->root = current->right;
    if(current != NULL)
    {
        inorder(BT_t* left);
        enqueue(inorder);   
        inorder(BT_t* right);
        return inorder；
    }
    inorder = NULL;
    free(left);
    free(right);
    return inorder;
}

bool same_inorder(BT_t* tree1, BT_t* tree2)
{
    queue_t* queue1 =  inorder(BT_t* tree1);
    queue_t* queue2 =  inorder(BT_t* tree2);
    //then check if queue1, queue2 are equal;
    while(queue1 != NULL && queue2 != NULL)
    {
        int item1 = dequeue(queue1);
        int item2 = dequeue(queue2);   
        if(item1 != item2)
        {
            return 0;
        }    
    }
    if(queue1 == NULL && queue2 == NULL) return 1;
    return 0;

}

//O(1)time//新写的❗️❗️❗️❗️❗️
bool same_inorder(BT_t* tree1, BT_t* tree2)
{
    BTnode_t* current1 = tree1->root;
    BTnode_t* current2 = tree2->root;
    BT_t* left1 = (BT_t*)malloc(sizeof(BT_t));
    BT_t* right1 = (BT_t*)malloc(sizeof(BT_t));
    left1->root = tree1->root;
    right1->root = tree1->root;
    BT_t* left2 = (BT_t*)malloc(sizeof(BT_t));
    BT_t* right2 = (BT_t*)malloc(sizeof(BT_t));
    left2->root = tree2->root;
    right2->root = tree2->root;
    if(current1->value != current2->value) return 0;
    return same_inorder(left1, left2) and same_inorder(right1, right2);
}

//Q3
// Write an algorithm that gets a Binary Tree a number k and returns all values in level k. 
// What is the running time of your algorithm?
//recursion

//recursion新写的❗️❗️❗️❗️❗️
void values_in_level_k(BT_t* tree, int k)
{
    int arr[10000];
    int index = 0;
    // BT_t* left = (stack_t*)malloc(sizeof(stack_t));
    // BT_t* right = (stack_t*)malloc(sizeof(stack_t));
    left->root = tree->root->left;
    right->root = tree->root->right;
    BTnode_t* current = tree->root;
    if(current == NULL) return NULL;
    if(k == 1)
    {
        printf("%d", current->data);
    }
    values_in_level_k(left, k-1);
    values_in_level_k(right, k-1);
    free(left);
    free(right);
}


//iteration新写的❗️❗️❗️❗️❗️
void values_in_level_k(BT_t* tree, int k)
{
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    queue_t* queue1 = (queue_t*)malloc(sizeof(queue_t));
    BTnode_t* current = tree->root;
    enqueue(queue, current);
    enqueue(queue1, 1)

    while(!isEmpty(queue))
    {
        current = dequeue(queue);
        int level = dequeue(queue1);//好像不对啊❓❓❓❓❓❓❓
        if(level == k)
        {
            printf("%d", current->data);
        }
        if(level !=k || current->left != NULL || current->right != NULL)
        {
            if(current->left != NULL)
            {
                enqueue(queue, current->left);
                enqueue(queue1, level + 1);
            }
            if(current->right != NULL)
            {
                enqueue(queue, current->right);
                enqueue(queue1, level + 1);
            }
        }
    }
    free(queue);
}

//Q4
// Write an algorithm that gets an array of numbers and returns a Binary Tree whose InOrder traversal is this sequence.
BT_t* Q4(int* arr, int n)
{
    int index = 0;
    BT_t* tree = (BT_t*)malloc(sizeof(BT_t));
    int length = n;
    BTnode_t* left_most = (BTnode_t*)malloc(sizeof(BTnode_t));
    left_most->data = arr[index];
    BTnode_t* previous = left_most;
    index++;
    while(index < length)//构建了一个直线形的tree
    {
        BTnode_t* pmove = (BTnode_t*)malloc(sizeof(BTnode_t));
        pmove = previous->parent;
        previous = pmove;
        pmove->data = arr[index];
        index++;
    }
    tree->root = previous;
    return tree;
}

//Q5
// Write an algorithm that gets a tree and computes its size using iterative implementation.
int size (BT_t* tree)//inorder traversal
{
    int size = 0;
    BTnode_t* current = tree->root;
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    while(1)
    {
        while(current != NULL)
        {
            push(stack, current);
            current = current->left;
        }
        if(current == NULL && !isEmpty(stack))
        {
            current = pop(stack);
            size++;
            current = current->right;
        }
        if(current == NULL && isEmpty(stack))
        {
            free(stack);
            return size;
        }
    }
}

//Q6
// Write an algorithm that prints PreOrder using iterative implementation
void Q6(BT_t* tree)
{
    BTnode_t* current = tree->root;
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    push(stack, current);
    while(!isEmpty(stack))
    {
        current = pop(stack);
        printf("%d", current->data);
        if(current->left != NULL)
        {
            push(stack, current->left);
        }
        if(current->right != NULL)
        {
            push(stack, current->right);
        }
    }
    free(stack);
}

//Q7
// **Write an algorithm that prints InOrder using iterative implementation
void Q7(BT_t* tree)
{
    BTnode_t* current = tree->root;
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    while(1)
    {
        while(current != NULL)
        {
            push(stack, current);
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
            free(stack);
            return;
        }
    }
}

//Q8
// **Write an algorithm that prints PostOrder iterative implementation
void Q8(BT_t* tree)
{
    BTnode_t* current = tree->root;
    stack_t* s1 = (stack_t)malloc(sizeof(stack_t));
    stack_t* s2 = (stack_t)malloc(sizeof(stack_t));
    push(s1, current);
    while(isEmpty(s1))
    {
        current = pop(s1);
        push(s2, current->data);
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

//Q9
// **Write an algorithm that gets a tree and computes its depth using iterative implementation.
int depth(BT_t* tree)//新写的❗️❗️❗️❗️❗️有什么问题啊我忘了?????????????????
{
    int depth = 0;
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t))；
    BTnode_t* current = tree->root;
    enqueue(queue, current);
    while(!isEmpty(queue))
    {
        current = dequeue(queue);
        if(current->left != NULL || current->right != NULL)
        {
            depth++;
            if(current->left != NULL)
            {
                enqueue(queue, current->left);
            }
            if(current->right != NULL)
            {
                enqueue(queue, current->right);
            }
        }
    }
    return depth;
}

//Q10
// ** Write an algorithm that gets an array of numbers and returns all Binary Trees whose InOrder traversals are this sequence.
BT_t* Q10(int arr[0, length-1])
{
    // queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    for(int i = 0; i < length; i++)
    {
        BT_t* tree = (BT_t*)malloc(sizeof(BT_t));
        BTnode* root = malloc;
        root->data = arr[i];
        if(i == 0)
        {
            tree->root->left = NULL;
            tree->root->right = Q10(arr[i+1, length-1])->root;
            return tree;

        }
        if(i == length-1)
        {
            tree->root->right = NULL;
            tree->root->left = Q10(arr[0, i-1])->root;
            return tree;
=
        }
        if(i > 0 && i < length-1)
        {
            tree->root->left = Q10(arr[0, i-1])->root;
            tree->root->right = Q10(arr[i+1, length-1])->root;
            return tree;
        }
    }
}
 


// Questions on Binary Search Trees (BST):
// Implement the following functions in C:

//Q11
// Create a BST by inserting the elements 6, 1, 4, 7, 5, 8, 2, 3, 9. Then, remove 8 and 4 from the obtained tree.
//For Q1 you don't need to write code. Just draw the tree

//Q12
// Write an algorithm gets a BST and returns the minimal element.
BTnode_t* minimal(BST_t* BST)
{
    BTnode_t* minimal = BST->root;
    while(minimal->left != NULL)
    {
        minimal = minimal->left;
    }
    return minimal;
}

//Q13
// Write an algorithm gets a BST and returns the maximal element.
BTnode_t* maximal(BST_t* BST)
{
    BTnode_t* maximal = BST->root;
    while(maximal->right != NULL)
    {
        maximal = maximal->right;
    }
    return maximal;
}
//Q14
// Write an algorithm that converts a BST into a sorted linked list with the same values.
queue_t* inorder(BST_t* BST)
{
    // queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    // BST_t* left = (BST_t*)malloc(sizeof(BST_t);
    // BST_t* right = (BST_t*)malloc(sizeof(BST_t);
    // left->root = current->left;
    // right->root = current->right;
    // inorder(BST_t* left);
    // enqueue(queue, BST->root->data);
    // inorder(BST_t* right);
    // return queue;
    stack -> enqueue
}

LL_t* convert(BST_t* BST)
{
    queue_t* queue = inorder(BST_t* BST)；
    //construct head
    LLnode_t* head = (LLnode_t*)malloc(sizeof(LLnode_t));
    head->data = dequeue(queue);
    head->next = NULL;
    LLnode_t* previous = head;
    //construct 2nd, 3rd, ... node
    while(isEmpty(queue) == 0)
    {
        LLnode_t* tmp = (LLnode_t*)malloc(sizeof(LLnode_t));
        previous->next = tmp;
        previous = tmp;
        tmp->data = dequeue(queue);
        tmp->next = NULL;
    }
    LL_t* LL = (LL_t*)malloc(LL_t);
    LL->head = head;
    return LL;
}
//Q15
// Write an algorithm that given a BST and a number k, outputs all values in the tree that are smaller than k.
void Q15(BST_t* BST, int k)
{
    if(BST-> root == NULL) return;
    BSTnode_t* current = BST->root;
    BST_t* left = (BST_t*)malloc(sizeof(BST_t);
    BST_t* right = (BST_t*)malloc(sizeof(BST_t);
    left->root = curent->left;
    right->root = current->right;
    if(current->data < k)
    {
        printf("%d", current->data);//没法用return写吧
        Q15(left, k);
        Q15(right, k);
    }
    if(curren->data >= k)
    {
        Q15(left, k);
    }
}
//Q16
// Write an algorithm that given a BST and two numbers k<ℓ, outputs all values in the tree between k and ℓ.
void Q16(BST_t* BST, int k, int ℓ)
{
    if(BST->root == NULL) return;
    BSTnode_t* current = BST->root;
    BST_t* left = malloc();
    BST_t* right = malloc();
    left->root = curent->left;
    right->root = current->right;
    if(current->data > k && current->data < ℓ)
    {
        printf("%d", current->data);//没法用return写吧
        Q16(left, k, ℓ);
        Q16(right, k, ℓ);
    }
    if(current->data <= k && current->data < ℓ)
    {
        Q16(right, k, ℓ);
    }
    if(current->data > k && current->data >= ℓ)
    {
        Q16(left, k, ℓ);
    }
}
//Q17
// Write an algorithm that gets a sequence of numbers and decides whether it is a PostOrder traversal of some BST.
bool is_post_order(int arr[], int length)
{//看左数组是不是全小于root_data,右数组是不是全大于root_data，不知道充不充足
    int root_data = arr[length-1];
    int index = 0;
    while(arr[index] < root_data)
    {
        index++;
    }
    // now index points to the first element of right tree
    for(int j = index; j < length-1; j++)
    {
        if(arr[j] <= root_data)
        {
            return 0;
        }
    }
    return is_post_order() && is_post_order();
}

//Q18
// Write an algorithm that gets a PostOrder traversal of a BST, and returns the tree. Prove that such BST is unique.
BST_t* Q18(int arr[0, length-1])
{
    BST_t* BST = (BST_t*)malloc(sizeof(BST_t));
    BST->root = malloc
    int BST->root->data = arr[length-1];
    int index = 0;
    while(arr[index] < BST->root->data)
    {
        index++;
    }
    //arr[0, index-1]is left tree
    //arr[index, length-2]is right tree
    //arr[length-1]is root

    root->left = Q18(int arr[0, index-1])->root;
    root->right = Q18(int arr[index, length-2])->root;
    return BST;
}
//Prove that such BST is unique.
//Given the specific postorder traversal, the left tree, right tree and root data of a BST have only one structure. 

//Q19
// Write an algorithms that gets a BST and a number t, and returns a node in the tree that contains the largest value that is smaller that t.
BTnode_t* Q19(BST_t* BST, int t)
{
    if(BST->root == NULL) return NULL;
    BTnode_t* current = BST->root;
    BST_t* left = (BST_t*)malloc(sizeof(BST_t));
    BST_t* right = (BST_t*)malloc(sizeof(BST_t));
    left->root = current->left;
    right->root = current->right;
    if(current->data == t)
    {
        current = current->left;
        while(current->right != NULL)
        {
            current = current->right;
        }
        return current;
    }
    if(current->data < t)
    {
        //在root和right里找
        if(Q19(right, t) > current->data)
        {
            return Q19(right, current->data);
        }else
        {
            return current->data;
        }
        
    }
    if(current->data > t)
    {
        //在left里找
        return Q19(left, t);
    }
}
//Q20
// How many distinct BSTs can be created with values 1,2,3,4?
// 4????? -> 10

//Q21
// **How many distinct BSTs can be created with values 1,2,3,…,n?
// n????

//Q22
// **How many distinct BSTs of depth n−1 can be created with values 1,2,3,…,n?
// 2???
