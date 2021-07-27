#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string solution(string number, int k)
{
	int answer_size = number.size() - k;
	string answer;
	int start = 0;
	while (k > 0 && answer.size() < answer_size)
	{
		string subnumber(number.begin() + start, number.begin() + start + k + 1);
		int idx = distance(subnumber.begin(), max_element(subnumber.begin(), subnumber.end())); // k+1 길이를 가진 문자열
		answer.push_back(subnumber[idx]);
		k -= idx;
		start += (idx + 1);
	}
	if (k == 0)
	{
		for (size_t i = start; i < number.size(); i++)
		{
			answer.push_back(number[i]);
		}
		return answer;
	}
	else // answer.size() == answer_size
		return answer;
}

int main()
{
	string temp = "999"; int n = 2;
	cout << solution(temp, n) << endl;
	return (0);
}

/*
	k	return
"1924"	2	"94"
"1231234"	3	"3234"
"4177252841"	4	"775841"
"88911"	2	"911"
"999" 2     "9"
"111119" 3     "119"
*/