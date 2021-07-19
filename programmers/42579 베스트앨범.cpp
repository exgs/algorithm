#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


bool comp1(const vector<pair<int, int> > &a, const vector<pair<int, int> > &b)
{
	int total = 0;
	for (auto i : a)
		total += i.second;
	for (auto i : b)
		total -= i.second;
	if (total > 0)
		return true;
	return false;
}

bool comp2(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second)
	{
		return (a.first < b.first);
	}
	else
	{
		return (a.second > b.second);
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, vector<pair<int, int> > > temp;
	int count = genres.size();
	vector<int> answer;
	for (size_t i = 0; i < count; i++)
	{
		temp[genres[i]].push_back(std::make_pair(i, plays[i]));
	}

	vector<vector<pair<int, int> > > temp2;
	for (auto i : temp)
	{
		temp2.push_back(i.second);
	}
	

	sort(temp2.begin(), temp2.end(), comp1);
	for (vector<pair<int, int> > &i : temp2)
	{
		sort(i.begin(), i.end(), comp2);
	}

	for (auto i : temp2)
	{
		for (auto j : i)
		{
			cout << j.first << " : " << j.second << endl;
		}
	}
	cout << "--------" << endl;
	for (auto i : temp2)
	{
		int count = 0;
		for (auto j : i)
		{
			if (++count > 2)
				break;
			answer.push_back(j.first);
		}
	}
	return answer;
}

int main()
{
	vector<string> vector1 = {"classic", "pop", "classic", "classic", "pop"};
	vector<int> vector2 = {500, 600, 150, 800, 2500};
	vector<int> temp = solution(vector1, vector2);
	
	for (auto i : temp)
	{
		cout << i << endl;
	}
	return(0);
}

/*
1.
["classic", "pop", "classic", "classic", "pop"]
[500, 600, 150, 800, 2500]
[4, 1, 3, 0]

*/