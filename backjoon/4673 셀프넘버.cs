using System;
using System.Collections;

namespace csharp
{
    class Program
    {
        static int d(int n)
        {
            int sum = n;
            while (n > 0)
            {
                sum += n % 10;
                n /= 10;
            }
            return (sum);
        }

        static void Main(string[] args)
        {
            bool[] isExist = new bool[10001];
            Array.Fill<bool>(isExist, false);
            for (int i = 1; i < 10001; i++)
            {
                if (isExist[i] == false)
                    Console.WriteLine($"{i}");
                int return_value = i;
                while ((return_value = d(return_value)) <= 10000)
                {
                    isExist[return_value] = true;
                }
            }
        }
    }
}
