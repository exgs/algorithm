using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Threading;
using System.Diagnostics;
using static System.Console;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace HelloWorld
{

	class Program
	{
		static int length = 0;
		static bool []havebeenthere;
		static void dfs(int[,] graph, int i)
		{
			WriteLine(i);
			havebeenthere[i] = true;
			for (int j = 0; j < length; j++)
			{
				if (graph[i, j] != 0 && havebeenthere[j] == false)
				{
					dfs(graph, j);
				}
			}
		}

		static void bfs(int[,] graph, int rootidx)
		{
			var que = new Queue<int>();
			que.Enqueue(rootidx);
			WriteLine(rootidx);
			havebeenthere[rootidx] = true;
			while (que.Count() != 0)
			{
				int i = que.Dequeue();
				for (int j = 0; j < length; j++)
				{
					if (graph[i, j] != 0 && havebeenthere[j] == false)
					{
						WriteLine(j);
						havebeenthere[j] = true;
						que.Enqueue(j);
					}
				}
			}
		}

		static void Main(string[] args)
		{
			// 무방향 인접 행렬
			var abc = new int [7, 7]
			{{0,1,1,1,0,0,0},
			 {1,0,0,0,1,0,0},
			 {1,0,0,0,1,1,0},
			 {1,0,0,0,0,1,0},
			 {0,1,1,0,0,0,1},
			 {0,0,1,1,0,0,1},
			 {0,0,0,0,1,1,0},
			};

			length = 7;
			havebeenthere = new bool[length];
			Console.WriteLine(abc.Length);
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					Write($"{abc[i, j]} ");
				}
				WriteLine();
			}
			WriteLine("-----");
			dfs(abc, 0);
			havebeenthere = havebeenthere.Select(_ => false).ToArray();
			WriteLine("-----");
			bfs(abc, 0);
		}
	}
}