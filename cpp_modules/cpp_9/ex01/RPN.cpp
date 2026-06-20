#include "RPN.hpp"

RPN::RPN(){};

RPN::RPN(std::queue<int> numbers, std::queue<char> tokens){
	this->numbers = numbers;
	this->tokens = tokens;
};

RPN::RPN(const RPN& rpn){
	*this = rpn;
};

RPN& RPN::operator=(const RPN& rpn){
	(void)rpn;
	return *this;
}

RPN::~RPN(){};

bool isToken(char str)
{
	if((str == '+' || str == '-' || str == '*' || str == '/'))
		return true;
	return false;
}

int calculate(int number1, int number2, char c)
{
	std::cout << "number1: " << number1 << " number2:  " << number2 << " c: " << c << std::endl;
	if(c == '+')
		return number1 + number2;
	if(c == '-')
		return number1 - number2;
	if(c == '*')
		return number1 * number2;
	else if(number2 != 0)
		return number1 / number2;
	return 0;	
}