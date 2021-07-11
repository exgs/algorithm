#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	while (priorities.size() != 0)
	{
		// cout << "location: " << location << endl;
		vector<int>::iterator it = priorities.begin();
		if (it != max_element(priorities.begin(), priorities.end()))
		{
			/* programmers에서 rotate()함수 대신에 사용했더니 오류가 남.
				iterator를 받은상태에서 push_back으로 변경되어기 때문에 그런것 같다.
			// int temp = *it;
			// priorities.push_back(temp);
			// priorities.erase(it);
			*/
			rotate(priorities.begin(), priorities.begin() + 1 ,priorities.end());
			if (location == 0)
				location = priorities.size() - 1;
			else
				location--;
		}
		else
		{
			priorities.erase(it);
			answer++;
			if (location == 0)
				return answer;
			else
				location--;
		}
	}
	return answer;
}

int main()
{
	vector<int> a = {2, 1, 3, 2};
	int b = 2;

	vector<int> c = {1, 1, 9, 1, 1, 1};
	int d = 0;

	cout << solution(c, d) << endl;
	
	return(0);
}


/*
[2, 1, 3, 2]	2	1
[1, 1, 9, 1, 1, 1]	0	5
*/
