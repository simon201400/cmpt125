//remove node with no children
void Remove (BST_t* tree, BTnode_t* node)
{
	if(node->parent == NULL) 
	{	
		free(node);
		tree->root = NULL;
		return;
	}
	BTnode_t* parent = node->parent;
	if(parent->left == node)
	{
		parent->left = NULL;
	}
	else
	{
	
		parent->right = NULL;
	}
	free(node);
}
