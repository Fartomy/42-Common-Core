#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <queue>

class RPN {
	private:
		std::queue<int> numbers;
		std::queue<char> tokens;
	public:
		RPN();
		RPN(std::queue<int> numbers, std::queue<char> tokens);
		RPN(const RPN& rpn);
		RPN& operator=(const RPN& rpn);

		~RPN();


};

		bool isToken(char str);
		int calculate(int number1, int number2, char c);
#endif