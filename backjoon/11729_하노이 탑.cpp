#include <iostream>

static int num = 0;
static void hanoi(int src, int stop, int dst, int N)
{
	if (N == 1)
	{
		printf("%d %d\n", src, dst);
		return ;
	}
	
	hanoi(src, dst, stop, N - 1);
	hanoi(src, stop, dst, 1);
	hanoi(stop, src, dst, N - 1);
	return ;
}

static void hanoi_num(int src, int stop, int dst, int N)
{
	if (N == 1)
	{
		num++;
		return ;
	}
	
	hanoi_num(src, dst, stop, N - 1);
	hanoi_num(src, stop, dst, 1);
	hanoi_num(stop, src, dst, N - 1);
	return ;
}
int main()
{
	int N;
	scanf("%d", &N);

	hanoi_num(1, 2, 3, N);
	printf("%d\n", num);
	hanoi(1, 2, 3, N);
	return (0);
}