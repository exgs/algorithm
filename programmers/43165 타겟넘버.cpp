// 2 <= number.size() = n <= 20
// 1 < = elements[n] <= 50
// 1 <= target <= 1000

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target)
{
	int answer = 0;
	if (numbers.size() == 0 && target == 0)
	{
		return (1);
	}
	else if (numbers.size() == 0 && target != 0)
	{
		return (0);
	}
	int temp = numbers.back();
	numbers.pop_back();
	answer += solution(numbers, target - temp);
	answer += solution(numbers, target + temp);
	return answer;
}

// STUB 디버깅
// #include <iostream>
// int main()
// {
// 	int array[] = {1, 1, 1, 1, 1};
// 	vector<int> numbers;
// 	numbers.push_back(1);
// 	numbers.push_back(1);
// 	numbers.push_back(1);
// 	numbers.push_back(1);
// 	numbers.push_back(1);
// 	cout << solution(numbers, 3) << endl;
// 	return (0);
// }