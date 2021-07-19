#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> fashion;

	for (auto i : clothes)
	{
		string name;
		string kind;
		name = i[0];
		kind = i[1];
		fashion[kind]++;
	}
	for (auto i : fashion)
	{
		answer *= (i.second + 1);
	}
	return answer - 1;
}

int main()
{
	vector<vector<string> > vector1 = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
	vector<vector<string>> vector2 = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
	cout << solution(vector2) << endl;
	return(0);
}

/*
[["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]	5
[["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]	3
*/