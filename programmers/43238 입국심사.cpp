#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

long long totalpeople(vector<int> &times, long long mid)
{
	long long peoples = 0;
	for (auto i : times)
	{
		peoples += floor((double)mid / i);
	}
	return peoples;
}

long long solution(int n, vector<int> times)
{
	long long max = (long long)n * (*max_element(times.begin(), times.end()));
	long long answer = max;
	long long min = 1;
	long long mid;
	while (min <= max)
	{
		mid = (max + min) / 2;
		long long people = totalpeople(times, mid);
		if (n > people)
		{
			min = mid + 1;
		}
		else
		{
			answer = std::min(answer, mid);
			max = mid - 1;
		}
		// cout << min << ":" << max << endl;
	}
	return answer;
}

int main()
{
	vector<int> vector1 = {2,3,4,5,100};
	int n = 6;
	cout << solution(n, vector1) << endl;
	return (0);
}
/*
6 [7, 10]	28
6 [1, 10111]	6 
101 [1, 100] 100
100 [1, 100] 100
99 [1, 100] 99
6 [2, 3, 4, 5, 100] 6 크리티컬히트
*/


/* Brute force
int min_whenTwice(vector<long long> data, vector<int> times)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		data[i] += times[i];
	}
	return (distance(data.begin(), min_element(data.begin(), data.end())));
}

long long solution(int n, vector<int> times)
{
	long long answer = 0;
	vector<long long> data;
	data.resize(times.size());
	fill(data.begin(), data.end(), 0);

	while (n > 0)
	{
		size_t i = min_whenTwice(data, times);
		data[i] += times[i];
		n--;
	}
	answer = *max_element(data.begin(), data.end());
	return answer;
}


*/