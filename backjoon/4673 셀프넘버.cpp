#include <iostream>
#include <stdio.h>

int d(int n)
{
    int sum = n;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return (sum);
}
int main()
{
    bool isExist[10001] = { false, };
    for (int i = 1; i < 10001; i++)
    {
        if (isExist[i] == false)
            printf("%d\n", i);
        int return_value = i;
        while ((return_value = d(return_value)) <= 10000)
        {
            isExist[return_value] = true;
        }
    }
    return (0);
}
