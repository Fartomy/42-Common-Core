#include "Date.hpp"

Date::Date()
{
}

Date::~Date()
{
}

std::vector<int> Date::geti_split() const
{
	return this->i_split;
}

std::vector<std::vector<std::string> > Date::getVector() const
{
	return this->vector;
}

std::vector<std::string> Date::getv_value() const
{
	return this->v_value;
}


bool Date::is_valid_date(int day, int month, int year)
{

    if (year < 1 || year > 9999) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;
        }
    }
    return true;

 }

bool isNumber(std::string str) {
	for(size_t i = 0; i < str.length() - 1; i++)
		if(!isdigit(str[i]) && (str[i] != '-' && str[i] != ' '))
			return false;
		
	return true;
}

std::vector<std::string> split( std::string s, const std::string& c) 
{
    std::vector<std::string> arr;
    
    size_t start = 0;
    size_t end = s.find(c);

    while (end != std::string::npos) {
        std::string sub = s.substr(start, end - start);
        arr.push_back(sub);
        start = end + 1;
        end = s.find(c, start);
    }
    
    std::string sub = s.substr(start);
    arr.push_back(sub);
	return arr;
}

void Date::input_txt(std::string file)
{
	std::ifstream input(file, std::ios::binary);

	if(!input.is_open())
		exit(1);

	std::string line;
	std::string  value;

    while (std::getline(input, line)) 
	{
		if(!isdigit(line[0]))
			continue;
        std::stringstream ss(line);
		std::string date_str;
        std::getline(ss, date_str, '|');
		std::vector<std::string> tmp_date = split(date_str,"-");
		vector.push_back(tmp_date);
		std::string tmp;
		for(std::vector<std::string>::iterator it = tmp_date.begin(); it != tmp_date.end(); it++)
			tmp += *it;
		i_split.push_back(stoi(tmp));
		std::getline(ss, value);
		if(value.size() == 0)
			value = "  ";
		value.erase(0,1);
		v_value.push_back(value);
	}
	input.close();
} 
