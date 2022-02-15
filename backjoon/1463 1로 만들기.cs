using System;
using static System.Math;
using System.Collections;
namespace csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] memory = new int[1000001];
            int N = int.Parse(Console.ReadLine());
            Array.Fill<int>(memory, 0);
            memory[1] = 0;
            for (int i = 2; i <= N; i++)
            {
                int value = memory[i - 1];
                if (i % 2 == 0)
                {
                    value = Min(value, memory[i / 2]);
                }
                if (i % 3 == 0)
                {
                    value = Min(value, memory[i / 3]);
                }
                memory[i] = value + 1;
            }
            Console.WriteLine(memory[N]);
        }
    }
}
