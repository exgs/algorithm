#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


bool func(int* temp, int size, int value)
{
	for (size_t i = 0; i < size; i++)
	{
		if (temp[i] == value)
			return (true);
	}
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	int *temp = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		temp[i] = a;
	}
	sort(temp, temp + n);
	int m;
	scanf("%d", &m);
	//int* temp = new int[n];
	for (size_t i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		if (binary_search(temp, temp + n, a) == true)
		{
			printf("%d\n", 1);
		}
		else
		{
			printf("%d\n", 0);
		}
	}
	return (0);
}
