//Add a new element at the front
void add_to_head(LL_t* list, int data)
{
    LLnode_t* new_head = create_node(data);
    new_head->next = list->head;
    list->head = new_head;
}

//Add a new element at the end
void add_to_end(LL_t* list, int data)
{
    LLnode_t* new_tail = create_node(data);
    new_tail->next = NULL;
    list->tail->next = new_tail;
    list->tail = new_tail;
}

//remove_from_head
void remove_from_head (LL_t* list)
{
    LLnode_t* current = list->head;
    list->head = list->head->next;
    //current->next = NULL;
    free(current);
}

//remove_from_tail
void remove_from_tail(LL_t* list)
{
    LLnode_t* new_tail = list->head;
    while(new_tail->next != list_tail)
    {
        new_tail = new_tail->next;
    }
    LLnode_t* remove = list->tail;
    list->tail = new_tail;
    new_tail->next = NULL;
    free(remove);
}

//Insert an element after a specific node
void insert(LL_t* list, LLnode_t* node, int data)
{
    LLnode_t* insert = create_node(data);
    insert->next = node->next;
    node->next = insert;
}

//Remove a given node
void remove(LL_t* list, LLnode_t* node)
{
    LLnode* front = list->head;
    while(front->next != node)
    {
        front = front->next;
    }
    front->next = node->next;
   // node->next = NULL;
    free(node);
}

//Find element
LLnode_t* find(LL_t* list, int data)
{
    LLnode_t* current = list->head;
    while(current->value != data)
    {
        current = current->next;
    }
    return current;
}
//Return element in a specified index
int index(LL_t* list, int data)
{
    LLnode_t* current = list->head;
    int index = 0;
    while(current->value != data)
    {
        current = current->next;
        index++;
    }
    return index;
}
//Get size
int get_size(LL_t* list)
{
    LLnode_t* current = list->head;
    int size = 1;
    while(current->next != NULL)
    {
        current = current->next;
        size++;
    }
    return size;
}