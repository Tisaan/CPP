/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 21:26:15 by tseche            #+#    #+#             */
/*   Updated: 2026/09/16 18:25:18 by tseche           ###   ########.fr       */
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
	}
	~Cont(){
	}
};

class PmergeMe{
	Cont cont;
	std::vector<size_t> gen_jacobsthal(std::vector<size_t> &nvec, size_t max);
	template <typename T> void sort(size_t lvl, T &main, std::vector<size_t> jacob);
	public:
		PmergeMe();
		PmergeMe(bool type = false);
		PmergeMe(const PmergeMe &p);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &p);
	
		bool parse(const std::string &s);
		void sortchoice();
		Cont &get_cont();
};