#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer;
	unordered_map<string, int> temp;
	for (size_t i = 0; i < participant.size(); i++)
	{
		temp[participant[i]]++;
	}
	for (size_t i = 0; i < completion.size(); i++)
	{
		temp[completion[i]]--;
	}

	unordered_map<string, int>::iterator it; it = temp.begin();
	while (it != temp.end())
	{
		if (it->second > 0)
		{
			return (answer = it->first);
		}
		it++;
	}
	return "";
}

int main()
{

	vector<string> participant = {"mislav", "stanko", "mislav", "ana"}; 
	vector<string> completion = {"stanko", "ana", "mislav"};

	vector<string> participant1 = {"leo", "kiki", "eden"};
	vector<string> completion1 = {"eden", "kiki"};

	vector<string> participant2 = {"marina", "josipa", "nikola", "vinko", "filipa"};
	vector<string> completion2 = {"josipa", "filipa", "marina", "nikola"};

	string temp = solution(participant, completion);
	cout << temp << endl;
	return(0);
}