#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit) 
{
	int answer = 0;
	deque<int> peoples(people.begin(), people.end());
	sort(peoples.begin(), peoples.end());
	while (peoples.size() != 0)
	{
		int sum = peoples.back();
		peoples.pop_back();
		while (sum + peoples.front() <= limit && peoples.size() != 0)
		{
			sum += peoples.front();
			peoples.pop_front();
		}
		answer++;
	}
	return answer;
}

int main()
{
	vector<int> vector1 = {70, 50, 80, 50};
	vector<int> vector2 = {70, 80, 50};
	int n = 100;
	cout << solution(vector2, n) << endl;
	return (0);
}

/*
[70, 50, 80, 50]	100	3
[70, 80, 50]	100	3
*/