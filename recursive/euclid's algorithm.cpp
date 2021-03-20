#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}

int greatest_common_divisor(int a, int b)
{
	if (a < b)
		swap(a, b);
	if(b != 0)
		return (greatest_common_divisor(b, a % b));
	return (a);
}

int main()
{
	int a,b;
	cin >> a >> b;

	if (a < b)
		swap(a,b);
	int answer;
	answer = greatest_common_divisor(a, b);
	cout << "GCD : " << answer << endl;
	return (1);
}
