#include <iostream>
#include <stdio.h>
#include <algorithm>


int main()
{
    int N;
    scanf_s("%d", &N);
    int count = N;
    int sum = 0;
    int *data = new int[N];
    for (int i = 0; i < count; i++)
    {
        scanf_s("%d", &data[i]);
    }
    
    std::sort(data, data + count);
    sum += data[0];
    for (size_t i = 1; i < count; i++)
    {
        data[i] += data[i - 1];
        sum += data[i];
    }
    printf("%d\n", sum);
    return (0);
}
