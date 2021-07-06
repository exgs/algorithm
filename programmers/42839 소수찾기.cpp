#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int gCount = 0;
bool isPrimenumber(int num)
{
	int count = 0;
	for (size_t i = 0; i < num; i++)
	{
		if (num % i == 0 && i != 0)
		{
			count++;
		}
	}
	if (count == 2)
		return (true);
	else
		return (false);
}


void Permutation(vector<char> datas, int size)
{
	
}

int solution(string numbers) {
	vector<char> datas;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		datas.push_back((char)numbers[i] - 48);
	}

	// STUB debugging
	vector<char>::iterator it = datas.begin();
	while (it != datas.end())
	{
		cout << (int)*it << endl;
		it++;
	}

	int answer = 0;
	return answer;
}

int main()
{
	string temp("17");
	string temp1("011");
	// long temp3 = stol(temp1);
	// cout << temp3 << endl;
	cout << "------" << endl;
	cout << solution(temp) << endl;
	return(0);
}