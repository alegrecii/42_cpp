#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN {

public:
	RPN();
	RPN(RPN const &original);
	~RPN();
	int calculate(std::string &input);

	RPN &operator=(RPN const &original);
};

