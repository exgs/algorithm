#include <iostream>
using namespace std;

int f(int n)
{
	if (n == 1)
		return (1);
	else if (n == 2)
		return (2);
	else if (n == 3)
		return (4);
}

int coding_drill(int n)
{
	if (n - 1 == 0)
		return (f(1));
	if (n - 2 == 0)
		return (f(2));
	if (n - 3 == 0)
		return (f(3));
	return (coding_drill(n - 1) + coding_drill(n - 2) + coding_drill(n - 3));
}

int main()
{
	int n;
	cin >> n;
	int answer = coding_drill(n);
	cout << "answer : " << answer<< endl;
	return (1);
}
