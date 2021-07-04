#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; scanf("%d", &N);
	vector<pair<int, int> >temp;
	for (size_t i = 0; i < N; i++)
	{

		int x; int y;
		scanf("%d", &y); scanf("%d", &x);
		pair<int, int> x_y(x,y);
		temp.push_back(x_y);
	}
	sort(temp.begin(), temp.end());

	for (size_t i = 0; i < temp.size(); i++)
	{
		printf("%d %d\n", temp[i].second, temp[i].first);
	}
	
	
	return (0);
}