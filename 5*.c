/*Practice questions related to stacks, queues, linked lists
In questions 1-10 below you may only use the standard functions of Stack and Queue.
You may not assume that you have access to the implementation of the classes.
For Queue the functions are: enqueue, dequeue, isEmpty.
For Stack the functions are: push, pop, isEmpty.
For Linked List the functions are: add_to_head, add_to_tail, remove_from_head, remove_from_tail,
as well as list->head, node->next, node->data....*/

//Q1
/*Write a function node_t* get_middle(LL_t* list). * The function gets a linked list, 
and returns the pointer to the middle element. * If the number of element in the list is even, 
it returns the pointer to the element in position (size/2).
* If the list is empty the function returns NULL. * You may not assume that you have the size() function.*/
node_t* get_middle(LL_t* list){
	if(list->head = NULL){
		return NULL;
	}
	int size = 1;
	int i = 1;
	node_t* current = list -> head;
    node_t* middle = list -> head;
    //compute size
	while(current->next != NULL){
		current = current->next;
		size++;
	}
    //move *middle
	if(size % 2 = 0){
		while(i < size/2){
			middle = middle->next;
			i++;
		}
		return middle;
	}else{
		while(i < (size+1)/2){
			middle = middle->next;
			i++;
		}
	return middle;
	}
}

//Q2
//Write a function bool equal_lists(LL_t* list1, LL_t* list2).                              
//* The function gets two link lists and checks if the have same elements in the same order.      
//* In the end both lists must be in the same state as in the beginning.

bool equal_lists(LL_t* list1, LL_t* list2)
{
	node_t *p = list1->head;
	node_t *q = list2->head;
	// while(p->data == q->data)
	// {
	// 	if(p->next == NULL && q->next == NULL){
	// 		return 1;
	// 	}else{
	// 		p = p->next;
	// 		q = q->next;
	// 		}
	// }
	// return 0;
	while(1)
	{
		if(p->data != q->data)
		return 0;
		if(p->next == NULL || q->next == NULL)
		{
			if(p->next == NULL && q->next == NULL) return 1;
			return 0;
		}
		p = p->next;
		q = q->next;
	}
}

//Q3❗️❗️❗️❗️❗️❗️❗️❗️❗️✅
//Write a function LL_t* copy_list(LL_t* orig).    
//* The function gets a pointer to a linked list, and returns a copy with the have same 
//elements in the same order.   
//* In the end orig must be in the same state as in the beginning.

LL_t* copy_list(LL_t* orig)
{
	//create
	LLnode_t* pmove = orig->head;
    LL_t* new;
    new = (LL_t*) malloc(sizeof(LL_t));
    
	//contruct first node of new list
	LLnode_t* head = (LLnode_t*)malloc(LLnode_t);
	head->data = pmove->data;
	pmove = pmove->next;
	LLnode* previous = head;

	//copy 2nd,3rd,… node
	while(pmove != NULL)
	{
		LLnode_t* temp = (LLnode_t*) malloc(sizeof(LLnode_t));
		temp->data = pmove->data;
		previous->next = temp;//我总是左右写反❗️
		pmove = pmove->next;
		previous = temp;
	}
	return new;
}

//Q4
//Write a function bool equal_queues(queue_t* q1, queue_t* q2).   
//* The function gets two queues and checks if the have same elements in the same order.  
//* In the end both queues must be in the same state as in the beginning.

bool equal_queues(queue_t* q1, queue_t* q2)
{
	if(q1 == NULL && q2 == NULL)
	{
		return 1;
	}

	while(1)
	{
		if(isEmpty(q1) || isEmpty(q2))
		{
			if(isEmpty(q1) && isEmpty(q2)) return 1;
			return 0;
		}
		int t1 = dequeue(q1);
		int t2 = dequeue(q2);

		if(t1 != t2) return 0;
	}

	return 1;
}

//Q5
//Write a function queue_t* copy_queue(queue_t* orig).   
//* The function gets a pointer to queue, and returns a copy with the have same elements in the same order.   
//* In the end orig must be in the same state as in the beginning.

queue_t* copy_queue(queue_t* orig)
{
	queue_t* new = (queue_t*)malloc(sizeof(queue_t));
	queue_t* tmp = (queue_t*)malloc(sizeof(queue_t));
	while(!isEmpty(orig))
	{
		int item = dequeue(orig);
		enqueue(tmp, item);
		enqueue(new, item);
	}
	while(!isEmpty(tmp))
	{
		int item = dequeue(tmp);
		enqueue(orig, item);
	}

	return new;
}

//Q6
//Write a function bool equal_stacks(stack_t* s1, stack_t* s2).  
//* The function gets two stacks and checks if the have same elements in the same order.  
//* In the end both stacks must be in the same state as in the beginning.

bool equal_stacks(stack_t* s1, stack_t* s2)//✅
{
	if(s1 == NULL && s2 == NULL)
	{
		return true;
	}
	if(s1 == NULL || s2 == NULL)
	{
		return false;
	}
	while(1)
	{
		int p = pop(s1);
		int q = pop(s2);
		if(p != q)
		{
			return false;
		}
		//p == q
		if(isEmpty(s1) && isEmpty(s2))
		{
			return true;
		}
		if(isEmpty(s1) || isEmpty(s2))
		{
			return false;
		}
	}
}

//Q7
//Write a function stack_t* copy_stack(stack_t orig).   
//* The function gets a pointer to stack, and returns a copy with the have same elements in the same order.   
//* In the end the orig must be in the same state as in the beginning.

stack_t* copy_stack(stack_t orig)
{
	stack_t* tmp = (stack_t*)malloc(sizeof(stack_t));
	stack_t* new = (stack_t*)malloc(sizeof(stack_t));
	while(!isEmpty(orig))
	{
		int item = pop(orig);
		push(tmp, item);
	}
	while(!isEmpty(tmp))
	{
		int i = pop(tmp);
		push(new, i);
		push(orig, i);
	}
	free(tmp);
	return new;
}

//Q8
//Write a function void reverse_queue(queue_t* queue)   
//* The function gets a queue and reverses the order of the elements in queue.

//用stack做
void reverse_queue(queue_t* queue)//新写的❗️
{
	stack_t* tmp = (stack_t*)malloc(stack_t);
	while(queue != NULL)
	{
		int item = dequeue(queue);
		push(tmp, item);
	}
	while(tmp != NULL)
	{
		int item = pop(tmp);
		enqueue(queue, item);
	}
	free(tmp);
}

//用数组做
void reverse_queue(queue_t* queue)
{
	//get length for arr malloc
	queue_t* tmp = (queue_t*)malloc(sizeof(queue_t));
	int length = 0;
	while(!isEmpty(queue))
	{
		int item = dequeue(queue);
		enqueue(tmp, item);
		length++;
	}
	//get data array
	int* arr = (int*) malloc(length*sizeof(int));
	int index = 0;
	while(!isEmpty(tmp))
	{
		int item = dequeue(tmp);
		arr[index] = item;
		index++;
	}
	//get reverse queue by iteration
	for(int i = length-1; i >= 0; i--)
	{
		push(queue, arr[i]);
	}
	free(tmp);
	free(arr);
}

//Q9
//Write a function void reverse_stack(stack_t* stack).  
//* The function gets a stack and reverses the order of the elements in the stack.

//用queue做
void reverse_stack(stack_t* stack)//新写的❗️
{
	queue_t* tmp = (queue_t*)malloc(sizeof(queue_t));
	while(stack != NULL)
	{
		int item = pop(stack);
		enqueue(tmp, item);
	}
	while(tmp != NULL)
	{
		int item = dequeue(tmp);
		push(tmp, item);
	}
	free(tmp);
}

//用数组做
void reverse_stack(stack_t* stack)
{
	stack_t* tmp;
	while(!isEmpty(stack))
	{
		int item = dequeue(stack);
		enqueue(tmp, item);
		length++;
	}
	int* arr = (int*)malloc(length*sizeof(int));
	int index = 0;
	while(!isEmpty(tmp))
	{
		int item = dequeue(tmp);
		arr[index] = item;
		index++;
	}
	for(int i = length-1; i >= 0; i--)
	{
		int item = arr[i];
		push(stack, item);
	}
	free(tmp);
	free(arr);
}


//Q10
//Implement Queue using two stacks and O(1) additional memory.
stack_t* stack1 = malloc();
stack_t* stack2 = malloc();

void enqueue(int new_item)
{
	while(!isEmpty(stack2))
	{
		int item = pop(stack2);
		push(stack1, item);
	}
	push(stack1, new_item);
}

void dequeue()
{
	while(!isEmpty(stack1))
	{
		int item = pop(stack1);
		push(stack2, item);
	}

	pop(stack2);
}

bool isEmpty()
{
	return isEmpty(stack1) && isEmpty(stack2)
}

//Q11
/*Implement the bounded_memory_queue.
* the function create_BMqueue gets a parameter size as an argument, and the queue remembers 
only the last size elements added to the queue
* More specifically, the behavior of the class is the same as queue_t with one exception in the 
enqueue(element) function:
void enqueue(queue_t* queue, int item)
   If the queue contains less than size elements, then the new element is added to the tail of the queue.
   Otherwise, the queue removes the element from the head of the queue and adds the new element to the tail.

* For example: Suppose size = 3, and we added 'a','b','c' to the queue so that queue = (a,b,c).
Now if we try to add 'd' to the queue we will get (b,c,d).*/


void create_BMquene(queue_t* queue, int size)
{
	my_size = sizeQueue();
	
	tmp
	if(my_size < size)
	{
		for(i=0,<my_size)
		{
			dequeue(tmp)
			enqueue(queue)
			enqueue()
		}
	}
	else
	{	
		dequeue
		for(i=1;<my_size)
		{
			dequeue
			enqueue
		}

	}
	// queue_t* head = queue;
	// queue_t* tail = queue;
	// tail->rear = NULL;
	// int length = 1;
	// //move rear
	// while(length < size)
	// {
	// 	int/char i;//不知道他输入数字还是字符呀
	// 	scanf(“%d/c”,&i);
	// 	tail->data = i;
	// 	tail = tail->rear;
	// 	length++;
	// }
	// //move head
	// if(length >= size)
	// {
	// 	int i = 0;
	// 	while(i < length - size)
	// 	{
	// 		head = head->rear;
	// 		i++;	
	// 	}
	// }
	// queue = head;
	// return queue;
}

//Q12✅
//Implement Queue using an array with cyclic pointers as discussed in class. 
/*You need to implement the following function:
* queue_t* create_queue()
* void enqueue(queue_t* queue, int item)
* int denqueue(queue_t* queue)
int is_empty((queue_t* queue)*/

typedef struct node
{
	int data;
	(struct node)* next;
}node_t;

typedef struct queue
{
	(struct queue)* head;
	(struct queue)* tail;

}queue_t;

queue_t* create_queue()
{
	queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

void enqueue(queue_t* queue, int item)
{
	node_t* new = (node_t*)malloc(sizeof(node_t));
	new->data = item;
	queue->tail->next = new;
	queue->tail = new;
	tail->next = NULL;
}

int dequeue(queue_t* queue)
{
	int item = queue->head->data;
	node_t* tmp = queue->head;
	queue->head = queue->head->next;
	free(tmp);
	return item;
}

int is_empty(queue_t* queue)
{
	if(queue->head == NULL)
	{
		return 1;
	}
	return 0;
}

/*Q13
Implement the class Doubly-Linked List.  You need to implement the following function:
* DLL_t* create_DLL()
* void add_to_front(DLL_t* list, int item)
* void add_to_end(DLL_t* list, int item)
* int remove_from_front(DLL_t* list)
* int remove_from_end(DLL_t* list)*/

typedef struct DLL_node
{
	int data;
	(struct DLL_node)* next;
} DLL_node_t;

typedef struct DLL
{
	(struct DLL)* head;
	(struct DLL)* tail;
}DLL_t;

DLL_t* create_DLL()
{
	DLL_t* DLL = (DLL_t*)malloc(sizeof(DLL_t));
	DDL->head = NULL;
	DLL->tail = NULL;
	return DLL;
}


void add_to_front(DLL_t* list, int item)
{
	DLL_node_t* new = (DLL_node_t*)malloc(sizeof(DLL_node_t));
	new->data = item;
	new->next = list->head;
	list->head->prev = new;
	list->head = new;
}

void add_to_end(DLL_t* list, int item)
{
	DLL_node_t* new = (DLL_node_t*)malloc(sizeof(DLL_node_t));
	new->data = item;
	new->prev = list->tail;
	list->tail->next = new;
	list->tail = new;
}

int remove_from_front(DLL_t* list)
{
	DLL_node_t* remove_me = list->head;
	int item = head->data;
	list->head = list->head->next;
	head->prev = NULL;
	free(remove_me);
	return item;
}

int remove_from_end(DLL_t* list)
{
	DLL_node_t* remove_me = list->tail;
	list->tail = list->tail->prev;
	int item = list->tail->next->data;
	list->tail->next = NULL;
	free(remove_me);
	return item;
}