/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:47:37 by tseche            #+#    #+#             */
/*   Updated: 2026/06/29 18:51:56 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Contact.hpp"

class PhoneBook
{
private:
	Contact slot[8];
public:
	int nbr;
	int save;
	int		idx;
	PhoneBook();
	void add(const Contact &contact);
	const Contact *get(int idx) const;
};