// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

// 첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
// 둘째 줄에는 중앙값을 출력한다.
// 셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
// 넷째 줄에는 범위를 출력한다.

using System;
using System.Collections;
using System.Linq;
namespace backjoon
{
	class mainapp
	{
		static void Main(string []argv)
		{
			int n = Int32.Parse(Console.ReadLine());
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
			{
				arr[i] = Int32.Parse(Console.ReadLine());
			}
			Array.Sort(arr);
			int min = arr[0];
			int max = arr[n - 1];

			double average = (double)arr.Sum() / n;
			int mid = arr[(n - 1)/ 2];
			int often;
			int range = max - min;

			int data_cnt = 0;
			int data = 0;
			bool flag = false;
			foreach (var item in arr.GroupBy(x=>x))
            {
            	// 반복된 횟수가 더 적을 경우 최빈값이 아니므로 continue
                if (item.Count() < data_cnt)
                    continue;
                    
                // 반복된 횟수가 더 많으면 최빈값이므로 data 갱신, data_cnt 갱신 
                // 최빈값이 여러개라면 두번째로 작은 값 출력을 위해 flag 사용
                // 만약 flag 가 true 되더라도 더 많은 빈도수를 가진 데이터 발견 시 
                // flag -> flase 로 변경 및 data 갱신
                if (item.Count() > data_cnt)
                {
                    data_cnt = item.Count();
                    data = item.Key;
                    flag = false;
                    continue;
                }
				
                // 빈도수가 같고, flag 가 false 라면 두번째로 작은 값이므로 flag -> true
                // 정렬되어 있으므로 빈도수가 같고, flag가 true 가 된다면 두번째로 작은 최빈값
                if (data_cnt == item.Count() && flag == false)
                {
                    data = item.Key;
                    flag = true;
                    continue;
                }
            }
			often = data;
		
			Console.WriteLine(Math.Round(average));
			Console.WriteLine(mid);
			Console.WriteLine(often);
			Console.WriteLine(range);
		}
	}
}