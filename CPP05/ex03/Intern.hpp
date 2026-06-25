/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:18:07 by tseche            #+#    #+#             */
/*   Updated: 2026/06/25 13:28:12 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern& other);
		Intern(const std::string &name, int grade, int exec);
		~Intern();

		const Intern& operator=(const Intern& other);

		AForm *makeForm(const std::string &n, const std::string &t);
};