#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool comp(std::tuple< int, int, string> &s1, std::tuple< int, int, string> &s2)
{
	if (std::get<1>(s1) != std::get<1>(s2))
	{
		return std::get<1>(s1) < std::get<1>(s2);
	}
	else
	{
		return (std::get<0>(s1) < std::get<0>(s2));
	}
}

char buffer[100];
int main()
{
	int count;
	scanf("%d", &count);
	// 나이, 순서, 이름
	vector< std::tuple< int, int, string> >temp;
	for (size_t i = 0; i < count; i++)
	{
		int number = i; int age; scanf("%d", &age); scanf("%s", buffer); string name(buffer);
		tuple<int, int, string> temp2 = std::make_tuple(number, age, name);
		temp.push_back(temp2);
	}

	// STUB debugging
	sort(temp.begin(), temp.end(), comp);
	for (size_t i = 0; i < temp.size(); i++)
	{
		printf("%d %s\n", std::get<1>(temp[i]), std::get<2>(temp[i]).c_str());
	}
	return (0);
}
