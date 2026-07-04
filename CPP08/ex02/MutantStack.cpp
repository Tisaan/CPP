/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 17:03:45 by tseche            #+#    #+#             */
/*   Updated: 2026/07/04 18:22:43 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &m): std::stack<T>()
{
	std::cout << "|Mutant| copy constructor called\n" << std::flush;
	if (this != &m)
		*this = m;
}

template <typename T> MutantStack<T>::MutantStack(): std::stack<T>(){
	std::cout << "|Mutant| default constructor called\n" << std::flush;
	this->filo = std::stack<T>();
}

template <typename T> const MutantStack<T> &MutantStack<T>::operator=(const MutantStack &m){
	std::cout << "|Mutant| assignment copy constructor called\n" << std::flush;

	this->filo = m.filo;
	return (*this);
};

template <typename T> MutantStack<T>::~MutantStack()
{
	std::cout << "|Mutant| destructor called\n" << std::flush;
}

template <typename T> bool MutantStack<T>::empty() const{
	return this->filo.empty();
}

template <typename T> void MutantStack<T>::pop(){
	return this->filo.pop();
}

template <typename T> void MutantStack<T>::push(const T &o) {
	return this->filo.push();
}

template <typename T> const T &MutantStack<T>::top() const{
	return this->filo.top();
}

template <typename T> size_t MutantStack<T>::size() const{
	return this->filo.size();
}