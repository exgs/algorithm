// 재귀써서 풀어야하는데 재귀를 안쓰니깐 5중 for문 돌림;

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void print_vector(vector<vector<char> > map);
void fill_map(vector<vector<char> > &map, int n);
void erase_map(vector<vector<char> > &map, int n, int m);

int main()
{
	int n; scanf("%d", &n);
	int m = 0;
	int temp = n;
	while (temp != 1)
	{
		m++;
		temp /= 3;
	}

	vector<vector<char> > map;
	fill_map(map, n);
	erase_map(map, n, m);

	// STUB debugging
	print_vector(map);
	return (0);
}

void erase_map(vector<vector<char> > &map, int n, int m)
{
	int num = 0;
	for (size_t i = 0; i < m; i++)
	{
		int x = n / 3;
		for (size_t a = 0; a < pow(3,num); a++) // 1 9 81
		{
			for (size_t b = 0; b < pow(3,num); b++)
			{
				for (size_t i = 0; i < x; i++)
				{
					for (size_t j = 0; j < x; j++)
					{
						map[x + (n * a) + i][x + (n * b) + j] = ' ';
					}
				}
			}
		}
		num++;
		n /= 3;
	}
}

void fill_map(vector<vector<char> > &map, int n)
{
	vector<char> row;
	for (size_t j = 0; j < n; j++)
	{
		row.push_back('*');
	}
	for (size_t i = 0; i < n; i++)
	{
		map.push_back(row);
	}
}

void print_vector(vector<vector<char> > map)
{
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}