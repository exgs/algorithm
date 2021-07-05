#pragma once

#include <iostream>
using namespace std;


// mergesort
struct s_data
{
	size_t size;
	size_t front_size;
	size_t back_size;
};

// utils
void swap(int &a, int &b);
void print_nums(int nums[], size_t count);

// sorting
void bubblesort(int array[], size_t count);
void insertsort(int *array, size_t count);
void selectsort(int *array, size_t count);

void shell_insertsort(int *array, int start, int interval ,size_t count);
void shellsort(int *array, size_t count);

int *mergesort(int *array, s_data data);
void divid(int *lists, s_data data, int **temp1, int **temp2);
void setting_data(s_data &data, int count);
int *merge(int *temp1, int *temp2, s_data data);

int partition(int array[], int start, int end);
void quicksort(int array[], int start, int end);