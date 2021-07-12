#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;


#include <string>
#include <vector>

using namespace std;


vector<int>::iterator getIterator(vector<int> temp, int idx)
{
	vector<int>::iterator it = temp.begin();;
	for (size_t i = 0; i < idx; i++)
	{
		it++;
	}
	return (it);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;
	for (size_t i = 0; i < commands.size(); i++)
	{
		vector<int> elements = commands[i];
		vector<int> temp;
		// 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.
		// warning: start <= range < end
		int start = elements[0] - 1 ; int end = elements[1] - 1; int idx = elements[2] - 1;
		temp.resize(end - start + 1);
		// STUB iterator 구하는 방법
		// vector<int>::iterator it_1 = getIterator(array, start);
		// vector<int>::iterator it_2 = getIterator(array, end); it_2++;
		// std::copy(it_1, it_2, temp.begin());
		std::copy(array.begin() + start, array.begin() + end + 1, temp.begin());
		std::sort(temp.begin(), temp.end());
		answer.push_back(temp[idx]);
	}
	return answer;
}

int main()
{
	vector<int> vector1 = {1, 5, 2, 6, 3, 7, 4};
	vector<vector<int> > commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
	vector<int> vector2;
	vector2 = solution(vector1, commands);

	for (size_t i = 0; i < vector2.size(); i++)
	{
		cout << vector2[i] << endl;
	}
	return (0);
}


/*
[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]
*/