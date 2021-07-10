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

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	size_t idx = 0;
	while (idx != progresses.size())
	{
		// STEP1 시간이 흐르면,
		for (size_t i = idx; i < progresses.size(); i++)
		{
			if (progresses[i] < 100)
				progresses[i] += speeds[i];
		}
		
		// STEP2 빠져나와야지
		int pop_count = 0;
		while (progresses[idx] >= 100 && idx != progresses.size())
		{
			pop_count++;
			idx++;
		}
		if (pop_count != 0)
			answer.push_back(pop_count);
	}
	return answer;
}

int main()
{
	vector<int> a = {93, 30, 55};
	vector<int> b = {1, 30, 5};

	// vector<int> c = {95, 90, 99, 99, 80, 99};
	// vector<int> d = {1, 1, 1, 1, 1, 1};

	vector<int>temp = solution(a, b);
	for (size_t i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << endl;
	}
	
	return(0);
}

/*
progresses	speeds	return
[93, 30, 55]	[1, 30, 5]	[2, 1]
[95, 90, 99, 99, 80, 99]	[1, 1, 1, 1, 1, 1]	[1, 3, 2]
*/

/*
작업의 개수(progresses, speeds배열의 길이)는 100개 이하입니다.
작업 진도는 100 미만의 자연수입니다.
작업 속도는 100 이하의 자연수입니다.
배포는 하루에 한 번만 할 수 있으며, 하루의 끝에 이루어진다고 가정합니다. 예를 들어 진도율이 95%인 작업의 개발 속도가 하루에 4%라면 배포는 2일 뒤에 이루어집니다.
*/