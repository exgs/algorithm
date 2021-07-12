#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>

using namespace std;

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations)
{
	vector<int>::iterator it = max_element(citations.begin(), citations.end());
	int max = *it;
	while (max)
	{
		int count = 0;
		for (size_t i = 0; i < citations.size(); i++)
		{
			if (citations[i] >= max)
			{
				count++;
			}
		}
		if (count >= max)
			return (max);
		max--;
	}
	return max;
}

int main()
{
	vector<int> vector1 = {3, 0, 6, 1, 5}; // 3
	vector<int> vector2;
	int a = 0; int b = 0; int c = 0;
	cout << solution(vector1) << endl;
	return(0);
}