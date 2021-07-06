// 컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
// 각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
// i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
// computer[i][i]는 항상 1입니다.

// DFS로 풀어야겠음. 왜냐하면 경로에 대한 정보가 중요하니깐?
// 이 알고리즘을 구현할 때 가장 큰 차이점은 그래프 탐색의 경우 어떤 노드를 방문했었는지 여부를 반드시 검사해야한다는 것 (이를 검사하지 않을 경우 무한루프에 빠질 위험이 있음)

// 그래프를 표현하는 방법
// 리스트구조 공간효율성은 낮추고 속도는 높이는 방식
// 행렬구조   공간효율성은 낮추고 속도는 높이는 방식

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <signal.h>

using namespace std;

bool is_connectedList(std::set<int> &connectedList, int index)
{
	if (connectedList.find(index) != connectedList.end())
	{
		return (true);
	}
	return (false);
}

void DFSfunction(std::set<int> &connectedList, int index, vector<vector<int> > &computers)
{
	// if (is_connectedList(connectedList, index) == true)
	// 	return ;
	vector<int> node = computers[index];
	for (int i = 0; i < node.size(); i++)
	{
		if (is_connectedList(connectedList, i) == true)
			continue ;
		if (node[i] == 1)
		{
			connectedList.insert(i);
			DFSfunction(connectedList, i, computers);
		}
	}
}

int solution(int n, vector<vector<int> > computers)
{
	set<int> connectedList;
    int sum = 0;
	// 아래삼각행렬 탐색
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i; j < n; j++)
		{
			if (is_connectedList(connectedList, j) == true)
				continue ;
			else
			{
				cout << j << ": ww " << endl;
				sum++;
				DFSfunction(connectedList, j, computers);
			}
		}
	}
	set<int>::iterator it = connectedList.begin();
	while (it != connectedList.end())
	{
		cout << "value : " << *it << endl;
		it++;
	}
	cout << "set size: " << connectedList.size() << endl;
	return sum;
}


int main()
{
	std::vector<vector<int> > network = { {1,1,0}, {1,1,0}, {0,0,1} }; // 2
	std::vector<vector<int> > network1 = { {1,1,0}, {1,1,1}, {0,1,1} }; // 1
	std::vector<vector<int> > network2 = { {1,1,1}, {1,1,1}, {1,1,1} }; // 1
	int n = network1.size();

	cout << solution(n, network1) << endl;
	return (0);
}

/*
3      2
[[1, 1, 0],
[1, 1, 0],
[0, 0, 1]]

3      1
[[1, 1, 0],
[1, 1, 1],
[0, 1, 1]]
*/