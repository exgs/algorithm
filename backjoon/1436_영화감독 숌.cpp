#include <iostream>
#include <string>
using namespace std;

// 첫째 줄에 숫자 N이 주어진다. N은 10,000보다 작거나 같은 자연수이다.
// 2 => 1666


bool is_bad_number(int num)
{
	std::string num_str = std::to_string(num);
	string stack = "";
	for (size_t i = 0; i < num_str.length(); i++)
	{
		if (num_str[i] == '6')
		{
			stack += '6';
		}

		if (stack.length() != 0)
		{
			if (stack.length() >= 3)
			{
				return (true);
			}
			else if (num_str[i] != '6')
			{
				stack = "";
			}
		}
	}
	return (false);
}

int main()
{
	int N; scanf("%d", &N);
	int count = 0;
	int num = 1;

	while (num)
	{
		if (is_bad_number(num) == true)
		{
			count++;
		}

		if (count == N)
		{
			cout << num;
			return (0);
		}
		num++;
	}
	return (0);
}

/*
666
1666
2666
3666
4666
5666
6661
6662
6663
...
6666
6669
7666
....

9666
10666
15666

16661 16662 16663 16664 16665 ... 
17666

*/