#include <math.h>
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int greatest_common_divisor(int a, int b)
{
	if (a < b)
		swap(a, b);
	if(b != 0)
		return (greatest_common_divisor(b, a % b));
	return (a);
}

long long solution(int w,int h) {
    long long answer = 1;
	int gcd = greatest_common_divisor(w, h);
	// cout << w << " " << h <<" GCD: " << gcd << endl;
	long long w_div = w / gcd; // 8byte int
	long long h_div = h / gcd; // 8byte int
	int blank_box = 0;
	if (w_div == h_div)
	{
		blank_box = w_div;
	}
	else
	{
		if (w_div > h_div) // 항상 height가 width보다 크도록 함.
			swap(w_div, h_div);
		double slope = ((double)h_div / (double)w_div); // > 1
		
		double before = 0;
		for (int i = 0; i < w_div; i++)
		{
			double cur = 0;
			cur = before + slope;
			blank_box += (ceil(cur) - floor(before));
			before = cur;
		}
	}
	long long temp2;
	temp2 = (long long)w * (long long)h;
	answer = temp2 - blank_box * gcd;
	return answer;
}

long long solution2(int w, int h)
{
	long long  answer = 1;
	long W = (long)w;
	long H = (long)h;
	long long total = W * H;
	if (H > W)
	{
		long temp = H;
		H = W;
		W = temp;
	}
	if (H == W)
		return total - W;
	long long cutsquare = 0;
	double slope = (double) H / W;
	//실제 기울기 (double형으로 제대로 표현 되야한다!) (1보다 작거나 같은 수) long cutsquare = 0;
	for (long i = 1; i <= W; i++)
	{
		double befval = slope * (i - 1);
		double curval = slope * i;
		if (floor(befval) == floor(curval) || floor(curval) == ceil(curval))
			cutsquare += 1;
		else
		{
			cutsquare += 2;
		}
	}
	answer = total - cutsquare;
	return answer;
}


int main()
{
	int a = 10000;
	int b = 10000;
	for (size_t i = 1; i < a; i++)
	{
		for (size_t j = 1; j < b; j++)
		{
			/* code */
			long long c = solution(i, j);
			long long d = solution2(i, j);
			if (c != d)
			{
				cout << i << " " << j << endl;
				cout << "c: " << c << " d: " << d << endl;
				goto here;
			}
		}
	}
	// example
	here:
	cout << "floor((double)2/98 * 49 ) " << floor((double)2/98 * 49) << endl;
	cout << "ceil ((double)2/98 * 49 ) " << ceil ((double)2/98 * 49) << endl;

	return (1);
}