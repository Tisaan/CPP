/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:14:35 by tseche            #+#    #+#             */
/*   Updated: 2026/06/30 14:17:40 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serailizer::serialize(Data *d){
	return (reinterpret_cast<uintptr_t>(d));
}

Data *Serailizer::deserialize(uintptr_t t)
{
	return (reinterpret_cast<Data *>(t));
}
