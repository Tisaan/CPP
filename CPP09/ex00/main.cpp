
#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	if (ac != 2)
	{
		std::cout << "Error: could not open file.\n" << std::flush;
		return (1);
	}
	try {
		BitcoinExchange btc("data.csv");

		std::fstream file;
		file.open(av[1]);
		if (!file.is_open())
			throw std::runtime_error("couldn't open" + std::string(av[1]) + '\n');
		std::string line;
		getline(file, line);// skip first line who's description the data
		while (getline(file, line))
			btc.verify(line);
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::flush;
		return (1);
	}
}