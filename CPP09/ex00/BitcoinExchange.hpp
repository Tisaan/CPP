
#include <fstream>
#include <iostream>
#include <map>


class BitcoinExchange{

	bool checkdate(const std::string &l);
	bool checkvalue(const std::string &l);
	std::map<std::string, double> th;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &s);
		~BitcoinExchange();

		const BitcoinExchange &operator=(const BitcoinExchange &b);

		int verify(const std::string &);
};