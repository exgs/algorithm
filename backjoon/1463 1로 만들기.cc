// 다이나믹 프로그래밍, 배열로 메모리제이션
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int memory[1000001] = { 0, };

int main()
{
    int N;
    scanf("%d", &N);
    memory[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        int value = memory[i - 1];
        if (i % 2 == 0)
        {
            value = min(value, memory[i / 2]);
        }
        if (i % 3 == 0)
        {
            value = min(value, memory[i / 3]);
        }
        memory[i] = value + 1;
    }
    printf("%d\n", memory[N]);
    return (0);
}
