#include <iostream>
#include <algorithm>

int main()
{
	int array[10000] = {0, };
	int max = 10000;
	int n;
	scanf("%d", &n);


	int i = 0;
	while (i < n)
	{
		int m; scanf("%d", &m);
		array[m - 1]++;
		i++;
	}
	i = 0;
	while (i < max)
	{
		int value  = i + 1;
		while (array[i] != 0)
		{
			printf("%d\n", value);
			array[i]--;
		}
		i++;
	}
	return (0);
}