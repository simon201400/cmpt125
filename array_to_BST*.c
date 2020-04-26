/*Suppose we have struct called some_data:
typedef struct {
	…
} some_data;
and a comparison function
	compare_data(some_data* d1, some_data* d2)
that returns 1 if d1 > d2, returns -1 if d1 <= d2.

A function array_to_BST() that gets an array of N elements of some_data, 
and creates a BST containing all the elements, where the items are compared using the function compare_data().
Prove that the running time of array_to_BST() must be at least Nlog(N)*/
//不会写

BST_t* array_to_BST(some_data arr[n])
{
    BST_t* tree = (BST_t*)malloc(sizeof(BST_t));
	tree->root->data = arr[0];
	for(int i = 1; i < n; i++)
	{
		if(arr[i] < tree->root->data)
		{
			if(tree->root->left == NULL)
			{
				BTnode_t* new = (BTnode_t*)malloc(sizeof(BTnode_t));
				tree->root->left = new;
				new->data = arr[i];
				new->left = NULL;
				new->right = NULL;
			}
			if(tree->root->left != NULL)
			{
				BTnode_t* current = tree->root->left;
				if(compare_data(tree->root->left->data, arr[i]) == 1)
				{
					if(current->left == NULL)
					{
						BTnode_t* new = (BTnode_t*)malloc(sizeof(BTnode_t));
						current->left = new;
						new->data = arr[i];
						new->left = NULL;
						new->right = NULL;
					}
				}
				if(compare_data(tree->root->left->data, arr[i]) == -1)
				{
					
				}				
			}
		}
	}
}