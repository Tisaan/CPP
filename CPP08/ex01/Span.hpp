/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:46:23 by tseche            #+#    #+#             */
/*   Updated: 2026/07/03 19:09:02 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <ctype.h>

typedef std::size_t size_t;

class Span{
	size_t *GArray;
	size_t idx;
	size_t max;
	public:
		Span();
		Span(const Span &s);
		Span(size_t n);
		~Span();
		const Span &operator=(const Span &s);
		void addNumber(size_t n);
		size_t shortestSpan();
		size_t longestSpan();
};