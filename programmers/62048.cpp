/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   62048.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:11:06 by yunslee           #+#    #+#             */
/*   Updated: 2021/06/07 10:11:39 by yunslee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
	int temp = greatest_common_divisor(w, h);
	// cout << w << " " << h <<" GCD: " << temp << endl;
	long long w_div = w / temp;
	long long h_div = h / temp;
	int blank_box;
	if (w_div == h_div)
	{
		blank_box = w_div;
	}
	else if (w_div > h_div)
	{
		blank_box = ceil(double(w_div)/h_div) * h_div;
	}
	else
	{
		blank_box = ceil(double(h_div)/w_div) * w_div;
	}
	unsigned long long temp2;
	temp2 = (long long)w * h;
	answer = temp2 - blank_box * temp;
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