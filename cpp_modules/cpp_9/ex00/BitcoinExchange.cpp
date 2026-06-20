#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{

}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::Data_csv()
{
	std::string line;
    std::string date_csv, rate;
	std::vector<std::string> tmp_split;

    std::ifstream input("data.csv");
	if(!input.is_open())
		exit(1);
    while (std::getline(input, line))
	{
		if(!isdigit(line[0]))
			continue;
        std::stringstream ss(line);
        std::getline(ss, date_csv, ',');
		tmp_split = split(date_csv, "-");
		std::string tmp;
		for(std::vector<std::string>::iterator it = tmp_split.begin(); it != tmp_split.end(); it++)
			tmp += *it;
		d_split.push_back(stoi(tmp));
        std::getline(ss, rate);
		v_rate.push_back(rate);
    }
	input.close();
}

int BitcoinExchange::Compare(Date date)
{
	size_t i = 0;
	size_t j = 0;

 	while(i <= date.geti_split().size() -1)
	{
		j = 0;
		while(j <= d_split.size() -1)
		{
			if(date.is_valid_date(stoi(date.getVector()[i][2]), stoi(date.getVector()[i][1]), stoi(date.getVector()[i][0])))
			{
				if(d_split[j] > date.geti_split()[i] && j > 0)
				{
					if(Type_control(v_rate[j - 1]) == -2 && Type_control(date.getv_value()[i]) != -1) 
					{
							std::cout << date.getVector()[i][0]<< "-" << date.getVector()[i][1] << "-" << date.getVector()[i][2] << " => "<< date.getv_value()[i];
							float res = stof(v_rate[j - 1]) * stof(date.getv_value()[i]);
							std::cout <<  " = " << std::to_string(res) << std::endl;
							
					}
					else if(Type_control(v_rate[j - 1]) != -2 && Type_control(date.getv_value()[i]) != -1)
					{
						std::cout << date.getVector()[i][0]<< "-" << date.getVector()[i][1] << "-" << date.getVector()[i][2] << " => "<< date.getv_value()[i] << " => "<< date.getv_value()[i];
						std::cout << " = " << stoi(v_rate[j - 1]) * stoi(date.getv_value()[i]) << std::endl;
					}
					break;
				}
			}
			else
			{
				std::cout << "Error: bad input => " << date.getVector()[i][0];
				std::cout << "-" << date.getVector()[i][1] << "-" << date.getVector()[i][2] <<std::endl;
				break;
			}
 			j++;
		 }
		 i++;
	 }
	return 0;
}

int Type_control(std::string value)
{
	if(value.find(".") != std::string::npos || value.find(",") != std::string::npos )
		return -2;
	return ft_stoi(value);
}
