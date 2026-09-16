/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:24:44 by von               #+#    #+#             */
/*   Updated: 2026/09/16 19:01:07 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <typeinfo>
#include <cstdlib>

void print(Cont cont, bool flag){
	if (flag)
		std::cout << "before: {";
	else
		std::cout << "after: {";
 	for (size_t i = 0; i < cont.vect.size(); i++){
		std::cout << cont.vect[i];
		if (i + 1 < cont.vect.size())
 			std::cout << ", ";
 	}
 	std::cout << "}\n" << std::flush;
}

int main(int ac, char **av){
	if (ac == 1)
	{
		std::cout << "Usage: ./PermergeMe ([(1-9)+ ])+ \n" << std::flush;
		return 1;
	}
	std::string s;
	for (int i = 1; i < ac; i++){
		s.append(av[i]).append(" ");	
	}

	PmergeMe vec(0);
	vec.parse(s);

	Cont contv = vec.get_cont();
	print(contv, 0);

	clock_t startv = clock();
	vec.sortchoice();
	clock_t endvc = clock();
	print(contv, 1);
	
	double elapsedv = startv - endvc / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << contv.vect.size()
			  << " elements with " << std::flush;
	std::string mang = typeid(contv.vect).name();
	std::system(("c++filt -t " + mang + " | tr -d '\\n'").data());
	std::cout << " in " << elapsedv << " us" << std::endl;

	PmergeMe deq(1);
	deq.parse(s);

	Cont contdeq = deq.get_cont();

	clock_t startdeq = clock();
	deq.sortchoice();
	clock_t enddeq = clock();
	
	double elapseddeq = startdeq - enddeq / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << contdeq.deq.size()
			  << " elements with " << std::flush;
	mang = typeid(contdeq.deq).name();
	std::system(("c++filt -t " + mang + " | tr -d '\\n'").data());
	std::cout << " in " << elapseddeq << " us" << std::endl;
}
