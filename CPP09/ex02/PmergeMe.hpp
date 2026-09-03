/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 21:26:15 by tseche            #+#    #+#             */
/*   Updated: 2026/09/02 19:01:11 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>

struct Cont{
	bool type;
	std::vector<size_t> vect;
	std::deque<size_t> deq;

	Cont(bool ctype = false): type(ctype), vect(), deq(){
		std::cout << "|Stuct Cont| constructor called\n" << std::flush;
	}
	~Cont(){
		std::cout << "|Stuct Cont| destructor called\n" << std::flush;
	}
};

class PmergeMe{
	Cont cont;
	void sortvect();
	void sortdeq();
	public:
		PmergeMe();
		PmergeMe(bool type = false);
		PmergeMe(const PmergeMe &p);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &p);
	
		bool parse(const std::string &s);
		void sort();
		std::vector<size_t>::iterator lowerbound(std::vector<size_t>::iterator first, std::vector<size_t>::iterator last, size_t val, size_t step);
		std::deque<size_t>::iterator lowerbound(std::deque<size_t>::iterator first, std::deque<size_t>::iterator last, size_t val, size_t step);
		Cont &get_cont();
};