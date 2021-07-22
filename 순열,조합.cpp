#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
	std::string s = "abcdef";
	std::sort(s.begin(), s.end());
	int count = 0;
	do 
	{
		std::cout << s << '\n';
		count++;
	} while(std::next_permutation(s.begin(), s.end()));
	cout << "count: " << count << endl;

	cout << "==========================" << endl;

	for (size_t i = 0; i <= s.size(); i++)
	{
		vector<bool> combineList(s.size() - i, false);
		combineList.insert(combineList.end(), i, true);
		sort(combineList.begin(), combineList.end());
		int count = 0;
		do
		{
			count++;
		} while (next_permutation(combineList.begin(), combineList.end()));
		cout << s.size() <<"C"<< i << " = " << count << endl;
	}
}