// returns the sum of elements in the tree greater than k
int sum_greater_than_k(BST_t* tree, int k) {
  // implement me
	if(tree->root == NULL)
		return 0;
	struct BTnode* current = tree->root;
	int sum = 0;
	if(current->value <= k)//only search right
	{
		BST_t* right = (BST_t*)malloc(sizeof(BST_t*));
		right->root = current->right;
		sum = sum_greater_than_k(right, k);
	}
	if(current->value > k)
	{
		BST_t* left = (BST_t*)malloc(sizeof(BST_t*));
		left->root = current->left;
		BST_t* right = (BST_t*)malloc(sizeof(BST_t*));
		right->root = current->right;
		sum = current->value + sum_greater_than_k(left, k) + sum_greater_than_k(right, k);
	}
  return sum;
}
