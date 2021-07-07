#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int count; scanf("%d", &count);
	// int *datas = new int [count];
	// vector<int> datas;

	vector<int> vectorOrigin;
	vector<int> vectorCopy;
	for (size_t i = 0; i < count; i++)
	{
		int temp;
		scanf("%d", &temp);
		vectorOrigin.push_back(temp);
		vectorCopy.push_back(temp);
		// vector[i] = temp;
		// vector_copy[i] = temp;
	}

	sort(vectorOrigin.begin(), vectorOrigin.end());
	vector<int>::iterator it = unique(vectorOrigin.begin(), vectorOrigin.end());
	vectorOrigin.erase(it, vectorOrigin.end());

	// cout << std::distance(vectorOrigin.begin(), it) << endl;
	// for (int i = 0; i < vectorOrigin.size(); i++)
	// {
	// 	printf("vector[%d]: %d\n", i, vectorOrigin[i]);
	// }
	// cout << "----" << endl;
	
	// 정렬
	for (size_t i = 0; i < count; i++)
	{
		int value = vectorCopy[i];
		// cout << "value :" << value << endl;
		printf("%ld ", lower_bound(vectorOrigin.begin(), vectorOrigin.end(), value) - vectorOrigin.begin());
	}
	return (0);
}