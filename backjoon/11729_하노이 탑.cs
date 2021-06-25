using System;
using static System.Console;

namespace test
{
	class MainApp
	{
		static int num = 0;
		static void hanoi(int src, int stop, int dst, int N)
		{
			if (N == 1)
			{
				WriteLine("{0} {1}", src, dst);
				return ;
			}
			
			hanoi(src, dst, stop, N - 1);
			hanoi(src, stop, dst, 1);
			hanoi(stop, src, dst, N - 1);
			return ;
		}

		static void hanoi_num(int src, int stop, int dst, int N)
		{
			if (N == 1)
			{
				num++;
				return ;
			}
			
			hanoi_num(src, dst, stop, N - 1);
			hanoi_num(src, stop, dst, 1);
			hanoi_num(stop, src, dst, N - 1);
			return ;
		}
		static void Main()
		{
			int N = int.Parse(ReadLine());

			hanoi_num(1, 2, 3, N);
			WriteLine(num);
			hanoi(1, 2, 3, N);
			return;
		}
	}
}