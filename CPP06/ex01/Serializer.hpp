/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:09:15 by tseche            #+#    #+#             */
/*   Updated: 2026/06/30 14:17:03 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"

#include <cstdint>

class Serailizer{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t p);
};
