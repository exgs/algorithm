#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end()); // string은 사전식 정렬
	for (size_t i = 0; i < phone_book.size() - 1; i++)
	{
		int j = i + 1;
		int z = 0;
		while (z < phone_book[i].size() && z < phone_book[j].size())
		{
			if (phone_book[i][z] != phone_book[j][z])
				break;
			z++;
		}
		if (z == phone_book[i].size() || z == phone_book[j].size())
			return (answer = false);
		/* 선형 탐색을 비할려면 정렬을 하는 수 밖에 */
		// for (size_t j = i; j < phone_book.size(); j++)
		// {
		// 	if (i == j)
		// 		continue ;
		// 	int z = 0;
		// 	while (z < phone_book[i].size() && z < phone_book[j].size())
		// 	{
		// 		if (phone_book[i][z] != phone_book[j][z])
		// 			break;
		// 		z++;
		// 	}
		// 	if (z == phone_book[i].size() || z == phone_book[j].size())
		// 		return (answer = false);
		// }
	}
	return answer;
}

int main()
{
	vector<string> vector1 = {"119", "97674223", "1195524421"};
	vector<string> vector2 = {"123","456","789"};
	vector<string> vector3 = {"567","88", "12","123","1235"};
	cout << "-------" << endl;
	cout << solution(vector3) << endl;
	return(0);
}

/*
["119", "97674223", "1195524421"]	false
["123","456","789"]	true
["12","123","1235","567","88"]	false
*/