/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:51:45 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:57:32 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <vector>
#include <climits>
#include <stdlib.h>


Span::Span(): idx(0), max(0){
	std::cout << "|Span| default constructor called\n" << std::flush;
	this->GArray = new size_t[0];
}

Span::Span(const Span&s): idx(0), max(s.max) {
	std::cout << "|Span| Copy constructor called\n" << std::flush;
	if (this != &s)
	{
		this->GArray = new size_t[max];
		for (size_t i = 0; i < idx; i++)
			this->GArray[i] = s.GArray[i];
		for (size_t i = this->idx; i < max; i++)
			this->GArray[i] = 0;
	}
}

Span::Span(size_t n): idx(0), max(n){
	std::cout << "|Span| Size constructor called\n" << std::flush;
	this->GArray = new size_t[n];
}

Span::~Span(){
	std::cout << "|Span| destructor called\n" << std::flush;
	if (!this->GArray)
		return ;
	delete[] this->GArray;
	this->GArray = NULL;
}

const Span &Span::operator=(const Span &s)
{
	this->idx = s.idx;
	this->GArray = s.GArray;
	this->max = s.max;
	return (*this);
}

void Span::addNumber(size_t n)
{
	if (this->idx == this->max)
		throw std::runtime_error("Type Error: try to add more item than possible to hold for type Span");
	this->GArray[this->idx++] = n;
}

size_t Span::longestSpan(){
	if (this->idx == 0 || this->idx == 1)
		throw std::runtime_error("Type Error: method longestSpan couldn't work on lesser than 2 lenght Span");
	size_t max = 0;
	size_t min = UINT_MAX;
	for (size_t i = 0; i < this->idx - 1; i++)
	{
		size_t t = this->GArray[i];
		if (t > max)
			max = t;
		else if (t < min)
			min = t;
	}
	return (max - min);
}


size_t Span::shortestSpan(){
	if (this->idx == 0 || this->idx == 1)
		throw std::runtime_error("Type Error: method longestSpan couldn't work on lesser than 2 lenght Span");
	
	size_t *tmp = this->GArray;
	std::sort(tmp, tmp + this->idx);
	size_t min = UINT_MAX;
	for (size_t i = 1; i < this->idx; i++)
	{
		size_t cur = tmp[i] - tmp[i - 1];
		if (cur < min)
			min = cur;
		if (min == 0)
			return 0;
	}
	return (min);
}

