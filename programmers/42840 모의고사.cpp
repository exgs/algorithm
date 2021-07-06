#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>

using namespace std;


vector<int> solution(vector<int> answers)
{
	int first = 0;
	int second = 0;
	int third = 0;
	int second_array[4] = {1, 3, 4, 5};
	int second_array_idx = 0;

	int third_array[5] = {3, 1, 2, 4, 5};
	int third_array_idx = 0;
	
	for (size_t i = 0; i < answers.size(); i++)
	{
		// A
		if (((i % 5) + 1) == answers[i])
			first++;
		
		// B
		// 1 3 4 6 
		if (i % 2 == 0)
		{
			if (answers[i] == 2)
				second++;
		}
		else
		{
			if (answers[i] == second_array[second_array_idx])
			{
				second++;
			}
			second_array_idx++;
			if (second_array_idx == 4)
				second_array_idx = 0;
		}

		// C
		if (i % 2 == 0)
		{
			if (answers[i] == third_array[third_array_idx])
			{
				third++;
			}
		}
		else
		{
			if (answers[i] == third_array[third_array_idx])
			{
				third++;
			}
			third_array_idx++;
			if (third_array_idx == 5)
				third_array_idx = 0;
		}
	}

	// answer
	vector<int> answer;
	if (first == second && second == third)
	{
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(3);
	}
	else if (first == second)
	{
		if (first > third)
		{
			answer.push_back(1);
			answer.push_back(2);
		}
		else
		{
			answer.push_back(3);
		}
	}
	else if (first == third)
	{
		if (first > second)
		{
			answer.push_back(1);
			answer.push_back(3);
		}
		else
		{
			answer.push_back(2);
		}
	}
	else if (second == third)
	{
		if (second > first)
		{
			answer.push_back(2);
			answer.push_back(3);
		}
		else
		{
			answer.push_back(1);
		}
	}
	else
	{
		if (first > second)
		{
			if (first > third)
				answer.push_back(1);
			else
				answer.push_back(3);
		}
		else
		{
			if (second > third)
				answer.push_back(2);
			else
				answer.push_back(3);
		}
	}
	return answer;
}

int main()
{
	vector<int> temp = {1,2,3,4,5}; 
	vector<int> temp1 = {1,3,2,4,2}; // 2번

	vector<int> a = solution(temp1);
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
	return(0);
}

/*
1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
*/

/* Beautiful Code
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%one.size()]) they[0]++;
        if(answers[i] == two[i%two.size()]) they[1]++;
        if(answers[i] == thr[i%thr.size()]) they[2]++;
    }
    int they_max = *max_element(they.begin(),they.end());
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1);
    }
    return answer;
}
*/