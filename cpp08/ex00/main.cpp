#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	int arr[] = {1, 2, 3, 4, 5};
	v.assign(arr, arr+5);
	easyfind(v, 4);
	easyfind(v, 8);

	std::cout << std::endl;
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	easyfind(v, 2);
	easyfind(v, 6);
}
