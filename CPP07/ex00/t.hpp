/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:06:11 by tseche            #+#    #+#             */
/*   Updated: 2026/07/01 14:13:33 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> T max(T &a, T &b){ return a > b ? a : b;};

template <typename T> T min(T &a, T &b){ return a < b ? a : b;};

template <typename T> void swap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
};