// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

// 첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
// 둘째 줄에는 중앙값을 출력한다.
// 셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
// 넷째 줄에는 범위를 출력한다.

using System;
using System.Collections;
using System.Linq;

namespace backjoon
{
	class mainapp
	{

		static void swap(ref char a,ref char b)
		{
			char temp;
			temp = a;
			a = b;
			b = temp;
		}

		static void Main(string []argv)
		{
			string temp = Console.ReadLine();
			char [] temp2 = temp.ToCharArray();
			
			for (int i = 0; i < temp2.Length - 1; i++)
			{
				int j = i + 1;
				while (j != temp2.Length)
				{
					if (temp2[i] < temp2[j])
					{
						swap(ref temp2[i], ref temp2[j]);
					}
					j++;
				}
			}
			Console.WriteLine(temp2);
		}
	}
}
