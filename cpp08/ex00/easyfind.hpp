#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
void easyfind(T cont, int n)
{
	if (std::find(cont.begin(), cont.end(), n) != cont.end())
		std::cout << "Value Found!" << std::endl;
	else
		std::cout << "Value Not Found!" << std::endl;
}
