#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool isPrimenumber(int num)
{
	int count = 0;
	for (int i = 1; i <= num; i++)
	{
		if ((num % i == 0) && i != 0)
		{
			count++;
		}
	}
	if (count == 2)
		return (true);
	else
		return (false);
}

int sol = 0;

int solution(string numbers) {
	int count = 0;
	int len = numbers.size();
	set<long> memory;
	for (int i = 1; i <= len; i++) {
		vector<bool> v(len - i, false);
		v.insert(v.end(), i, true);
		do {
			string temp = "";
			for (int k = 0; k < len; k++)
			{
				if (v[k])
					temp += numbers[k];
			}
			sort(temp.begin(), temp.end());
			do
			{
				sol++; // 전체 갯수와 동일한지 확인하는 용도
				// if (temp[0] == '0')
				// 	continue ;
				long value = stol(temp);
				if (isPrimenumber(value) == true)
				{
					if (memory.find(value) == memory.end())
					{
						memory.insert(value);
					}
				}
			} while (next_permutation(temp.begin(), temp.end()));
		} while (next_permutation(v.begin(), v.end()));
	}
	return memory.size();
}

int main()
{
	string temp("17"); // 3
	string temp1("011"); // 2
	string temp2("12"); // 1
	string temp3("123"); // 5
	string temp4("12345"); // 5
	string temp5("0052"); // 2
	string temp6("9999"); // 0
	string temp7("22222"); // 1
	string temp8("1001"); // 2 ??

	string t1("2"); // 1
	string t2("7843"); // 12
	string t3("1276543"); // 1336

	cout << "------" << endl;
	cout << solution(t2) << endl;
	cout << "sol: " << sol << endl;
	return(0);
}