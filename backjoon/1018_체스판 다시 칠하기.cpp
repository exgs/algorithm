#include <iostream>
using namespace std;

int first_W(char temp[8][8])
{
	int sum = 0;
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			int value = i + j;
			if (value % 2 == 0) //W
			{
				if (temp[i][j] == 'B')
				{
					sum++;
				}
			}
			else
			{
				if (temp[i][j] == 'W')
					sum++;
			}
		}
	}
	return (sum);
}

int first_B(char temp[8][8])
{
	int sum = 0;
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			int value = i + j;
			if (value % 2 == 0) //W
			{
				if (temp[i][j] == 'W')
					sum++;
			}
			else
			{
				if (temp[i][j] == 'B')
					sum++;
			}
		}
	}
	return (sum);
}



void print_chess(char board[8][8])
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

// 1018_체스판 다시 칠하기.cpp
// 첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 
// M(가로), N(세로)
int main()
{
	int N, M;
	scanf("%d", &N); scanf("%d", &M);
	int MIN = N * M;
	char board[N][M];
	for (size_t i = 0; i < N; i++)
	{
		scanf("%s", board[i]);
	}
	// STUB print_all
	// printf("=-=-=-=-=-=-=-==-=-=-==-=-=-=\n");
	// for (size_t i = 0; i < N; i++)
	// {
	// 	for (size_t j = 0; j < M; j++)
	// 	{
	// 		printf("%c", board[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("-----------------------------\n");

	
	for (size_t i = 0; i + 7 < N; i++)
	{
		for (size_t j = 0; j + 7 < M; j++)
		{
			char chess_board[8][8];
			int new_i; int new_j; new_i = i; new_j = j;
			for (size_t a = 0; a < 8; a++)
			{
				new_j = j;
				for (size_t b = 0; b < 8; b++)
				{
					chess_board[a][b] = board[new_i][new_j];
					new_j++;
				}
				new_i++;
			}
			// print_chess(chess_board);
			int first_white = first_W(chess_board);
			int first_black = first_B(chess_board);
			// cout << "first_white: " << first_white << endl;
			// cout << "first_black: " << first_black << endl;
			int local_min;
			if (first_white < first_black)
				local_min = first_white;
			else
				local_min = first_black;
			if (local_min < MIN)
				MIN = local_min;
		}
	}
	printf("%d\n", MIN);
	return (0);
}