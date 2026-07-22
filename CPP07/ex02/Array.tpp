/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:13:30 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:39:07 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template<typename T> Array<T>::Array(size_t n): length(n){
	std::cout  << "lenght constructor called.\n" << std::flush;
	this->list = new T[n];
	for (size_t i = 0; i < this->length; i++)
		list[i] = 0;
};

template<typename T> Array<T>::Array(const Array<T> &a): length(0){
	std::cout  << "copy constructor called.\n" << std::flush;
	this->list = new T[this->length];
	for (size_t i = 0; i < this->length; i++)
		this->list = 0;
	*this = a;
}

template<typename T> Array<T>::Array(): list(0), length(0)
{
	std::cout  << "Default constructor called.\n" << std::flush;
}

template<typename T> Array<T>::~Array()
{
	std::cout  << "Destructor called.\n" << std::flush;
	delete[] this->list;
}

template<typename T> const Array<T> & Array<T>::operator=(const Array<T> &a){
	std::cout  << "assignment constructor called.\n" << std::flush;
	this->length = a.length;
	this->list = new T[this->length];
	for (size_t i = 0; i < this->length; i++)
		this->list[i] = a.list[i];
	return (*this);
}

template<typename T> T &Array<T>::operator[](size_t i){
	if (i >= this->length)
		throw std::exception();
	return (this->list[i]);
}

template <typename T> size_t Array<T>::size()const{
	return (this->length);
}