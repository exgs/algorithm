using System;
using System.Collections;

namespace backjoon
{
	class mainapp
	{
		static void Main(string []temp)
		{
			ArrayList src = new ArrayList();
			int n = Int32.Parse(Console.ReadLine());
			for (int i = 0; i < n; i++)
			{
				src.Add(Int32.Parse(Console.ReadLine()));
			}
			src.Sort();

			foreach(int i in src)
			{
				Console.WriteLine(i);
			}
		}
	}
}