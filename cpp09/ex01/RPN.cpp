#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const &original)
{
	(void) original;
}

RPN &RPN::operator=(RPN const &original)
{
	(void) original;
	return (*this);
}

bool numberCheck(std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

int RPN::calculate(std::string &input)
{
	std::stack<int> stack;
	std::stringstream iss(input);
	std::string operand;

	while(iss >> operand)
	{
		if (operand == "+" || operand == "-" || operand == "*" || operand == "/")
		{
			if (stack.size() < 2)
			{
				std::cout << "Syntax Error" << std::endl;
				return 0;
			}
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (operand == "+")
				stack.push(b + a);
			else if (operand == "-")
				stack.push(b - a);
			else if (operand == "*")
				stack.push(b * a);
			else if (operand == "/")
			{
				if (a == 0)
				{
					std::cout << "Error: Division by zero" << std::endl;
					return 0;
				}
				stack.push(b / a);
			}
		}
		else
		{
			int num;
			if(!numberCheck(operand))
			{
				std::cout << "Syntax Error" << std::endl;
				return 0;
			}
			num = std::atoi(operand.c_str());
			stack.push(num);
		}
	}
	if (stack.size() > 1)
		std::cout << "Syntax Error" << std::endl;
	else
		std::cout << stack.top() << std::endl;
	return 0;
}

RPN::~RPN()
{

}
