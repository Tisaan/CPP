/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:37:43 by tseche            #+#    #+#             */
/*   Updated: 2026/07/01 18:07:02 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::size_t size_t;
typedef std::string string;

template<typename T> class Array{
	T *list;
	size_t length;
	public:
		Array();
		Array(size_t n);
		Array(const Array<T> &a);
		const Array<T> &operator=(const Array<T> &a);
		T &operator[](size_t n);
		size_t size()const;
};

#include "Array.tpp"