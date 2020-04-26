//implementation of merge sort with double linked list✅
DLL_t* merge_sort(DLL_t* DLL)
{
    //求dll的length
    int length = 0;
    DLL_node_t* pmove = DLL->head;
    while(pmove != NULL)
    {
        pmove = pmove->next;
        length++;
    }
    //获取指向中间的指针
    int i = 1;
    DLL_node_t* median = DLL->head;
    while(i < length/2)
    {
        median = median->next;
        i++;
    }
    //recursion sort左右两侧
    DLL_t* left_DLL = (DLL_t*)malloc(sizeof(DLL_t));
    left_DLL->head = DLL->head;
    left_DLL->tail = median;
    DLL_t* right_DLL = (DLL_t*)malloc(sizeof(DLL_t));
    right_DLL->head = median->next;
    right_DLL->tail = DLL->tail;
    merge_sort(left_DLL);
    merge_sort(right_DLL);
    //construct new DLL
    DLL_t* ret = (DLL_t*)malloc(sizeof(DLL_t));
    DLL_node_t* first_node = (DLL_node_t*)malloc(sizeof(DLL_node_t));
    ret->head = first_node;
    ret->tail = first_node;
    for(int j = 1; j < length; j++)
    {
        DLL_node_t* new = (DLL_node_t*)malloc(sizeof(DLL_node_t));
        ret->tail->next = new;
        new->prev = ret->tail;
        ret->tail = new;
        ret->tail->next = NULL;       
    }   
    //merge
    DLL_node_t* pmove = new->head;
    while(left_DLL != NULL && right_DLL != NULL)
    {
        if( left_DLL->head->value > right_DLL->head->value)
        {
            pmove->value = right_DLL->head->value;
            remove_from_head(right_DLL);
            pmove = pmove->next;
        }
        if( left_DLL->head->value < right_DLL->head->value)
        {
            pmove->value = left_DLL->head->value;
            remove_from_head(left_DLL);
            pmove = pmove->next;       
        }
    }
    if(left_DLL == NULL && right_DLL != NULL)
    {
        while(right_DLL != NULL)
        {
            pmove->value = right_DLL->head->value;
            remove_from_head(right_DLL);
            pmove = pmove->next;            
        }
    }
    if(left_DLL != NULL && right_DLL == NULL)
    {
        while(left_DLL != NULL)
        {
            pmove->value = left_DLL->head->value;
            remove_from_head(left_DLL);
            pmove = pmove->next;             
        }
    }
    if(left_DLL == NULL && right_DLL == NULL)
    {
        return ret;
    }
}

//implementation of merge sort with array✅
/*void​ merge_sort(​int​* A, ​int​ n) 
{ ​
    if​ (n >= ​2​) 
    {
        ​int​ mid = n/​2​; 
        merge_sort(A, mid); 
        merge_sort(A+mid, n-mid); //❗️❗️❗️❗️❗️❗️❗️❗️这种表达方法
        merge(A,n,mid);
    } 
}
Implement the merge function that gets an array A of length n, and an index mid, 
and it is guaranteed that the part A[0,...mid-1] is sorted in ascending order, 
and A[mid...n-1] is sorted in ascending order. The function merges the two halves in time in A in time O(n).
You may assume all elements are distinct.
Remember to use malloc/free if you need to use a new array.
*/
void​ merge(​int​* A, ​int​ n, ​int​ mid) 
{
    int arr[n];
    int i = 0;
    int ind1 = 0; ind2 = mid;
    while(i < n)
    {
        if(ind1 == mid || arr[ind2] < arr[ind1])
        {
            arr[i] = arr[ind2];
            i++;
            ind2++;
        }
        if(ind2 == n || arr[ind1] < arr[ind2])
        {
            arr[i] = arr[ind1];
            i++;
            ind1++;
        }        
    }
    for(int j = 0; j < n; j++)
    {
        A[j] = arr[j];
    }
}

//implementation of selection sort
void selection_sort(DLL_node_t* head)
{
    DLL_node_t* current = head;
    DLL_node_t* pmin = head;
    while(current != NULL)
    {
        int min = current->value;
        DLL_node_t* pmove = current-> next;
        while(pmove != NULL)
        {
            if(pmove->value < min)
            {
                pmin = pmove;
                pmove = pmove->next;
            }
            swap(pmin, current);//swap data
        }
        current = current->next;
    }
}

//implementation of insertion sort with DLL重新写了❗️❗️❗️❗️❗️❗️
void insertion_sort(DLL_node_t* head)
{
    DLL_node_t* previous = head;
    DLL_node_t* pmove = head->next;
    DLL_node_t* current = head->next;
    while(current != NULL)
    {
        while(pmove->data < previous->data && previous != NULL)
        {
            swap(pmove, previous);//swap data
            previous = previous->prev;
            pmove = pmove->prev;
        }
        current = current->next;
        pmove = current;
        previous = pmove->prev;
    }
}

//implementation of insertion sort with array
void insertion_sort(int arr[n])
{
    for(int i = 0; i < n; i++)
    {
        int j = i;
        while(j != 0 && arr[j-1] > arr[j])
        {

            swap(&arr[j-1], &arr[j]);
            j--;
        }
    }
}

//implementation of quick sort with DLL重新写了❗️❗️❗️❗️❗️❗️
void quick_sort(DLL_t* DLL)
{
    DLL_node_t* pivot = DLL->head;//取第一个为pivot
    DLL_node_t* left = DLL->head->next;
    DLL_node_t* right = DLL->tail;
    while(right->value > pivot->value) right = right->prev;
    while(left->value < pivot->value) left = left->next;
    if(right->value < pivot->value && left->value < pivot->value)
    {
        swap(left, right);
        right = right->prev;
        left = left->next;
    }
    if(right->next == left || right == left)
    {
        while(left->data > pivot->data) left = left->prev;
        swap(pivot, left);
        pivot = left;
    }       
    DLL_t* left_DLL = (DLL_t*)malloc(sizeof(DLL_t));
    left_DLL->head = DLL->head;
    left_DLL->tail = pivot->prev;
    DLL_t* right_DLL = (DLL_t*)malloc(sizeof(DLL_t));
    right_DLL->head = pivot->next;
    right_DLL->tail = DLL->tail;
    quick_sort(left_DLL);
    quick_sort(right_DLL);
}

//implementation of quick sort with array
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j)
      {
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j)
         {
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

//implementation of quick sort with stack without recursion
//不会❗️❗️❗️❗️❗️❗️❗️
//lecture13最后一张
void quick_sort(arr[0,n-1])
{
    // s will contain the indices of subarrays that we need to be sorted
    //s = create_stack() of pairs of indices;
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    //把0～(n-1)放进stack
    for(int i = 0; i < n; i++)
    {
        push(stack, i);
    }

}
