#include <iostream>

using namespace std;

unsigned int arr[100];

int main()
{
	int N, M;
	scanf("%d", &N); scanf("%d", &M);
	for (size_t i = 0; i < N; i++)
	{
		unsigned int temp;
		scanf("%d", &temp);
		arr[i] = temp;
	}
	
	int i = 0;
	int j = i + 1;
	int k = j + 1;
	int sum = 0;
	while (i < N - 2)
	{
		j = i + 1;
		while (j < N - 1)
		{
			k = j + 1;
			while (k < N)
			{
				int temp;
				temp = arr[i] + arr[j] + arr[k];
				if (M == temp)
				{
					printf("%d\n", M);
					return (0);
				}
				else if (sum < temp && temp < M)
				{
					sum = temp;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	printf("%d\n", sum);
	return (0);
}