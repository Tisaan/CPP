/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:31:05 by tseche            #+#    #+#             */
/*   Updated: 2026/02/04 16:52:19 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
private:
public:
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone;
	std::string secret;
	Contact(std::string name, std::string surname, std::string nickname, std::string phone, std::string secret);
	~Contact();
};

Contact::Contact(
	std::string name,
	std::string surname,
	std::string nickname,
	std::string phone,
	std::string secret
){
		this->name = name;
		this->surname = surname;
		this->nickname = nickname;
		this->phone = phone;
		this->secret = secret;
};

Contact::~Contact(){};

