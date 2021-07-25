#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<string> operations)
{
	vector<int> answer;
	vector<pair<string, string> > operations_pair;
	for (auto i : operations)
	{
		string temp1; string temp2; size_t found = i.find(" ");
		temp1 = i.substr(0, found);
		temp2 = i.substr(found + 1);
		pair<string, string> pair_str(temp1, temp2);
		operations_pair.push_back(pair_str);
		// cout << "temp1:" << temp1 << endl;
		// cout << "temp2:" << temp2 << endl;
	}
	for (auto i : operations_pair)
	{
		if (i.first == "I")
		{
			answer.push_back(stol(i.second));
		}
		else if (i.first == "D")
		{
			if (answer.size() != 0)
			{
				if (i.second == "1")
				{
					answer.erase(max_element(answer.begin(), answer.end()));
				}
				else if (i.second == "-1")
				{
					answer.erase(min_element(answer.begin(), answer.end()));
				}
			}
		}
	}
	vector<int> max_min;
	if (answer.size() == 0)
	{
		max_min.push_back(0);
		max_min.push_back(0);
		return (max_min);
	}
	max_min.push_back(*max_element(answer.begin(), answer.end()));
	max_min.push_back(*min_element(answer.begin(), answer.end()));
	return max_min;
}

int main()
{
	vector<string> vector1 = {"I 7","I 5","I -5","D -1"};
	vector<string> vector2 = {"I 16","D 1"};
	vector<string> vector3 = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
	vector<int> temp = solution(vector3);
	cout << temp[0] << endl;
	cout << temp[1] << endl;
	return(0);
}

/*
["I 16","D 1"]	[0,0]
["I 7","I 5","I -5","D -1"]	[7,5]

["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]	[0, 0]
*/