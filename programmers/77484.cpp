#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
	set<int> mine;
	int zero_count = 0;
	int nonzero_count = 6;
	for (size_t i = 0; i < lottos.size(); i++)
	{
		mine.insert(lottos[i]);
	}
	if (mine.size() == 6)
	{
		if (mine.find(0) != mine.end())
		{
			zero_count = 1;
		}
		nonzero_count = nonzero_count - zero_count;
	}
	else
	{
		zero_count = 6 - mine.size() + 1;
		nonzero_count = nonzero_count - zero_count;
	}
	int count = 0;
	
	while (win_nums.size() != 0)
	{
		if (mine.find(win_nums.back()) != mine.end())
		{
			count++;
		}
		win_nums.pop_back();
	}
	int rank;
	if (nonzero_count == 6)
	{
		rank = 7 - count;
		if (rank == 7)
			rank = 6;
		answer.push_back(rank);
		answer.push_back(rank);
		return (answer);
	}
	else
	{
		int max_count;
		int min_count;
		max_count = count + zero_count;
		min_count = count;
		rank = 7 - max_count;
		answer.push_back(rank);
		rank = 7 - min_count;
			if (rank == 7)
				rank = 6;
		answer.push_back(rank);
	}
    return answer;
}