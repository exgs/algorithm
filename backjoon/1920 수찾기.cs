using System;
using static System.Math;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.IO;

namespace Mainapp
{

    class Program
    {
        static void Main(string[] args)
        {
            int num_int = int.Parse(Console.ReadLine());
            int[] A = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            Array.Sort(A);

            int num_int2 = int.Parse(Console.ReadLine());

            int[] B = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            foreach (int item in B)
            {
                //if (Array.BinarySearch<int>(A, item) >= 0)
                if (binSearch(A, item, 0, A.Length - 1) == true)
                {
                    Console.Write("1\n");
                }
                else
                {
                    Console.Write("0\n");
                }
            }
            return;
        }
        
        // Array.BinSearch 은 int index를 반환하는 함수이기때문에 시간이 더 걸린다.
        private static bool binSearch(int []paN, int dSearchNum, int Min, int Max)
        {
            int Mid;
            Mid = (Min + Max) / 2;

            if (Min > Max)
                return false;

            if (paN[Mid] == dSearchNum)
                return true;

            if (paN[Mid] > dSearchNum)
                return binSearch(paN, dSearchNum, Min, Mid - 1);
            else
                return binSearch(paN, dSearchNum, Mid + 1, Max);
        }
    }
}


namespace TestCodes
{
    class Problem
    {
        static void Main()
        {
            var sr = new StreamReader(Console.OpenStandardInput());
            var sw = new StreamWriter(Console.OpenStandardOutput());
            var sb = new StringBuilder();
            sw.AutoFlush = true;

            sr.ReadLine();
            var nums = sr.ReadLine().Split(' ');

            var dic = new Dictionary<string, int>();
            foreach (var num in nums)
            {
                if (!dic.ContainsKey(num))
                    dic.Add(num, 1);
                else
                    dic[num]++;
            }

            sr.ReadLine();
            var check = sr.ReadLine().Split(' ');

            foreach (var num in check)
            {
                if (dic.ContainsKey(num))
                    sb.AppendLine("1");
                else
                    sb.AppendLine("0");
            }

            sw.Write(sb);
        }
    }
}
