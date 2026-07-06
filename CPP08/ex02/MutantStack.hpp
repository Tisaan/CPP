/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 15:07:17 by tseche            #+#    #+#             */
/*   Updated: 2026/07/06 12:30:52 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <deque>


template <typename T, typename Cont = std::deque<T>>
class MutantStack: public std::stack<T, Cont>{
	public:
		MutantStack(){
			std::cout << "|Mutant| default constructor called\n" << std::flush;
		}
		MutantStack(const MutantStack &m){
				std::cout << "|Mutant| copy constructor called\n" << std::flush;
				if (this != &m)
					*this = m;
		}
		const MutantStack<T, Cont> &operator=(const MutantStack<T, Cont> &m){
			std::cout << "|Mutant| assignment copy constructor called\n" << std::flush;
			if (this == &m)
				return *this;
			std::stack<T, Cont>::operator=(m);
			return (*this);
		}
		~MutantStack(){std::cout << "|Mutant| destructor called\n" << std::flush;
		}
		typename std::deque<T, Cont>::iterator begin(){
			return (this->c.begin());
		}

		typename std::deque<T, Cont>::iterator end(){
			return (this->c.end());
		}

		typename std::deque<T, Cont>::const_iterator begin() const{
			return (this->c.begin());
		}

		typename std::deque<T, Cont>::const_iterator end() const {
			return (this->c.end());
		}
};