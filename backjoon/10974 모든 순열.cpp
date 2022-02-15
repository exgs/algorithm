#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main()
{
	int n;
	scanf("%d", &n);
	string temp = "87654321";
	temp = temp.substr(temp.size() - n);
	sort(temp.begin(), temp.end());
	do
	{
		for (size_t i = 0; i < temp.size(); i++)
		{
			cout << temp[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(temp.begin(), temp.end()));
	return (0);
}
