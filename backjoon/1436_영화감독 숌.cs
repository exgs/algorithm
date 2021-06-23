using System;

namespace Film
{
	class MainApp
	{
		static bool is_bad_number(int num)
		{
			string num_string = num.ToString();
			string stack = "";
			foreach (char c in num_string)
			{
				if (c == '6')
				{
					stack += '6';
				}

				if (stack.Length != 0)
				{
					if (stack.Length >= 3)
					{
						return (true);
					}
					else if (c != '6')
					{
						stack = "";
					}
				}
			}
			return (false);
		}
		static void Main(string[] args)
		{
			string input_ = Console.ReadLine();
			int N = int.Parse(input_);
			int count = 0;
			int num = 0;

			while (true)
			{
				if (is_bad_number(num) == true)
				{
					count++;
				}

				if (count == N)
				{
					Console.WriteLine(num);
					return ;
				}
				num++;
			}
			return ;
		}
	}
}

/*
666
1666
2666
3666
4666
5666
6661
6662
6663
...
6666
6669
7666
....

9666
10666
15666

16661 16662 16663 16664 16665 ... 
17666

*/