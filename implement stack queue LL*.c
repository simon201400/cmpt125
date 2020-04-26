/*Implement the ADT ​queue of ints.​ The running time of each operation must be O(1). In your code you may use the struct ​node_t​.
If you want to use functions related to Linked List, you need to implement them.
struct​ node {
​int​ data;
​struct​ node* next;
};
​typedef​ ​struct​ node node_t;*/

typedef​ ​struct​ 
{
    node_t* head;
    node_t* tail;
} queue_t;

queue_t* queue_create() 
{
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void​ enqueue(queue_t* q, ​int​ item) 
{
    node_t* new = (node_t*)malloc(sizeof(node_t));
    q->tail->next = new;
    q->tail = new;
    q->tail->data = item;
}

int​ dequeue(queue_t* q) 
{
    int item = q->head->data;
    node_t* remove = q->head;
    q->head = q->head->next;
    free(remove);
    return item;
}

int​ queue_is_empty(queue_t* q)
{
    if(q->head == NULL) return 1;
    return 0;
}

/*Implement the ADT ​stack of ints.​ The running time of each operation must be O(1). In your code you may use the struct ​node_t​.
If you want to use functions related to Linked List, you need to implement them.
struct​ node {
​int​ data;
​struct​ node* next;
};
​typedef​ ​struct​ node node_t;*/

typedef​ ​struct​ 
{
    node_t* bottom;
    node_t* top;
} stack_t;

stack_t* stack_create() 
{
    stack_t* s = (stack_t*)malloc(sizeof(stack_t));
    s->bottom = NULL
    s->top = NULL;
    return s;
}

void​ stack_push(stack_t* s, ​int​ item) 
{
    node_t* new = (node_t*)malloc(sizeof(node_t));
    s->top->next = new;
    s->top = new;
    new->data = item;
}

int​ stack_pop(stack_t* s) 
{
    int item = s->top->data;
    node_t* previous = s->bottom;
    while(previous->next != s->top)
    {
        previous = previous->next;
    }
    free(s->top);
    s->top = previous;
    return item;
}

int​ stack_is_empty(stack_t* s) 
{ 
    if(s->bottom == NULL) return 1;
    return 0;
}

//implement linked list