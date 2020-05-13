// converts a arithmetic expression from tree to string
char* get_arithmetic_expression(BTnode_t* expression) {
	//printf("%d\n", expression->value);
  	// implement me
	char* final = NULL;

  	char* current = NULL;
	if(expression->left == NULL)
	{
		int value = expression->value;
		int length = -1;
		while(value != 0)
		{
			length++;
			value /= 10;
		}
		if(length == -1) length = 0;
		char* temp_char = (char*)malloc((length+1)*sizeof(char));
		current = (char*)malloc((length+1)*sizeof(char));
		value = expression->value;
		length = -1;
		temp_char[0] = '0';
		while(value != 0)
		{
			length++;
			temp_char[length] = value % 10 + '0';
			value /= 10;
		}
		if(length == -1) length = 0;
		for(int i = 0; i <= length; ++i)
		{
			current[i] = temp_char[length - i];
		}
		final = current;
	}
	else
	{	
		if(expression->value == PLUS)
		{
			current = (char*)malloc(sizeof(char));
			current[0] = '+';
		}
		else if(expression->value == MINUS)
		{
			current = (char*)malloc(sizeof(char));
			current[0] = '-';
		}
		else if(expression->value == MULT)
		{
			current = (char*)malloc(sizeof(char));
			current[0] = '*';
		}
		else if(expression->value == DIV)
		{
			current = (char*)malloc(sizeof(char));
			current[0] = '/';
		}
	
		char* left = get_arithmetic_expression(expression->left);
		char* right = get_arithmetic_expression(expression->right);
		final = (char*)malloc((7+strlen(left)+strlen(right)+1) * sizeof(char));
		final[0] = '(';
		final[1] = ' ';
		for(int i = 0; i < strlen(left); ++i)
		{
			final[i+2] = left[i];
		}
		final[2+strlen(left)] = ' ';
		final[3+strlen(left)] = current[0];
		final[4+strlen(left)] = ' ';
		for(int i = 0; i < strlen(right); ++i)
		{
			final[5+strlen(left)+i] = right[i];
		}
		final[5+strlen(left)+strlen(right)] = ' ';
		final[6+strlen(left)+strlen(right)] = ')';
	}
  	return final;
}
