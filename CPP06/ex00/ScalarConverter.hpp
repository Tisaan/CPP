/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:08:27 by tseche            #+#    #+#             */
/*   Updated: 2026/08/03 12:45:24 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ScalarConverter{
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &s);
	ScalarConverter &operator=(const ScalarConverter &s);
	public:
		static void convert(std::string &s);
};