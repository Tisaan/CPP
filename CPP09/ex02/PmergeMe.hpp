/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 21:26:15 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 22:18:34 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>

struct Cont{
	bool type;
	size_t lenght;
	union{
		std::vector<size_t> vect;
		std::deque<size_t> deq;
	};

	Cont(bool ctype = false): type(ctype){
		std::cout << "|Stuct Cont| constructor called\n" << std::flush;
		if (!type)
			new (&vect) std::vector<size_t>();
		else
			new (&deq) std::deque<size_t>();
	}
	~Cont(){
		std::cout << "|Stuct Cont| destructor called\n" << std::flush;
		if (type) vect.~vector();
		else deq.~deque();
	}
	Cont &operator=(const Cont &c)
	{
		std::cout << "|Stuct Cont| copy assignment operator called\n" << std::flush;
		this->type = c.type;
		if (this->type)
			this->deq = c.deq;
		else
			this->vect = c.vect;
		return (*this);
	}
};

class PmergeMe{
	Cont cont;
	public:
		PmergeMe();
		PmergeMe(bool type = false);
		PmergeMe(const PmergeMe &p);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &p);
	
		bool parse(const std::string &s);
};