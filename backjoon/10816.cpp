#include <iostream>
#include <list>
#include <map>

// 1. Timeout
// 이분탐색 스터디
using namespace std;

void print_list(std::list<int> temp);
void print_pair(std::list <std::pair<int, int> > temp);

int main()
{
	size_t src;
	std::list<int> list2;
	size_t dst;
	std::list< std::pair<int, int> > pairlist;

	cin >> src;
	for (size_t i = 0; i < src; i++)
	{
		int temp;
		cin >> temp;
		list2.push_back(temp);
	}
	
	cin >> dst;
	for (size_t i = 0; i < dst; i++)
	{
		int temp;
		cin >> temp;
		std::pair<int, int> temp2(temp, 0);
		pairlist.push_back(temp2);
	}

	// 빼는식으로
	std::list < pair<int, int> >::iterator temp_it;
	temp_it = pairlist.begin();
	for (size_t j = 0; j < dst; j++)
	{
		if (list2.size() == 0)
			break;
		pair<int, int> &temp_pair = *temp_it;
		std::list <int>::iterator list2_it;

		// STUB error "3 0 0 0 0 0 0 0"
		// for (list2_it = list2.begin(); list2_it != list2.end(); list2_it++)
		// {
		// 	int temp = *list2_it;
		// 	if (temp == temp_pair.first)
		// 	{
		// 		temp_pair.second++;
		// 	}
		// 	list2.erase(list2_it);
		// }
		list2_it = list2.begin();
		while(list2_it != list2.end())
		{
			int temp = *list2_it;
			if (temp == temp_pair.first)
			{
				temp_pair.second++;
				list2.erase(list2_it++);
				continue;
			}
			list2_it++;
		}

		temp_it++;
	}
	
	// STUB 디버깅
	// cout << "src: " << src << endl;
	// print_list(list2);
	// cout << "dst: " << dst << endl;
	print_pair(pairlist);
	return (1);
}


void print_list(std::list<int> temp)
{
	std::list<int>::iterator it_temp;
	for (it_temp = temp.begin(); it_temp != temp.end(); it_temp++)
	{
		cout << *it_temp;
		cout << " ";
	}
	cout << endl;
}

void print_pair(std::list <std::pair<int, int> > temp)
{
	std::list <std::pair<int, int> >::iterator it_temp;
	for (it_temp = temp.begin(); it_temp != temp.end(); it_temp++)
	{

		// cout << it_temp->first;
		// cout << ":";
		cout << it_temp->second;
		cout << " ";
	}
	cout << endl;
}