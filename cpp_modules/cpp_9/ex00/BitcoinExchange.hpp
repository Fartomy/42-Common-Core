#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Date.hpp"
class Date;

using namespace std;

class BitcoinExchange
{
	private:
		std::vector<int> d_split;
		std::vector<std::string> v_rate;
	public:
		BitcoinExchange(/* args */);
		~BitcoinExchange();
		void Data_csv();
		int Compare(Date date);
		//int Compare(std::string str , std:: string value);
};
int Type_control(std::string value);

#endif