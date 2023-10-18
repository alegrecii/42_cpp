#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <limits>

class PmergeMe
{
private:
public:
	PmergeMe();
	PmergeMe(PmergeMe const &original);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &original);
	void execute(int size, std::string values);
};
