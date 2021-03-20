#include <iostream>

using namespace std;


bool palindrome(int start, int end, string str)
{
	if (start > end) // asdsa 홀수인경우
		return true;
	else if (start == end)
		return true;
	//
	if (str[start] == str[end])
		return (palindrome(start + 1, end - 1, str));
	else
		return false;
}

int main()
{
	string str;
	cin >> str;

	bool answer = 0;
	answer = palindrome(0, str.size() - 1, str);
	string temp;
	cout << (temp = answer ? "palindrome : true" : "palindrome : false") << endl;
	return (0);
}
