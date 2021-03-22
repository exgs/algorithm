#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_nums(int nums[], size_t count)
{
	cout << "------------ print nums ------------" << endl;
	for (size_t i = 0; i < count; i++)
	{
		cout << nums[i] << " ";
		if (i != 0 && i % 10 == 9)
			cout << endl;
	}
	cout << endl;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int nums[], size_t count)
{
	int max; // 를 저장하게하면, index에 대한 정보도 저장해야함. 바꿔주기 위해서
	int temp; // 계속 값을 swap 해주는 것이 더 좋은 거 같다.
	for (size_t i = 0; i < count - 1; i++)
	{
		max = nums[0];
		for (size_t j = 0; j < count - 1 - i; j++) // 맨 뒤에가 채워지니깐 하나씩 줄어듬
		{
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
		}
	}
	
}

int main()
{
	int nums[24] = {0,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	int count = 24;

	print_nums(nums, count);
	// int sort_nums[24];
	// memset(sort_nums, 0 ,24 * sizeof(int));
	// print_nums(sort_nums, count);
	bubble_sort(nums, count);
	print_nums(nums, count);

	
	return (1);
}
