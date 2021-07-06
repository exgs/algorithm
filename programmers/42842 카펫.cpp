#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int sum = brown + yellow;

	int j = 3; // 높이의 최소값부터 시작해서 가로의 최대값 부터 calculated_yellow를 구한다.
	while (j < sum)
	{
		if (sum % j == 0)
		{
			int i = sum / j;
			int calculated_yellow = (j - 2) * (i - 2);
			if (calculated_yellow == yellow)
			{
				answer.push_back(i);
				answer.push_back(j);
				return (answer);
			}
		}
		j++;
	}
	return answer;
}
/*
10	2	[4, 3]
8	1	[3, 3]
24	24	[8, 6]
*/

/*
갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
*/

int main()
{
	int a = 8;
	int b = 1;
	std::vector<int> temp = solution(a, b);

	for (size_t i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << endl;
	}
	return (0);
}