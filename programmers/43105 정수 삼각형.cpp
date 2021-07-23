#include <iostream>
#include <vector>

using namespace std;

int g_max = 0;
int solution(vector<vector<int>> triangle)
{
	int count = triangle.size();
	for (size_t i = 0; i < count; i++)
	{
		if (i == 0)
			continue;
		for (size_t j = 0; j < triangle[i].size(); j++)
		{
			if (j == 0)
			{
				triangle[i][0] += triangle[i - 1][0];
			}
			else if (j == triangle[i].size() - 1)
			{
				triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i - 1].size() - 1];
			}
			else
			{
				if (triangle[i - 1][j - 1] > triangle[i - 1][j])
				{
					triangle[i][j] += triangle[i - 1][j - 1];
				}
				else
				{
					triangle[i][j] += triangle[i - 1][j];
				}
			}
		}
	}
	
	int sum = 0;
	for (size_t i = 0; i < triangle[count - 1].size(); i++)
	{
		if (sum < triangle[count - 1][i])
			sum = triangle[count - 1][i];
	}
	return sum;
}

int main()
{
	vector<vector<int> > vector1 = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}; // 30
	vector<vector<int> > vector2 = {{1}, {1, 2}, {1, 2, 3}, {1, 2, 3, 4}, {100, 100, 1000, 100, 100}}; // 1009

	cout << solution(vector2) << endl;
	return(0);
}