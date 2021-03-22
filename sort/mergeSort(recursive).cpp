#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct s_data
{
	int *nums_;
	size_t size_;
	int start;
	int end_;
	int middle_;
};

void data_setting(s_data *data, int *nums, int count);
s_data merge_sort(s_data data, size_t count);

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

// 지금 현재는 n = 1, n = 2, n = 3일 때를 가정해보면서 함수를 작성하고 있음.
void divid(s_data &data, s_data &left, s_data &right)
{
	int *left_int;
	int *right_int;
	if (data.size_ == 1)
		return;
	else
	{
		left_int = new int[data.middle_ + 1];
		right_int = new int[data.end_ - data.middle_];
		for (size_t i = 0; i < data.middle_ + 1; i++)
		{
			left_int[i] = data.nums_[i];
			// cout << "left_int[i] : " << left_int[i] << endl;
		}
		for (size_t i = 0; i < data.end_ - data.middle_; i++)
		{
			right_int[i] = data.nums_[i + data.middle_ + 1];
			// cout << "right_int[i] : " << right_int[i] << endl;
		}
		
		data_setting(&left, left_int, data.middle_ + 1);
		data_setting(&right, right_int, data.end_ - data.middle_);
		// cout << "-----" << endl;
		// print_nums(left.nums_, left.size_);
		// print_nums(right.nums_, right.size_);

		// 재귀 함수 앞에 있기 때문에, 위에 있는 행위들은 모두 먼저 실행됨.
		merge_sort(left, left.size_);
		merge_sort(right, right.size_);
	}
}

void ADD(s_data &data, s_data &left, s_data &right)
{
	if (data.size_ == 1)
		return ;
	int a = 0;
	int b = 0;
	// cout << data.size_ << endl;
	for (size_t i = 0; i < data.size_; i++)
	{
		if (a == left.size_)
			data.nums_[i] = right.nums_[b++];
		else if (b == right.size_)
			data.nums_[i] = left.nums_[a++];
		else if (left.nums_[a] >= right.nums_[b])
			data.nums_[i] = right.nums_[b++];
		else if (left.nums_[a] < right.nums_[b])
			data.nums_[i] = left.nums_[a++];
	}
}

s_data merge_sort(s_data data, size_t count) // 하노이 탑처럼 함수의 기능을 하나로 고정시키면, merge_sort 함수는 정렬 기능을 가진 것으로 이해.
{
	if (data.size_ == 1)
		return (data);

	s_data left;
	s_data right;
	/* 단위 사이클 */

	divid(data, left, right);
	// ADD함수는 재귀 함수 뒤에 있기 때문에, 아래에 있는 행위들은 모두 나중에 실행됨.
	ADD(data, left, right);
	return (data);
}

void data_setting(s_data *data, int *nums, int count)
{
	data->nums_ = nums;
	data->size_ = count;
	data->start = 0;
	data->end_ = data->size_ - 1;
	data->middle_ = (data->start + data->end_) / 2;
}

int main()
{
	int nums[24] = {0,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	int count = 24;
	// int nums[3] = {3, 2, 0};
	// int count = 3;
	// int nums[5] = {3, 2, 6, 4,0};
	// int count = 5;

	s_data data;
	data_setting(&data, nums, count);
	print_nums(data.nums_, count);
	data = merge_sort(data, data.size_);
	print_nums(data.nums_, count);

	return (1);
}
