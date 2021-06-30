#include <iostream>
#include <algorithm>

int main()
{

	int n;
	scanf("%d", &n);
	int *array = new int[n];

	for (size_t i = 0; i < n; i++)
	{
		int m; scanf("%d", &m);
		array[i] = m;
	}
	std::sort(array, array + n);
	// std::reverse(array, array + n);
	for (size_t i = 0; i < n; i++)
	{
		printf("%d\n", array[i]);
	}
	
	return (0);
}