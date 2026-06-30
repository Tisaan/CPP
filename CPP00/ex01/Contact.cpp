/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:31:05 by tseche            #+#    #+#             */
/*   Updated: 2026/06/29 18:34:01 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <iostream>

#include "Contact.hpp"

Contact::Contact(){};

Contact::Contact(
	std::string name,
	std::string surname,
	std::string nickname,
	std::string phone,
	std::string secret
): name(""), surname(""), nickname(""), phone(""), secret(""){
		this->name = name;
		this->surname = surname;
		this->nickname = nickname;
		this->phone = phone;
		this->secret = secret;
};

Contact::~Contact(){};

std::ostream &operator<<(std::ostream &o, const Contact &c)
{
	o << "|" << std::setw(10) << ((c.name.length() <= 10) ? c.name : (c.name.substr(0, 9) + "."));
	o << std::flush;
	o << std::string("|") << std::setw(10) << ((c.surname.length() <= 10) ? c.surname : (c.surname.substr(0, 9) + "."));
	o << std::flush;
	o << std::string("|") << std::setw(10) << ((c.nickname.length() <= 10) ? c.nickname : (c.nickname.substr(0, 9) + "."));
	o << std::flush;
	o << std::string("|") << std::setw(10) << ((c.phone.length() <= 10) ? c.phone : (c.phone.substr(0, 9) + "."));
	o << std::flush;
	o << std::string("|") << std::setw(10) << ((c.secret.length() <= 10) ? c.secret : (c.secret.substr(0, 9) + "."));
	o << std::string("|") << std::flush;
	return (o);
}