#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

bool reverse_comp(vector<int> &a, vector<int> &b)
{
	return (a[0] > b[0]);
}

class priority_comp
{
	public:
		bool operator()(pair<int, int> &a, pair<int, int> &b)
		{
			return (a.second > b.second);
		}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int init_size = jobs.size();
	std::sort(jobs.begin(), jobs.end(), reverse_comp);
	int time = (jobs.back()[0] + jobs.back()[1]);
	answer += (time - jobs.back()[0]);
	jobs.pop_back();
	priority_queue<pair<int, int>, vector<pair<int, int> >, priority_comp > pq;
	while ( !(pq.size() == 0 && jobs.size() == 0) )
	{
		int count = jobs.size();
		int count_pop = 0;
		vector<vector<int>> jobs_copy(jobs);
		while (jobs_copy.size() != 0)
		{
			if (jobs_copy.back()[0] <= time)
			{
				pq.push(std::make_pair(jobs_copy.back()[0], jobs_copy.back()[1]));
				count_pop++;
			}
			jobs_copy.pop_back();
		}
		for (size_t i = 0; i < count_pop; i++)
		{
			jobs.pop_back();
		}

		// 컨트롤러는 하나의 작업만 실행가능
		if (pq.size() != 0)
		{
			time += pq.top().second;
			answer += time - pq.top().first;
			pq.pop();
		}
		else
		{
			time = jobs.back()[0]; // 다른 작업의 init 시간에 도달하지못했므로, 다음 작업의 init 시간으로 이동시킴
			// time++;
		}
	}
	return answer / init_size;
}

int main()
{
	vector<vector<int> > vector1 = {{0, 3}, {1, 9}, {2, 6}}; // A: 9
	cout << solution(vector1) << endl;
	return (0);
}