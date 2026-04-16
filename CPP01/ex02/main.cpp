/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:10:52 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 17:16:51 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = *stringPTR;

	std::cout << "[mem]|var|" << &var << "\n" << std::flush;
	std::cout << "[mem]|stringPTR|" << stringPTR << "\n" << std::flush;
	std::cout << "[mem]|stringREF|" << &stringREF << "\n" << std::flush;

	std::cout << "[val]|var|" << var << "\n" << std::flush;
	std::cout << "[val]|stringPTR|" << *stringPTR << "\n" << std::flush;
	std::cout << "[val]|stringREF|" << stringREF << "\n" << std::flush;
}