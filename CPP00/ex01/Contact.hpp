/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:41:21 by tseche            #+#    #+#             */
/*   Updated: 2026/06/29 17:48:19 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iosfwd>

class Contact
{
public:
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone;
	std::string secret;
	Contact(std::string name, std::string surname, std::string nickname, std::string phone, std::string secret);
	Contact();
	~Contact();
};

std::ostream &operator<<(std::ostream &o, const Contact &c);