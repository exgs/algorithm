#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

void solution(list<int> temp, int count)
{
	if (count <= 0)
	{
		printf("\n");
		return;
	}
	else
		count--;
	for (size_t i = 0; i < temp.size(); i++)
	{
		temp.
		temp.pop_front();
		printf("%d ", temp.front());
		solution(value, count);
	}
}

int main()
{
	int a; scanf("%d", &a);
	int b; scanf("%d", &b);
	list<int> temp;
	for (size_t i = 0; i < a; i++)
	{
		temp.push_back(i + 1);
	}
	
	solution(temp, b);
	return(0);
}

/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
	1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.

3 1
출력
1
2
3
---
4 2
출력 
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
*/