/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 15:07:17 by tseche            #+#    #+#             */
/*   Updated: 2026/07/04 18:21:57 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <deque>


template <typename T>
class MutantStack: public std::stack<T>{
	std::stack<T> filo;
	public:
		MutantStack();
		MutantStack(const MutantStack &m);
		const MutantStack<T> &operator=(const MutantStack<T> &m);
		~MutantStack();
		const T &top() const;
		bool empty() const;
		size_t size() const;
		void push(const T &o);
		void pop();

		typename std::deque<T>::iterator begin(){
			return (std::stack<T>::c.begin());
		}
		typename std::deque<T>::iterator end(){
			return (std::stack<T>::c.end());
		}
};