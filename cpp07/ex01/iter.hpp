#pragma once
#include <iostream>
#include <string>

template <typename T, typename F, typename S>
void iter(T *array, int n, F func(S))
{
	for (int i = 0; i < n; i++)
		func(array[i]);
}
