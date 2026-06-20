#include "BitcoinExchange.hpp"
#include "Date.hpp"

int	 ft_stoi(std::string nbr)
{
	long i;

	if(!isNumber(nbr))
	{
		std::cerr << "not number" << std::endl;
		return (-1);
	}
	i = stol(nbr);
	if(i < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (-1);
	}
	else if(i > INT_MAX )
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (-1);
	}
	return (int)i;
}


int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	Date date;
	BitcoinExchange bitcoin;
	bitcoin.Data_csv();
	date.input_txt(av[1]);
	bitcoin.Compare(date);
}
