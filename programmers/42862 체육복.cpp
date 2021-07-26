#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = n - lost.size();
	vector<int> newlost;
	for (auto i : lost)
	{
		vector<int>::iterator it;
		if ((it = find(reserve.begin(), reserve.end(), i)) != reserve.end())
		{
			reserve.erase(it);
			answer++;
		}
		else
		{
			newlost.push_back(i);
		}
	}

	sort(newlost.begin(), newlost.end());
	for (auto i : newlost)
	{
		sort(reserve.begin(), reserve.end());
		vector<int>::iterator it;
		if ((it = find(reserve.begin(), reserve.end(), i - 1)) != reserve.end())
		{
			reserve.erase(it);
			answer++;
		}
		else if ((it = find(reserve.begin(), reserve.end(), i + 1)) != reserve.end())
		{
			reserve.erase(it);
			answer++;
		}
	}
	return answer;
}

int main()
{
	int n = 5;
	vector<int> vector1 = {3,1};
	vector<int> vector2 = {2,4};
	cout << solution(n, vector1, vector2) << endl;
	return(0);
}
/*
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]	4
3	[3]	[1]	2
5 [1,2] [2,3] 4
5 [5,4,2] [2,4] 4
4 [4,2] [3,5] 4

5 [3,1] [2,4] 5
*/