#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> gPath;
int flag;

void recursive(vector<vector<string>> tickets, vector<string> path, string dest)
{
	path.push_back(dest);
	if (tickets.size() == 0)
	{
		if (flag++ == 0)
			gPath = path;
		else
		{
			// if (!lexicographical_compare(gPath.begin(), gPath.end(), path.begin(), path.end()))
			// vector<string> 을 비교하면 사전식으로 비교해준다.
			if (gPath > path)
			{
				gPath = path;
			}
		}
		return ;
	}
	
	for (size_t i = 0; i < tickets.size(); i++)
	{
		string src = tickets[i][0];
		if (src == dest)
		{
			vector<vector<string>> tickets_copy(tickets);
			string new_dest = tickets_copy[i][1];
			tickets_copy.erase(tickets_copy.begin() + i);
			recursive(tickets_copy, path, new_dest);
		}
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	for (size_t i = 0; i < tickets.size(); i++)
	{
		string src = tickets[i][0];
		if (src == "ICN")
		{
			vector<vector<string> > tickets_copy(tickets);
			vector<string> path;
			string new_dest = tickets[i][1];
			path.push_back(src);
			tickets_copy.erase(tickets_copy.begin() + i);
			recursive(tickets_copy, path, new_dest);
		}
	}
	vector<string> answer = gPath;
	return answer;
}

int main()
{
	vector<vector<string> > temp1 = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
	vector<vector<string> > temp2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
	
	for (auto temp : solution(temp2))
	{
		cout << temp << endl;
	}
	return(0);
}

/*
{["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]	["ICN", "JFK", "HND", "IAD"]
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]	["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
*/