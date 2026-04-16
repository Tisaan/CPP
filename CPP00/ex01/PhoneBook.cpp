/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:41:05 by tseche            #+#    #+#             */
/*   Updated: 2026/03/31 15:25:54 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include <iostream>
#include <stdlib.h>
#include <iomanip>

class PhoneBook
{
	private:
		Contact *slot[8];
		int		idx;

	public:
		int	nbr;
		PhoneBook();
		void add(Contact *contact);
		void display(int idx);
		Contact *get(int idx);
		~PhoneBook();
};

PhoneBook::PhoneBook(){
	this->idx = 0;
	this->nbr = 0;
	for (int i = 0; i < 8; i++)
		this->slot[i] = NULL;
};

void PhoneBook::add(Contact *contact)
{
	this->slot[this->idx] = contact;
	this->idx++;
}

Contact *PhoneBook::get(int idx)
{
	return (this->slot[idx]);
}

void PhoneBook::display(int idx)
{
	Contact *c = this->slot[idx];
	std::cout << '|' << std::setw(10) << ((c->name.length() <= 10) ? c->name : (c->name.substr(0, 9) + "."));
	std::cout << std::flush;
	std::cout << '|' << std::setw(10) << ((c->surname.length() <= 10) ? c->surname : (c->surname.substr(0, 9) + "."));
	std::cout << std::flush;
	std::cout << '|' << std::setw(10) << ((c->nickname.length() <= 10) ? c->nickname : (c->nickname.substr(0, 9) + "."));
	std::cout << std::flush;
	std::cout << '|' << std::setw(10) << ((c->phone.length() <= 10) ? c->phone : (c->phone.substr(0, 9) + "."));
	std::cout << std::flush;
	std::cout << '|' << std::setw(10) << ((c->secret.length() <= 10) ? c->secret : (c->secret.substr(0, 9) + "."));
	std::cout << "|" << std::flush;
}

PhoneBook::~PhoneBook(){
	for (int i = 0; i < 8; i++)
		delete this->slot[i];
}