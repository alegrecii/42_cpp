#include "iter.hpp"


template< typename T >
void print( T& value )
{
  std::cout << value << std::endl;
  return;
}


int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::string str[] = {"ciao", "come", "va", "?"};

	iter(arr, 5, print<int>);
	iter(str, 4, print<std::string>);
	return 0;
}
