#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main(void)
{
	int src;
	std::list<int> list_src;
	int dst;
	std::list<int> list_dst;

	cin >> src;
	for (int i = 0; i < src; i++)
	{
		int temp;
		cin >> temp;
		list_src.push_back(temp);
	}
	cin >> dst;
	for (int i = 0; i < dst; i++)
	{
		int temp;
		cin >> temp;
		list_dst.push_back(temp);
	}

	// NOTE map에 새로 담기
	unordered_map<int, int> map;
	std::list<int> temp = list_dst;
	std::list<int>::iterator temp_it = temp.begin();
	for (int i = 0; i < dst; i++)
	{
		map.insert(std::pair<int, int>(*temp_it, 0));
		temp_it++;
	}

	for (int i = 0; i < src; i++)
	{
		std::unordered_map<int, int>::iterator it;
		if ((it = map.find(list_src.front())) != map.end())
		{
			it->second++;
		}
		list_src.pop_front();
	}
	
	for (int i = 0; i < dst; i++)
	{
		std::unordered_map<int, int>::iterator it;
		if ((it = map.find(list_dst.front())) != map.end())
		{
			cout << it->second;
			if (i != dst - 1)
				cout << " ";
		}
		list_dst.pop_front();
	}
	
	// STUB 디버깅
	// cout << "src: " << src << endl;
	// print_list(list_src);
	// cout << "dst: " << dst << endl;
	// print_pair(list_dst);
	return (0);
}