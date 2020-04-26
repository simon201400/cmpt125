Remove (BST_t* tree, BTnode_t* node)
{
	if(node->right == NULL)
	{
		node->data = node->left->data;
		free(node->left);
		node->left = NULL;
		return;
	}else{
		node->data = node->right->data;
		free(node->right);
		node->right = NULL;
		return;
		}
}
