/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brains.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:39:48 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 17:45:08 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brains.hpp"

Brain::Brain(const Brain &b){
	std::cout << "|Brain| copy constructor called\n" <<std::flush;
	if (this != &b)
		*this = b;
}

Brain::Brain(){
	std::cout << "|Brain| default constructor called\n" <<std::flush;
}

Brain::~Brain(){
	std::cout << "|Brain| destructor called\n" <<std::flush;
}

const Brain &Brain::operator=(const Brain &b){
	if (this != &b)
		*this = b;
	return b;
}