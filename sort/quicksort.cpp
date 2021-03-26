#include <iostream>
#include <list>
using namespace std;

/* 프로토타입 설정하기 */
//상황을 이해하고, 크기가 변하는지를 확인해서, 리턴값이 있어야하는지 확인하기
//크기가 변하지 않기 때문에 리턴은 없어도되며, 정렬 알고리즘의 파라미터는 다음과 같이 고정하는 것이 일관성이 있다고 생각함.
//but, 크기가 변하지않지만 index는 변하기 때문에 관련된 정보를 넘겨줘야함. return값이 있었더라면 int size를 넘겨주는 것이 맞지만,
//지금은 그렇게해서는 array의 어느 부분을 고쳐야하는지 알 수 가 없음.
void quicksort(int *array, int l, int r);
void print_nums(int nums[], size_t count);

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// pivoting 함수에서 기대하는 것은 swaping이 모두 일어나고, 리턴 값만 알려주는 상황
int pivoting(int *array, int l, int r) // 0, 2
{
	//r,l로 들어올 수 있는 경우는 l <= r
	if (r == l)
		return (r);
	if (l + 1 == r)
	{
		if (array[r] < array[l])
			swap(array[r], array[l]);
		return (l);
	}
	int init = l;
	int pivot_index = l;
	int pivot_value = array[l];
	while (l <= r)
	{
		if (array[l] > pivot_value)
		{
			while (l <= r)
			{
				if (array[r] < pivot_value)
				{
					swap(array[l], array[r]);
					cout << " while 2 break " << endl;
					break;
				}
				// swap(array[init], array[r]);
				r--;
			}
			
		}
		l++; //어짜피 l은 43번째 줄에 영향을 못주니깐.
	}
	cout << " pivot end " << endl;
	swap(array[init], array[r]);
	print_nums(array, 3);
	return (r);
}

void quicksort(int *array, int l, int r)
{
	if (r <= l) 
		return ;
	int pivot_index = (array, l, r);
	quicksort(array, l, pivot_index - 1);
	quicksort(array, pivot_index + 1, r);
}

void print_nums(int nums[], size_t count)
{
	cout << "------------ print nums ------------" << endl;
	for (size_t i = 0; i < count; i++)
	{
		cout << nums[i] << " " << endl;
		if (i != 0 && i % 10 == 9)
			cout << endl;
	}
	cout << endl;
}


int main()
{
	// int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	// int count = 24;
	int lists[3] = {3, 2, 0};
	int count = 3;
	// int lists[2] = {2, 1};
	// int count = 2;
	// int lists[4] = {3, 2, 1, 0};
	// int count = 4;
	// int lists[5] = {3, 2, 6, 4, 0};
	// int count = 5;
	print_nums(lists, count);
	quicksort(lists, 0, count - 1);
	print_nums(lists, count);
	return (1);
}
