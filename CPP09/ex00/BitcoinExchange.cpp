#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cmath>

BitcoinExchange::BitcoinExchange(){std::cout << "|Bitcoin| default constructor called\n" << std::flush;};

BitcoinExchange::BitcoinExchange(const std::string &s){
	std::cout << "|Bitcoin| string constructor called\n" << std::flush;
	std::fstream file;

	if (s.length() < 4 || s.substr(0) != ".csv")

	file.open(s.c_str());
	if (!file.is_open())
		throw std::runtime_error("couldn't open" + s + '\n');
	std::string line;
	getline(file, line);// skip first line who's description the data
	while (getline(file, line))
	{
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = line.substr(0, comma);
		if (!this->checkdate(date))
			continue;
		std::string value = line.substr(comma + 1);
		float num;
		std::istringstream iss(value);
		iss >> num;
		this->data[date] = num;
	}
};

BitcoinExchange::~BitcoinExchange(){
	std::cout << "|Bitcoin| destructor called\n" << std::flush;
}

const BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &b){
	std::cout << "|Bitcoin| copy assignment operator called\n" << std::flush;
	if (this != &b)
		*this = b;
	return (*this);
};

float BitcoinExchange::getValue(const std::string &key){
	if (this->data.empty() )
	{
		std::cout << "Empty DB\n" << std::flush;
		return (NAN);
	}
	else if (key < this->data.begin()->first)
	{
		std::cout << "Date too old\n" << std::flush;
		return (NAN);
	}
	std::map<std::string, double>::iterator val = this->data.upper_bound(key);
	val--;
	return val->second;
}


int BitcoinExchange::verify(const std::string &line){
	size_t find = line.find('|');
	std::string date;
	if (find == std::string::npos || find < 2)
	{
		std::cout << ("Error: bad input => " + line.substr(0, find) + '\n') << std::flush;
		return (0);
	}
	date = line.substr(0, find - 1);
	checkdate(date);
	if (line.at(find - 1) != ' ' || line.at(find + 1) != ' ' || line.length() <= (find + 2))
	{
		std::cout << ("Error: bad input => " + line.substr(0, find) + '\n') << std::flush;
		return (0);
	}
	float i;
	if (this->checkvalue(line.substr(find + 2), i, date))
	{
		float num = this->getValue(date);
		std::cout << date << "=>" << num  << "=" << (num * i) << "\n" << std::flush;
		return (1);
	}
	// error

	//std::cout << ("Error: bad input => " + date + '\n') << std::flush;
	return (0);
}

bool BitcoinExchange::checkvalue(const std::string &line, float &i, const std::string &date)
{
	std::istringstream iss(line);
	iss >> i;
	if (i > 1000 || i < 0 || (iss.fail() || !iss.eof()))
	{
		if (i < 0)
			std::cout << "Error: not a positive number\n" << std::flush;
		else if (i > 1000)
			std::cout << "Error: too large a number.\n" << std::flush;
		else{
			std::cout << ("Error: bad input => " + date + '\n') << std::flush;
		}
		return (false);
	}
	return (true);
}

bool BitcoinExchange::checkdate(const std::string &line)
{
	if (line.length() != 10)
		return (false);
	if (line.at(4) != '-' || line.at(7) != '-')
		return (false);
	std::string year = line.substr(0, 4);
	std::string month = line.substr(5, 2);
	std::string date = line.substr(8, 2);
	
	for (std::string::iterator c = year.begin(); c < year.end(); ++c) if (!isdigit(*c)) return false;
	for (std::string::iterator c = month.begin(); c < month.end(); ++c) if (!isdigit(*c)) return false;
	for (std::string::iterator c = date.begin(); c < date.end(); ++c) if (!isdigit(*c)) return false;

	int monthi = atoi(month.c_str());
	if (monthi < 1 || monthi > 12)
		return (false);
	int datei = atoi(date.c_str());
	if (datei < 1 || datei > 31)
		return (false);
	return (true);
}
