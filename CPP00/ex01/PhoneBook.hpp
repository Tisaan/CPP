/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:47:37 by tseche            #+#    #+#             */
/*   Updated: 2026/02/03 17:01:51 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Contact.hpp"

class PhoneBook
{
private:
	Contact slot[8];
	int		idx;
public:
	int nbr;
	PhoneBook();
	void add(Contact *contact);
	void display(int idx);
	Contact *get(int idx);
	~PhoneBook();
};