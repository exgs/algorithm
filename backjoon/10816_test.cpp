#include <iostream>
#include <algorithm>
using namespace std;

int arr[500003];

int main()
{
	int N, M, in;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	// cout << arr << "\n" << arr+N << "\n";
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> in;
		// cout << upper_bound(arr, arr + N, in) << "\n";
		// cout << lower_bound(arr, arr + N, in) << "\n";
		cout << upper_bound(arr, arr + N, in) - lower_bound(arr, arr + N, in);
		if (i == M -1)
			break;
		cout << " ";
	}
	cout << endl;
}