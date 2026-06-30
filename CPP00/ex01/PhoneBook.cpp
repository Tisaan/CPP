/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:41:05 by tseche            #+#    #+#             */
/*   Updated: 2026/06/29 18:52:02 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->idx = 0;
	this->nbr = 0;
	this->save = 0;
}

void PhoneBook::add(const Contact &contact)
{
	this->slot[this->idx] = contact;
	this->idx++;
	this->save++;
}

const Contact *PhoneBook::get(int idx) const
{
	if (idx < 0 || idx >= nbr)
		return NULL;
	return (&this->slot[idx]);
}