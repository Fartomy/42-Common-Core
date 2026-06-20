#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "BitcoinExchange.hpp"
class BitcoinExchange;

class Date
{
	private:
		std::vector<int> i_split;
		std::vector<std::string> v_value;
		std::vector< std::vector<std::string> > vector;

	public:
		Date();
		~Date();
		std::vector<int> geti_split() const;
		std::vector<std::vector<std::string> > getVector() const;
		std::vector<std::string> getv_value() const;
		bool is_valid_date(int day, int month, int year);
		void input_txt(std::string file);
};

std::vector<std::string> split( std::string s, const std::string& c); 
bool isNumber(std::string str);
int ft_stoi(std::string nbr);

#endif