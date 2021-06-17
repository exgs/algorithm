#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j)
{
	if (i > j)
		return (true);
	return (false);
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
	std::sort(scoville.begin(), scoville.end(), compare);
	vector<int>::reverse_iterator it = scoville.rbegin();
	while (*it < K)
	{
		if (scoville.size() == 1)
			return (-1);
		int value;
		value = *it + *(++it) * 2;
		scoville.pop_back();
		scoville.pop_back();
		it = scoville.rbegin();
		while (it != scoville.rend())
		{
			if (*it > value)
			{
				scoville.insert(it.base(), value);
				break;
			}
			it++;
		}
		if (it == scoville.rend())
		{
			scoville.insert(it.base(), value);
		}
		
		it = scoville.rbegin();
		answer++;
	}
    return answer;
}

// [1, 2, 3, 9, 10, 12] 7 = 2
#include <iostream>
using namespace std;

int main()
{
	std::vector<int> temp;
	temp.push_back(12);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(10);
	temp.push_back(9);
	std::sort(temp.begin(), temp.end(), compare);
	int ee;

	int value = solution(temp, 7);

	cout << value << endl;

	return (1);
}

