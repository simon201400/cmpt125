// returns the sum of elements in the tree
int get_sum(BTnode_t* tree) {
    // implement me
	int sum = 0, sum_left = 0, sum_right = 0;
	BTnode_t* current = tree;

	if(tree == NULL)
	{
		return 0;
	}

	// compute left and right subtree
	if(current->left != NULL)
	{
		sum_left = get_sum(current->left);
	}
	if(current->right != NULL)
	{
		sum_right = get_sum(current->right);
	}

	sum = current->value + sum_left + sum_right;

  return sum;
}
