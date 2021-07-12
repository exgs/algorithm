#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool mydecision(int a, int b)
{
	string str_a = to_string(a);
	string str_b = to_string(b);
	int i_a = 0; int i_b = 0; 
	while (i_a != str_a.size() || i_b != str_b.size())
	{
		if (str_a.size() == i_a)
		{
			i_a = 0;
		}

		if (str_b.size() == i_b)
		{
			i_b = 0;
		}

		if (str_a[i_a] > str_b[i_b])
			return (true);
		else if (str_a[i_a] < str_b[i_b])
			return (false);
		i_a++;
		i_b++;
	}
	return (false);
}

string solution(vector<int> numbers)
{
	string answer = "";
	sort(numbers.begin(), numbers.end(), mydecision);
	for (size_t i = 0; i < numbers.size(); i++)
	{
		answer += to_string(numbers[i]);
	}
	if (answer[0] == '0') // {0, 0}에 대한 하드코딩
		answer = "0";
	return answer;
}

int main()
{
	vector<int> vector1 = {6, 10, 2};
	vector<int> vector2 = {3, 30, 34, 5, 9};
	vector<int> vector3 = {3, 30, 32, 5, 9};
	vector<int> vector4 = {1, 2, 4, 5, 6, 3};
	vector<int> vector5 = {1, 1, 11, 2, 12, 112};
	vector<int> vector6 = {0, 0};
	vector<int> vector7 = {345, 3456};
	vector<int> vector8 = {345, 3451};

	std::string temp = solution(vector8);
	cout << temp << endl;
	return(0);
}

/*
numbers의 길이는 1 이상 100,000 이하입니다.
numbers의 원소는 0 이상 1,000 이하입니다.
정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
*/

/*
[6, 10, 2]	"6210"
[3, 30, 34, 5, 9]	"95 34 3 30"
[3, 30, 32, 5, 9]	"95 3 32 30"
*/

/*
(길이가 같아짐)두 값을 더하고 나서 비교를 함
bool compare(const string &a, const string &b)
{
    if (b + a < a + b)
        return true;
    return false;
}
*/