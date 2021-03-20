#include <iostream>

using namespace std;

int count = 0;
int where[3];
void hanoi(int num, int from, int by, int to)
{
	if (num == 1)
	{
		::count++;
		where[from]--;
		where[to]++;
		cout << "[" << ::count << "] " << from << " -> " << to << endl;
		cout << "    " <<where[0] << " | " << where[1] << " | " << where[2] << endl;
		return ;
	}
	hanoi(num - 1, from, to, by);
	hanoi(1, from, by, to);
	hanoi(num - 1, by, from, to);
}

int main()
{
	int n;
	cin >> n;
	where[0] = n;
	hanoi(n, 0, 1, 2);
	return (1);
}
