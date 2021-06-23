#include <iostream>
using namespace std;

// 첫째 줄에 숫자 N이 주어진다. N은 10,000보다 작거나 같은 자연수이다.
// 2 => 1666


bool is_bad_number(int num)
{
	std::string temp;
	
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