/*
다리에 트럭이 올라가는 것이 제한무게만 넘어가지않으면 병렬처럼 올라가고, 나갈때는 queue구조로 하나씩 나가는 것이 이해가 안됨.
해답을 복사함
*/

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int tot_w = 0;

    int t_front = 0;
    int t_cur = 0;

    int sec = 0;

    queue <int> q;

    while (t_front != truck_weights.size())
	{
        if (!q.empty() && (sec - q.front() == bridge_length)) {
            tot_w -= truck_weights[t_front];
            ++t_front;
            q.pop();
        }
        if (t_cur != truck_weights.size() && tot_w + truck_weights[t_cur] <= weight) {
            tot_w += truck_weights[t_cur];
            ++t_cur;
            q.push(sec);
        }
        ++sec;
    }

    answer = sec;

    return answer;
}

int main()
{
	int a = 2  ; int b = 10 ; vector<int>temp = {7,4,5,6}; // 8 
	int c = 100; int d = 100; vector<int>temp1	= {10}; // 101
	int e = 100; int f = 100; vector<int>temp2 = {10,10,10,10,10,10,10,10,10,10}; // 110

	cout << solution(e, f, temp2) << endl;
	return (0);
}

/*
2	10	[7,4,5,6]								8
100	100	[10]									101
100	100	[10,10,10,10,10,10,10,10,10,10]			110
*/