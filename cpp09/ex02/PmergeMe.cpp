#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &original)
{
	(void)original;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &original)
{
	(void)original;
	return (*this);
}

template <typename T>
void cFiller(T &container, int size, std::string values)
{
	std::istringstream iss(values);
	int n;
	for (int i = 0; i < size; i++)
	{
		iss >> n;
		container.push_back(n);
	}
}

template <typename IT>
void insertionSort(IT begin, IT end)
{
	for (IT i = begin + 1; i != end; i++)
	{
		IT j = i;
		while (j != begin && *j < *(j - 1))
		{
			std::iter_swap(j, j - 1);
			j--;
		}
	}
}


template <typename T, typename IT>
void mergeInsert(T &container, IT begin, IT end)
{
	if (end - begin > 8)
	{
		IT mid = begin + (end - begin) / 2;
		mergeInsert(container, begin, mid);
		mergeInsert(container, mid + 1, end);
		std::inplace_merge(begin, mid, end);
	}
	else
	{
		insertionSort(begin, end);
	}
}

void PmergeMe::execute(int size, std::string values)
{
	std::cout << "Before:  " << values << std::endl;
	std::vector<int> v;
	std::deque<int> d;

	cFiller(v, size, values);
	cFiller(d, size, values);
	mergeInsert(v, v.begin(), v.end());
	mergeInsert(d, d.begin(), d.end());
	std::cout << "After:   ";
	for (int i = 0; i < size; i++)
	{
		std::cout << d[i];
		if (i != size - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{
}
