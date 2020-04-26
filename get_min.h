//Q4
// returns the minimal element in the binary search tree
// assumption: tree is not empty
int get_min(BST_t* tree) {
//   implement me
  	struct BTnode* current = tree->root;
	while(current->left != NULL)
	{
		current = current->left;
	}

  return current->value;
}
