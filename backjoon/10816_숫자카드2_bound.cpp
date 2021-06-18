#include <iostream>
#include <algorithm>
using namespace std;

int arr[500003];

int main()
{
	int N, M, in;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		arr[i] = temp;
	}
	sort(arr, arr + N);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &in);
		if (i == M -1)
		{
			printf("%d", upper_bound(arr, arr + N, in) - lower_bound(arr, arr + N, in));
			break;
		}
		printf("%d ", upper_bound(arr, arr + N, in) - lower_bound(arr, arr + N, in));
	}
	printf("\n");
}