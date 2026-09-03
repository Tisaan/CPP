/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:24:44 by von               #+#    #+#             */
/*   Updated: 2026/09/02 19:05:11 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(){
	std::string s = "1 34 56 685 978 6 90800";
	PmergeMe vec(0);
	PmergeMe deq(1);
	std::cout << "string:" << s << "\n" << std::flush;
	if (vec.parse(s)){
		//std::cout << vec.get_cont().vect;
		vec.sort();
		Cont &cont = vec.get_cont();
		std::cout << "{";
		for (size_t i = 0; i < cont.vect.size(); i++){
			std::cout << cont.vect[i];
			if (i + 1 < cont.vect.size())
				std::cout << ", ";
			else
				std::cout << "}\n" << std::flush;
		}
	} else {return 1;}
	if (deq.parse(s)){
		deq.sort();
		Cont &cont = deq.get_cont();
		std::cout << "{";
		for (size_t i = 0; i < cont.deq.size(); i++){
			std::cout << cont.deq[i];
			if (i + 1 < cont.deq.size())
				std::cout << ", ";
			else
				std::cout << "}\n" << std::flush;
		}
	} else {return 1;}
}