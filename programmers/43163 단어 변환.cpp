#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string gtarget;
int gmin = 3000000;

bool similar(string &a, string &b)
{
	if (a.size() != b.size())
		return false;
	int size = a.size();
	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] == b[i])
			count++;
	}
	if (size - 1 == count)
		return true;
	else
		return false;
}

void recursive(string cur, vector<string> words, int count)
{
	if (cur == gtarget)
	{
		gmin = std::min(gmin, count);
		return ;
	}
	++count;
	for (auto word : words)
	{
		if (similar(cur, word))
		{
			vector<string> temp;
			temp.resize(words.size());
			std::copy(words.begin(), words.end(), temp.begin());
			temp.erase(find(temp.begin(), temp.end(), word));
			recursive(word, temp, count);
		}
	}
	return ;
}

int solution(string begin, string target, vector<string> words)
{
	int count = 0;
	gtarget = target;
	recursive(begin, words, count);
	if (gmin == 3000000)
		return (0);
	return gmin;
}

int main()
{
	string a = "hit";
	string b = "cog";
	vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

	string c = "hit";
	string d = "hot";
	vector<string> wordss = {"hot"};
	
	cout << solution(a, b, words) << endl;
	return(0);
}

// "hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]	4
// "hit"	"cog"	["hot", "dot", "dog", "lot", "log"]	0