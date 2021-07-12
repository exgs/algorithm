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

int solution(string numbers) {
	int count = 0;
	int len = numbers.size();
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
			do
			{
				long value = stol(temp);
				cout << "value: " << value << endl;
				if (isPrimenumber(value) == true)
					count++;
			} while (next_permutation(temp.begin(), temp.end()));
		} while (next_permutation(v.begin(), v.end()));
	}
	return count;
}

int main()
{
	string temp("17"); // 3
	string temp1("011"); // 2
	// long temp3 = stol(temp1);
	// cout << temp3 << endl;
	cout << "------" << endl;
	cout << solution(temp1) << endl;
	return(0);
}