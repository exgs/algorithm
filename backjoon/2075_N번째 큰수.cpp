#include <iostream>
#include <queue>
using namespace std;


int main()
{
	int N;
	// cin >> N;
	scanf("%d", &N);

	// priority_queue<int, vector<int>, greater<int> > pq; // vector는 메모리를 많이 잡아먹음
	priority_queue<int, vector<int> > pq;
	for (size_t i = 0; i < N * N; i++)
	{
		int temp;
		scanf("%d", &temp);
		// cin >> temp;
		pq.push(temp);
	}
	

	for (size_t i = 0; i < (N - 1); i++)
	{
		pq.pop();
	}
	cout << pq.top();

	// STUB debugging
	// for (size_t i = 0; i < N * N; i++)
	// {
	// 	cout << pq.top();
	// 	if (i % N == N - 1 && i != 0)
	// 		cout << endl;
	// 	else
	// 		cout << " ";
	// 	pq.pop();
	// }
	return (0);
}