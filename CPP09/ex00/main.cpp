
#include <iostream>
#include <fstream>
#include <string>


int main(int ac, char **av){
	if (ac != 2)
		return (1);
	std::fstream in;
	in.open(av[1]);
	if (!in.is_open()){
		std::cout << "Couldn't open" << av[1] << "\n" << std::flush;
		return (1);
	}
	std::string line;
	while (std::getline(in, line))
	{
		
	}
}