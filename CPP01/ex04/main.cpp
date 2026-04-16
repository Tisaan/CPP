/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:32:49 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 19:38:47 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

struct littleTrickCauseWeCouldntUseLambda{
	std::string operator()(
		int pos,
		int lpos,
		std::string line,
		std::string sub,
		std::string rep
	){
		std::string thing;
		while ((pos = line.find(sub, lpos)) != -1)
		{
			thing.append(line.substr(lpos, pos - lpos));
			thing.append(rep);
			lpos = pos + sub.length();
		}
		thing.append(line.substr(lpos));
		return thing;
	}
};

int main(int ac, char **av){
	if (ac != 4)
	{
		std::cout << "./sed [filename] [haystack] [needle]\n" << std::flush;
		return (1);
	}

	std::fstream in;
	in.open(av[1]);
	if (!in.is_open())
	{
		std::cout << "couldn't open file";
		return 1;
	}

	std::string out = std::string(av[1]) + ".replace";
	std::ofstream outfile(out.c_str());
	if (!outfile.is_open()){
		std::cout << "couldn't create output file\n" << std::flush;
		in.close();
		return 1;
	}
	std::string sub = std::string(av[2]);
	if (sub.empty())
	{
		outfile.close();
		in.close();
		return 1;
	}
	std::string line;
	std::string rep = av[3];
	littleTrickCauseWeCouldntUseLambda lambda;
	while (std::getline(in, line)){
		int lpos = 0;
		int pos = 0;
		
		outfile << (line.find(sub, lpos) != -1 ? lambda(pos, lpos, line, sub, rep) : line) + "\n";
	}
	in.close();
	outfile.close();
	return (0);
}