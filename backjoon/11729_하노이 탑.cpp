using System;
using static System.Console;
using System.Text;

namespace test
{
	class MainApp
	{
		static void hanoi(int src, int stop, int dst, int N, StringBuilder string_builder)
		{
			if (N == 1)
			{
				string_builder.AppendFormat(string.Format("{0} {1}\n", src, dst));
				return ;
			}
			
			hanoi(src, dst, stop, N - 1, string_builder);
			hanoi(src, stop, dst, 1, string_builder);
			hanoi(stop, src, dst, N - 1, string_builder);
			return ;
		}

		static void hanoi(int src, int stop, int dst, int N)
		{
			if (N == 1)
			{
				Write("{0} {1}\n", src, dst);
				return ;
			}
			
			hanoi(src, dst, stop, N - 1);
			hanoi(src, stop, dst, 1);
			hanoi(stop, src, dst, N - 1);
			return ;
		}

		// static int num = 0;
		// static void hanoi_num(int src, int stop, int dst, int N)
		// {
		// 	if (N == 1)
		// 	{
		// 		num++;
		// 		return ;
		// 	}
			
		// 	hanoi_num(src, dst, stop, N - 1);
		// 	hanoi_num(src, stop, dst, 1);
		// 	hanoi_num(stop, src, dst, N - 1);
		// 	return ;
		// }
		static void Main()
		{
			// StringBuilder string_builder = new StringBuilder();
			int N = int.Parse(ReadLine());
		
			// hanoi_num(1, 2, 3, N);
			Write("{0}\n", Math.Pow(2, N) - 1);

			// STUB 타임아웃!
			hanoi(1, 2, 3, N);

			// STUB 시간줄이기 최적화
			hanoi(1, 2, 3, N, string_builder);
			Write(string_builder);
			return;
		}
	}
}