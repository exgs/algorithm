#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<pair<int, int> > &graphData, bool *node_visit, int start)
{
	if (node_visit[start] == true)
		return;
	node_visit[start] = true;
	cout << start << " ";
	vector<int> dest_node;
	for (int i = 0; i < graphData.size(); i++)
	{
		int first = graphData[i].first;
		int second = graphData[i].second;
		if (first == start)
		{
			dest_node.push_back(second);
		}
		else if (second == start)
		{
			dest_node.push_back(first);
		}
	}
	sort(dest_node.begin(), dest_node.end());
	for (int i = 0; i < dest_node.size(); i++)
	{
		dfs(graphData, node_visit, dest_node[i]);
	}
}


void bfs(vector<pair<int, int> >& graphData, bool* node_visit, int start)
{
	queue<int> bfs_queue;
	bfs_queue.push(start);
	node_visit[start] = true;
	while (bfs_queue.size() != 0)
	{
		int node = bfs_queue.front();
		bfs_queue.pop();
		cout << node << " ";
		vector<int> temp;
		for (int i = 0; i < graphData.size(); i++)
		{
			int first = graphData[i].first;
			int second = graphData[i].second;
			if (first == node)
			{
				if (node_visit[second] == false)
				{
					node_visit[second] = true;
					temp.push_back(second);
				}
			}
			else if (second == node)
			{
				if (node_visit[first] == false)
				{
					node_visit[first] = true;
					temp.push_back(first);
				}
			}
		}
		sort(temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++)
		{
			bfs_queue.push(temp[i]);
		}
	}
}

int node; int edge; int start;
int main()
{
	scanf_s("%d", &node);
	scanf_s("%d", &edge);
	scanf_s("%d", &start);
	bool* node_visit = new bool[node + 1];
	vector<pair<int, int> >graphData;
	for (int i = 0; i < edge; i++)
	{
		int a, b;
		scanf_s("%d", &a);
		scanf_s("%d", &b);
		graphData.push_back(std::make_pair(a, b));
	}

	dfs(graphData, node_visit, start);
	cout << "\n";
	memset(node_visit, 0, node + 1);
	bfs(graphData, node_visit, start);

	delete[]node_visit;
	return (0);
}
