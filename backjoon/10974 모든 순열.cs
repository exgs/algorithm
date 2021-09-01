using System;
using static System.Math;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace Mainapp
{
    class Program
    {
        // https://webbibouroku.com/Blog/Article/cs-permutation
        static List<T[]> AllPermutation<T>(params T[] array) where T : IComparable
        {
            var a = new List<T>(array).ToArray();
            var res = new List<T[]>();
            res.Add(new List<T>(a).ToArray());
            var n = a.Length;
            var next = true;
            while (next)
            {
                next = false;

                // 1
                int i;
                for (i = n - 2; i >= 0; i--)
                {
                    if (a[i].CompareTo(a[i + 1]) < 0) break;
                }
                // 2
                if (i < 0) break;

                // 3
                var j = n;
                do
                {
                    j--;
                } while (a[i].CompareTo(a[j]) > 0);

                if (a[i].CompareTo(a[j]) < 0)
                {
                    // 4
                    var tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                    Array.Reverse(a, i + 1, n - i - 1);
                    res.Add(new List<T>(a).ToArray());
                    next = true;
                }
            }
            return res;
        }

        static void Main(string[] args)
        {
            string temp = (Console.ReadLine());
            int value = int.Parse(temp);
            int[] num_array = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };
            int[] input_array = new int[value];
            for (int i = 0; i < value; i++)
            {
                input_array[i] = num_array[i];
            }
            foreach (var item in AllPermutation(input_array))
            {
                Console.WriteLine(string.Join(" ", item));
            }
            return;
        }
    }
}
