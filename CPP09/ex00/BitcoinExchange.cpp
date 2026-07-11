#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>

BitcoinExchange::BitcoinExchange(){std::cout << "|Bitcoin| default constructor called\n" << std::flush;};

BitcoinExchange::BitcoinExchange(const std::string &s){
	std::cout << "|Bitcoin| string constructor called\n" << std::flush;
	std::fstream file;

	if (s.length() < 4 || s.substr(0) != ".csv")

	file.open(s);
	if (!file.is_open())
		throw std::runtime_error("couldn't open" + s);
	
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

int BitcoinExchange::verify(const std::string &line ){
	int find = line.find('|');
	if (find == std::string::npos || find != 2)
	{
		//error
	}
	else{
		checkdate(line.substr(0, find - 2));
	}
	if (line.at(find - 1) != ' ' || line.at(find + 1) != ' ' || line.length() <= (find + 2))
	{
		// error
	}
	checkvalue(line.substr(find + 2));
}

bool BitcoinExchange::checkvalue(const std::string &line)
{
	int lenght;
	if (lenght = line.length() && lenght > 4)
	{
		// error
	}
	std::istringstream iss(line);
	float num;
	iss >> num;
	if (num > 1000 || num < 0 || (iss.fail() || !iss.eof()))
	{
		// error
	}
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
	
	for (char c: year) if (!isdigit(c)) return false;
	for (char c: month) if (!isdigit(c)) return false;
	for (char c: date) if (!isdigit(c)) return false;

	if (int monthi = atoi(month.c_str()) && monthi < 1 && monthi > 12)
		return (false);
	int datei = atoi(date.c_str());
	return ( datei < 1 && datei > 31);
}
