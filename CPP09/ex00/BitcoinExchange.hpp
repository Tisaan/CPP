
#include <fstream>
#include <iostream>
#include <map>


class BitcoinExchange{

	bool checkdate(const std::string &l);
	bool checkvalue(const std::string &l, float &value, const std::string &date);
	std::map<std::string, double> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &s);
		~BitcoinExchange();

		const BitcoinExchange &operator=(const BitcoinExchange &b);

		int verify(const std::string &);
		float getValue(const std::string &key);
};