/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:14:35 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:13:06 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::~Serializer(void) {}

Serializer::Serializer(const Serializer &cpy) { (void)cpy;}

Serializer	&Serializer::operator=(const Serializer &src) {(void)src; return *this;}

uintptr_t Serializer::serialize(Data *d){
	return (reinterpret_cast<uintptr_t>(d));
}

Data *Serializer::deserialize(uintptr_t t)
{
	return (reinterpret_cast<Data *>(t));
}
