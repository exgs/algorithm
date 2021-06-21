#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <pair<int, int> >class_data;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int weight; int height; scanf("%d", &weight); scanf("%d", &height);
		std::pair<int, int> temp_pair(weight, height);
		class_data.push_back(temp_pair);
	}

	for (int i = 0; i < N; i++)
	{
		int rank = 0;
		std::pair<int, int> cur = class_data[i];
		for (int j = 0; j < class_data.size(); j++)
		{
			std::pair<int, int> temp = class_data[j];
			if (temp.first > cur.first && temp.second > cur.second)
			{
				rank++;
			}
		}
		cout << (rank + 1) << " ";
	}	
	cout << endl;
	return (0);
}