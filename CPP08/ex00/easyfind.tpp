/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:44:45 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:49:13 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <algorithm>
#include <stdexcept>
#include <climits>


template <typename T> int easyfind(T &list, int needle)
{
	typename T::iterator it = std::find(list.begin(), list.end(), needle);
	if (it != list.end())
		return (*it);
	return INT_MAX;
}