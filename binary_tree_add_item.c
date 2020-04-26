BTnode_t* add_item (binary_tree_t* tree, int item) {
	BTnode* current = tree->root;
	while(1)
	{
		if(item < current -> data)
		{
			if(current -> left != NULL)
			{
				current = current->left;
			}else//current -> left == NULL
			{
				BTnode_t* add = (BTnode_t*)malloc(sizeof(BTnode_t));
				current->left = add;
				//add = current->left//是这样吗
				add->data = item;
				add->left = NULL;
				add->right = NULL;
				return add;
			}
			}
		else if(item >= current -> data)
		{
			if(current -> right != NULL)
			{
				current = current->right;
			}else//current -> right = =NULL
			{
				BTnode_t* add = (BTnode_t*)malloc(sizeof(BTnode_t));
				current->right = add;
				//add = current->right//是这样吗
				add->data = item;
				add->left = NULL;
				add->right = NULL;
				return add;
			}
		}
	}
}