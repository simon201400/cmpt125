Remove (BST_t* tree, BTnode_t* node)
{
	//find successor
	BTnode_t* successor = node;
	successor = successor->right;
	while(successor-> left != NULL)
	{
		successor = successor->left;
	}
	node->data = successor->data;
	free(successor);
	successor = NULL;
}

