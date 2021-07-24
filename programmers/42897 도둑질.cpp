#include <iostream>
#include <vector>

using namespace std;

//  1,000,000개 이하입니다.
int dp1[1000000];
int dp2[1000001];

// 첫번째 집 턴다.
int case1(vector<int> money)
{
	dp1[0] = money[0];
	dp1[1] = money[0];

	// dp1[1] = money[1];
	for (size_t i = 2; i < money.size() - 1; i++)
	{
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
	}
	return (dp1[money.size() - 2]);
}
// 첫번째 집 안턴다.
int case2(vector<int> money)
{
	dp2[1] = money[1];
	dp2[2] = max(money[2], money[1]);
	for (size_t i = 3; i < money.size(); i++)
	{
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
	}
	return (dp2[money.size() - 1]);
}

int solution(vector<int> money)
{
	int answer = 0;
	answer = max(case1(money), case2(money));
	return answer;
}

int main()
{
	vector<int> vector1 = {1, 2, 3, 1}; // 4
	vector<int> vector2 = {1000, 12, 2, 2, 1000}; //1012
	cout << solution(vector2) << endl;
	return (0);
}

/*
[1, 2, 3, 1]	4
이 마을에 있는 집은 3개 이상 1,000,000개 이하입니다.
money 배열의 각 원소는 0 이상 1,000 이하인 정수입니다.
*/