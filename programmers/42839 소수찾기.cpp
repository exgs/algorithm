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


// void Permutation(vector<char> datas, int size)
// {
	
// }

int solution(string numbers) {
	int count = 0;
	// vector<char> datas;
	// for (size_t i = 0; i < numbers.size(); i++)
	// {
	// 	datas.push_back((char)numbers[i] - 48);
	// }

	for (size_t i = 0; i < count; i++)
	{
		while (next_permutation(numbers.begin(), numbers.end()) == true)
		{
			string temp = "";
			for (size_t i = 0; i < numbers.size(); i++)
			{
				temp += numbers[i];
			}
			cout << temp << endl;
			int temp2 = atoi(temp.c_str());
			// int temp2 = stol(temp);
			if (isPrimenumber(temp2) == true)
			{
				count++;
			}
		}
	}
	

	// STUB debugging
	// vector<char>::iterator it = datas.begin();
	// while (it != datas.end())
	// {
	// 	cout << (int)*it << endl;
	// 	it++;
	// }
	return count;
}

int main()
{
	string temp("17");
	string temp1("011");
	// long temp3 = stol(temp1);
	// cout << temp3 << endl;
	cout << "------" << endl;
	cout << solution(temp1) << endl;
	return(0);
}