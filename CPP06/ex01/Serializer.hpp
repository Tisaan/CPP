/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:09:15 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:13:49 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"

#include <stdint.h>

class Serializer{
	public:
		Serializer();
		Serializer(const Serializer &s);
		Serializer &operator=(const Serializer &s);
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t p);
};
