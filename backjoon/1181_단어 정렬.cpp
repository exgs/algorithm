#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

char buffer[51];
int main()
{
	int N; scanf("%d", &N);
	map<int, string> mapping;
	vector<pair<int, string> >temp;
	for (size_t i = 0; i < N; i++)
	{
		scanf("%s", buffer);
		string temp2(buffer);
		pair<int, string> directory(temp2.size(), temp2);
		temp.push_back(directory);
	}
	sort(temp.begin(), temp.end());
	string before = "";
	for (size_t i = 0; i < temp.size(); i++)
	{
		if (before == temp[i].second)
			continue;
		else
			before = temp[i].second;
		printf("%s\n", temp[i].second.c_str());
	}
	return (0);
}


/*
   auto comp = [](string& str1, string& str2) {
        if (str1.size() != str2.size())
            return str1.size() < str2.size();
        return str1 < str2;
    };
    sort(vs.begin(), vs.end(), comp);
    vs.erase(unique(vs.begin(), vs.end()), vs.end());

*/