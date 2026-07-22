/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:44:40 by tseche            #+#    #+#             */
/*   Updated: 2026/07/20 18:50:59 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AdjGraph.hpp"

Node::Node(size_t n) noexcept{
	this->value = n;
}

Node::Node(){}

inline size_t Node::getValue() const noexcept{
	return this->value;
}

inline bool Node::haschild() const noexcept{
	return (this->left || this->right);
}

inline Node *Node::getRight() const noexcept{
	return (this->right);
}

inline Node *Node::getLeft() const noexcept{
	return (this->left);
}

inline bool Node::hasParent() const noexcept{
	if (this->parent)
		return (true);
	return (false);
}