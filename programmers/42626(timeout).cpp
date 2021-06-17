#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    list<int> temp;
	temp.resize(scoville.size());
	std::copy(scoville.begin(), scoville.end(), temp.begin());
	temp.sort();
	list<int>::iterator it = temp.begin();
	while (*it < K)
	{
		if (temp.size() == 1)
			return (-1);
		int value;
		value = *it + *(++it) * 2;
		temp.pop_front();
		temp.pop_front();
		temp.push_front(value);
		temp.sort();
		it = temp.begin();
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

	int value = solution(temp, 7);


	return (1);
}

