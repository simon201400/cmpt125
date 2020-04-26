int distance (BTnode* u, BTnode* v)
{
	//算各自到root的距离(=depth)，记录ancesters到数组
	int depth_u = 0, depth_v = 0, index_u = 0, index_v = 0, distance = 0;
	BTnode* ancesters_u[10000];
	BTnode* ancesters_v[10000];

	while(u -> parent != NULL)
	{
		depth_u++;
		u = u -> parent;
		ancesters_u[index_u] = u;
		index_u++;
	}
	while(v -> parent != NULL)
	{
		depth_v++;
		v = v -> parent;
		ancesters_v[index_v] = v;
		index_v++;
	}
	//颠倒数组,重写了
	BTnode** reverse_ancesters_u = (BTnode**)malloc(10000*sizeof(BTnode*));
	BTnode** reverse_ancesters_v = (BTnode**)malloc(10000*sizeof(BTnode*));
	for(int i = index_u; i >= 0, i--)
	{
		int index = 0;
		reverse_ancesters_u[index] = ancesters_v[i];
	}
	for(int j = index_v; j >= 0, j--)
	{
		int index = 0;
		reverse_ancesters_v[index] = ancesters_v[j];
	}
	//从头找颠倒的字符串的相同部分
	int index = 0;
	int num_of_common_ancesters = 1;
	while(reverse_ancesters_u[index] == reverse_ancesters_v[index])
	{
		num_of_common_ancesters++;
		index++;
	}
	//计算
	distance = depth_u + depth_v - (num_of_common_ancesters - 1)*2;
	return distance；
}