#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void minusAll(vector<int> &temp)
{
	temp[0]--;
	temp[1]--;
}

void print_element(long long a)
{
	cout << a << " ";
}

void printAll(vector<long long> temp)
{
	for_each(temp.begin(), temp.end(), print_element);
	cout << endl;
}

int solution(int m, int n, vector<vector<int> > puddles) {
	vector<long long> sample(n, 0);
	vector<vector<long long> >data(m, sample);
	for_each(puddles.begin(), puddles.end(), minusAll); // 위치를 index로 바꾸어 줌

	data[0][0] = 1;
	for (size_t i = 0; i < puddles.size(); i++)
	{
		data[puddles[i][0]][puddles[i][1]] = -1;
	}

	int i = 1;
	int j = 0;
	while ( !(i == (int)(data.size() - 1) && j == ((int)data[0].size())) )
	{
		int x = i;
		int y = j;
		while ( !(x == -1 || y == data[0].size()))
		{
			if (y == 0)
			{
				if (data[x - 1][y] != -1 && data[x][y] != -1)
					data[x][y] += data[x - 1][y];
			}
			else if (x == 0)
			{
				if (data[x][y - 1] != -1 && data[x][y] != -1)
					data[x][y] += data[x][y - 1];
			}
			else
			{
				if (data[x - 1][y] != -1 && data[x][y] != -1)
					data[x][y] += data[x - 1][y];
				if (data[x][y - 1] != -1 && data[x][y] != -1)
					data[x][y] += data[x][y - 1];
			}
			if (data[x][y] > 1000000007)
				data[x][y] %= 1000000007;
			x--;
			y++;
		}
	
		// 일반적인 상황
		i++;
		// 일반적이지 않은 마지막 상황, 마지막에 i가 내려갈 수 가 없을 때
		if (i == (int)data.size())
		{
			i = (int)data.size() - 1;
			j++;
		}
	}
	// for_each(data.begin(), data.end(), printAll); cout << endl;
	long long answer = data[m - 1][n - 1];
	return answer % 1000000007;
}

int main()
{
	vector<vector<int> > poll = {}; // 4
	int m = 3;
	int n = 3;
	cout << solution(m, n, poll) << endl;
	return(0);
}