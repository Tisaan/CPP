/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:44:45 by tseche            #+#    #+#             */
/*   Updated: 2026/07/03 13:19:18 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <algorithm>
#include <stdexcept>
#include <limits>


template <typename T> int easyfind(T &list, int needle)
{
	typename T::iterator it = std::find(list.begin(), list.end(), needle);
	if (*it == needle)
		return (*it);
	return __INT32_MAX__;
}