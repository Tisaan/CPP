/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brains.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:25:03 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 16:44:14 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain{
	public:
		std::string ideas[100];
		Brain();
		Brain(const Brain &b);
		~Brain();

		const Brain &operator=(const Brain &b);
};

