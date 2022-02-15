using System;
using static System.Math;
using System.Collections;
using System.Collections.Generic;

namespace Mainapp
{
    class Program
    {
        static int node;
        static int edge;
        static int start;

        static void dfs(ref List<Tuple<int, int>> graphData, bool[] node_visit, int start)
        {
            if (node_visit[start] == true)
                return;
            node_visit[start] = true;
            Console.Write(start + " ");
            List<int> dest_node = new List<int>();
            for (int i = 0; i < graphData.Count; i++)
            {
                int first = graphData[i].Item1;
                int second = graphData[i].Item2;
                if (first == start)
                {
                    dest_node.Add(second);
                }
                else if (second == start)
                {
                    dest_node.Add(first);
                }
            }
            dest_node.Sort();
            for (int i = 0; i < dest_node.Count; i++)
            {
                dfs(ref graphData, node_visit, dest_node[i]);
            }
        }


        static void bfs(ref List<Tuple<int, int>> graphData, bool[] node_visit, int start)
        {
            Queue<int> bfs_queue = new Queue<int>();
            bfs_queue.Enqueue(start);
            node_visit[start] = true;
            while (bfs_queue.Count != 0)
            {
                int node = bfs_queue.Dequeue();
                Console.Write(node + " ");
                List<int> temp = new List<int>();
                for (int i = 0; i < graphData.Count; i++)
                {
                    int first = graphData[i].Item1;
                    int second = graphData[i].Item2;
                    if (first == node)
                    {
                        if (node_visit[second] == false)
                        {
                            node_visit[second] = true;
                            temp.Add(second);
                        }
                    }
                    else if (second == node)
                    {
                        if (node_visit[first] == false)
                        {
                            node_visit[first] = true;
                            temp.Add(first);
                        }
                    }
                }
                temp.Sort();
                for (int i = 0; i < temp.Count; i++)
                {
                    bfs_queue.Enqueue(temp[i]);
                }
            }
        }


        static void Main(string[] args)
        {
            string temp = (Console.ReadLine());
            string []temps = temp.Split(' ');
            node = int.Parse(temps[0]);
            edge = int.Parse(temps[1]);
            start = int.Parse(temps[2]);
            List<Tuple<int, int> > graphData = new List<Tuple<int, int> >();

            for (int i = 0; i < edge; i++)
            {
                string[] ab = Console.ReadLine().Split(' ');
                Tuple<int, int> temp2 = new Tuple<int, int>(int.Parse(ab[0]), int.Parse(ab[1]));
                graphData.Add(temp2);
            }

            //for(int i = 0; i < graphData.Count; i++)
            //{
            //    Console.WriteLine(graphData[i]);
            //}

            bool [] dfs_visit = new bool[node + 1];
            bool [] bfs_visit = new bool[node + 1];

            //for (int i = 0; i < node + 1; i++)
            //         {
            //	if (dfs_visit[i] == true || bfs_visit[i] == true)
            //		Console.WriteLine("funck");
            //         }
            dfs(ref graphData, dfs_visit, start);
            Console.WriteLine();
            bfs(ref graphData, bfs_visit, start);

            return;
        }
    }
}
