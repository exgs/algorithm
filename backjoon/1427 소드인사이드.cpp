#include <iostream>
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <new>

// 10자리수
// 1,000,000,000

size_t getLength(char temp[11])
{
	size_t i = 0;
	while (temp[i] != 0)
	{
		i++;
	}
	return (i);
}

// 선택정렬
void sorting1(char temp[11], size_t size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int j = i + 1;
		while (j != size)
		{
			if (temp[i] < temp[j])
			{
				char ee = temp[i];
				temp[i] = temp[j];
				temp[j] = ee;
			}
			j++;
		}
	}
}

// 버블소트
void sorting2(char *temp, size_t size)
{
	for (int a = 0; a < size - 1; a++)
	{
		for (int i = 0; i < size - 1 - a; i++)
		{
			int j = i + 1;
			if (temp[i] < temp[j])
			{
				char ee = temp[i];
				temp[i] = temp[j];
				temp[j] = ee;
			}
		}
	}
}

// https://gmlwjd9405.github.io/2018/05/06/algorithm-bubble-sort.html
void bubble_sort(int list[], int n){
  int i, j, temp;

  for(i=n-1; i>0; i--){
    // 0 ~ (i-1)까지 반복
    for(j=0; j<i; j++){
      // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
      if(list[j]<list[j+1]){
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}

char temp[11];
using namespace std;

int main()
{
	scanf("%s", temp);
	size_t size = getLength(temp);
	if (size == 0)
	{
		printf("\n");
	}
	sorting2(temp, size);
	printf("%s\n",temp);
	return (0);
}