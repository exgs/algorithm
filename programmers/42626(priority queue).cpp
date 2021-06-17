#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int first_value;
    int second_value;
    priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());

    while(pq.top() < K)
    {
        if (pq.size() == 1)
            return (answer = -1);
        first_value = pq.top();
        pq.pop();
        second_value = pq.top();
        pq.pop();
        pq.push(first_value + second_value * 2);
        answer++;
    }
    return answer;
}