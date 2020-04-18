//Write a function that gets two arrays of length n. The first array is the PreOrder some binary tree and the second array is the InOrder of the binary tree. The functions outputs the binary tree.
// the function recovers the tree from its inorder and preorder
BTnode_t* reconstruct_tree(int* preorder, int* inorder, int n) {
  // implement me
	if(preorder == NULL || inorder == NULL || n == 0)
	{
		return NULL;
	}

	//find the index of root in inorder
	int root_index_inorder = -1;
	for(int i = 0; i < n; i++)
	{
		if(inorder[i] == preorder[0])
		{
			root_index_inorder = i;
			break;
		}
	}

	//find left subarray and right subarray
	int* left_array_inorder = NULL;
	int* left_array_preorder = NULL;
	int* right_array_inorder = NULL;
	int* right_array_preorder = NULL;
	left_array_inorder = (int*)malloc((root_index_inorder)*sizeof(int));
	left_array_preorder = (int*)malloc((root_index_inorder)*sizeof(int));
	right_array_inorder = (int*)malloc((n - root_index_inorder - 1)*sizeof(int));
	right_array_preorder = (int*)malloc((n - root_index_inorder - 1)*sizeof(int));
	for(int i = 0; i < root_index_inorder; i++)
	{
		left_array_inorder[i] = inorder[i];
		left_array_preorder[i] = preorder[i+1];
	}
	for(int j = 0; j < n - root_index_inorder - 1; j++)
	{
		right_array_inorder[j] = inorder[root_index_inorder+1+j];
		right_array_preorder[j] = preorder[root_index_inorder+1+j];
	}

	//now we have root, left array, right array from inorder and preorder
	//construct root
	BTnode_t* root = (BTnode_t*)malloc(sizeof(BTnode_t));
	root->value = inorder[root_index_inorder];
	//construct left subtree
	root->left = reconstruct_tree(left_array_preorder, left_array_inorder, root_index_inorder);
	// //construct right subtree
	root->right = reconstruct_tree(right_array_preorder, right_array_inorder, n - root_index_inorder -1);
  return root;
}
