/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 21:30:58 by tseche            #+#    #+#             */
/*   Updated: 2026/07/16 15:51:01 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <climits>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): cont(){
	std::cout << "|PmergeMe| default constructor called\n" << std::flush;
}

PmergeMe::PmergeMe(bool type = false): cont(type){
	std::cout << "|PmergeMe| type constructor called\n" << std::flush;
}

PmergeMe::PmergeMe(const PmergeMe &p){
	std::cout << "|PmergeMe| copy constructor called\n" << std::flush;
	if (this != &p)
		*this = p;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &p)
{
	std::cout << "|PmergeMe| copy constructor called\n" << std::flush;
	if (this != &p)
		this->cont = p.cont;
	return (*this);
}

PmergeMe::~PmergeMe(){
	std::cout << "|PmergeMe| destructor called\n" << std::flush;
	cont.~Cont();
}

bool PmergeMe::parse(const std::string &s){
	std::stringstream ss(s);
	std::string tok;
	long num;
	size_t lenght = 0;
	while (getline(ss, tok, ' ')){
		std::istringstream iss(tok);
		iss >> num;
		if (iss.fail() || !iss.eof()){
			std::cout << "ERROR: Fail to convert[" << tok << "] to integer\n" << std::flush;
			return (false);
		}
		if (num < 0){
			std::cout << "ERROR: " << num << " is negative\n" << std::flush;
			return (false);
		} else if (num > INT_MAX){
			std::cout << "ERROR: " << num << " overflow an integer\n" << std::flush;
			return (false);
		} else{
			if (this->cont.type)
				this->cont.deq.push_back(num);
			else
				this->cont.vect.push_back(num);
			lenght++;
		}
	}
	this->cont.lenght = lenght;
	return (true);
}