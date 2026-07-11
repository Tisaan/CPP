/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brains.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:39:48 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 15:15:46 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brains.hpp"

Brain::Brain(const Brain &b){
	std::cout << "|Brain| copy constructor called\n" <<std::flush;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
}

Brain::Brain(){
	std::cout << "|Brain| default constructor called\n" <<std::flush;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::~Brain(){
	std::cout << "|Brain| destructor called\n" <<std::flush;
}

const Brain &Brain::operator=(const Brain &b){
	if (this == &b)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	return (*this);
}