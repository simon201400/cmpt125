//

void permutation_helper(int n, int* a, int k)
{
    if(k == n){
        //print the permutation
        for(int i = 0; i <n ;i++)
        {
            printf("%d",a[i]);
        }
    printf("\n");
    }
    for(int i = k; i < n; i++)
    {
        swap(&a[k], &a[i]);//set a[i] to be the next value
        permutation_helper(n, a, k+1)
        swap(&a[k], &a[i]);
    }
}
void print_all_permutations(int n)
{
   int* a = (int*)malloc(sizeof(int));
   //initiialise the array with[1, 2, 3, ..., n]
    for(int i = 0; i < n; i++)
    {
        a[i] = i+1;
    }
    permutation_helper(n, a, 0) 
}