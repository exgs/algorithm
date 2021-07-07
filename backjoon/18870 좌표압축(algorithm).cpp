#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool isArray(vector<int> &array, int num)
{
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] == num)
			return true;
	}
	return false;
}

int main()
{
	// set<int> datas;
	int count; scanf("%d", &count);
	// int *array = new int [count];
	// int *datas = new int [count];
	vector<int> datas;


	int array[1000000];
	for (size_t i = 0; i < count; i++)
	{
		int temp;
		scanf("%d", &temp);
		array[i] = temp;
		// if (isArray(datas, temp) == false)
		// 	datas.push_back(temp);
	}

	// 서로다른 STL값 넣기
	datas.resize(count); // 꼭 써줘야함!!
	std::copy(&array[0], &array[count], datas.begin());

	// 중복되는 요소 지우기
	sort(datas.begin(), datas.end());
	vector<int>::iterator it2 = unique(datas.begin(), datas.end());
	// datas.
	int idx = std::distance(datas.begin(), it2);
	// cout << "idx: " << idx << endl;
	datas.erase(it2, datas.end());
	// cout << "size: " << datas.size() << endl;
	for (size_t i = 0; i < count; i++)
	{
		int sum = 0;
		vector<int>::iterator it = datas.begin();
		while (it != datas.end())
		{
			if (array[i] > *it)
			{
				sum++;
			}
			it++;
		}
		array[i] = sum;
	}
	
	// STUB Debugging 출력
	// for (size_t i = 0; i < datas.size(); i++)
	// {
	// 	printf("%d ", datas[i]);
	// }

	for (size_t i = 0; i < count; i++)
	{
		printf("%d ", array[i]);
	}

	// delete []array;
	return (0);
}