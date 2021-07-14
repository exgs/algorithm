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
#include <stack>

using namespace std;

vector<int> solution_other(vector<int> prices)
{
	vector<int> answer(prices.size());
	stack<int> s;
	int size = prices.size();
	for (int i = 0; i < size; i++)
	{
		while (!s.empty() && prices[s.top()] > prices[i])
		{
			answer[s.top()] = i-s.top();
			cout << "s.top: " << s.top() << " | " << "i-s.top(): " <<  i-s.top() << endl;
			s.pop();
		}
		s.push(i);
		cout << "i: " << i << endl;
	}
	while (!s.empty())
	{
		answer[s.top()] = size - s.top() - 1;
		s.pop();
	}
	return answer;
}

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (size_t i = 0; i <= prices.size() - 2; i++)
	{
		int count = 1;
		size_t j = i + 1;
		while (j <= prices.size() - 1)
		{
			if (prices[i] <= prices[j])
				count++;
			else
				break;
			j++;
		}
		if (j == prices.size())
		{
			answer.push_back(j - i - 1);
		}
		else
		{
			answer.push_back(j - i);
		}

	}
	answer.push_back(0);
	return answer;
}

int main()
{
	vector<int> prices	= {1, 2, 3, 2, 3};
	vector<int> prices1	= {5, 8, 6, 2, 4, 1};

	vector<int>temp = solution_other(prices1);
	for (size_t i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << endl;
	}
	return(0);
}

/*
prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
prices의 길이는 2 이상 100,000 이하입니다.

초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때,
가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

prices			    return
[1, 2, 3, 2, 3]     [4, 3, 1, 1, 0]
[5, 8, 6, 2, 4, 1]  [3, 1, 1, 2, 1, 0]
*/
