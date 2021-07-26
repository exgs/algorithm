#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int loopBinarySearch(vector<int> &data, int target)
{
	int min = 0;
	int max = data.size() - 1;
	int mid = (max + min) / 2;
	while (min <= max)
	{
		mid = (max + min) / 2;
		// cout << min << ":" << max << endl;
		if (data[mid] < target)
		{
			min = mid + 1;
		}
		else if (data[mid] > target)
		{
			max = mid - 1;
		}
		else
		{
			// 중복값이 없다는 가정하에
			// return (mid);

			// 중복값 중에 가장 작은 값
			while (data[mid - 1] == target)
			{
				mid--;
			}
			return (mid);
		}
	}
	return (-1); // Can't find
}

// recursive version : A[0 ~ N-1]
int RecursiveBinarySearch(vector<int> &A, int low, int high, int target){
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (A[mid] == target)
	{// 중복값이 없다는 가정하에
		return mid;
	}
	if (A[mid] > target)
		return RecursiveBinarySearch(A, low, mid-1, target);
	else
		return RecursiveBinarySearch(A, mid+1, high, target);
}



int main()
{
	vector<int> data = {2,6,11,13,18,20,22,22,22,22,27,29,30,34,38,41,42,45,47};
	int value = loopBinarySearch(data, 22);
	cout << value << endl;
	
	value = RecursiveBinarySearch(data, 0, data.size() - 1, 22);
	cout << value << endl;
	return(0);
}