/* Write a function that computes the Fibonacci sequence:
			Fib(0) = 0, Fib(1) = 1		Fib(N) = Fib(N-1) + Fib(N-2)		for  N >=2
Write a recursive implementation
Write an iterative implementation
*/

#include <stdio.h>

//recursive method
/*int Fib(int N)
{
    if(N == 0) return 0;
    if(N == 1) return 1;
    return Fib(N-1) + Fib(N-2);
}*/

//iterative method❗️❗️❗️❗️❗️❗️❗️
int Fib(int N)
{
    int prev_prev = 0;
    int prev = 0;
    int current = 1;
    if(N == 0) return 0;
    if(N == 1) return 1;
    for(int i = 2; i <= N; i++)
    {
        prev_prev = prev;
        prev = current;
        current = prev_prev + prev;
    }
    return current;
}

int main()
{
    for(int i = 0; i < 8; i++)
    {
        printf("%d\n", Fib(i));
    }
}