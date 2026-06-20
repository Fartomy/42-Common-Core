#include "RPN.hpp"

int main(int ac, char** av)
{
	if(ac != 2)
		return 0;
	int i;
	for(i = 0; av[1][i]; i++) 
	{
		if(av[1][i] == ' ')
			continue;
		if(isdigit(av[1][i]))
			numbers.push(static_cast<int>(av[1][i]) - '0');
		else if(isToken(av[1][i]))
			tokens.push(av[1][i]);
		else {
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	if(numbers.size() - 1 == tokens.size()) 
	{
		int result = numbers.front();
		numbers.pop();
		size_t len = numbers.size();
		for(size_t i = 0; len > i ; i++)
		{
			result = calculate(result, numbers.front(), tokens.front());
			numbers.pop();
			tokens.pop();
		}
		std::cout << result << std::endl;
	}

}