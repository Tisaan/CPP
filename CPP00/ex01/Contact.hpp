/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:41:21 by tseche            #+#    #+#             */
/*   Updated: 2026/03/31 14:31:31 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iosfwd>

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