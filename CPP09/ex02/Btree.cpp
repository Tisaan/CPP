/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btree.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:49:14 by tseche            #+#    #+#             */
/*   Updated: 2026/07/21 17:09:27 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AdjGraph.hpp"

Btree::Btree(const std::vector<size_t> &vect){
	this->root = new Node();
	this->root->parent = NULL;
	if (vect.size() == 0)
	{
		this->root->left = NULL;
		this->root->right = NULL;
		this->root->value = 0;
		this->depth = 0;
		return ;
	}
	else if (vect.size() == 1)
	{
		this->root->value = vect.at(0);
		this->root->right = NULL;
		this->root->left = NULL;
		this->depth == 1;
		return ;
	}
	std::vector<size_t>::const_iterator beg = vect.begin();
	std::vector<size_t>::const_iterator end = vect.end();
	Node *node = this->root;
	++beg;
	for (; beg != end;){
		if (*beg <= *(beg + 1)){
			node->right = new Node(*beg);
			node->right->parent = this->root;
			node->right->left = NULL;
			node->right->right = NULL;

			node->value = *(beg + 1);
		} else {
			node->right = new Node(*(beg + 1));
			node->right->parent = this->root;
			node->right->left = NULL;
			node->right->right = NULL;

			node->value = *beg;
		}
		beg += 2;
		node->left = new Node();
		node = node->getLeft();
	}
	this->depth = vect.size() - 1;
}

Btree::~Btree(){
	if (this->depth == 0 || this->depth == 1)
	{
		delete this->root;
		return ;
	}
	Node *node = getNode(this->depth);
	if (!node)
	{
		std::cout << "|Btree| Error destructor\n" << std::flush;
	}
	for (int i = 0; i < this->depth; i++)
	{
		if (node->getLeft())
			delete node->getLeft();
		if (node->getRight())
			delete node->right;
		node = node->parent;
		if (node == this->root)//early termination isn't supose to append
			return ;
	}
	delete node;
}

inline Node *Btree::getNode(int depth) const noexcept{
	Node *node = this->root;
	for (int i = 0; i < depth; i++)
	{
		if (node->getLeft())
			node = node->getLeft();
		else
			return NULL;
	}
	return node;
}

inline int Btree::getDepth() const noexcept{
	return this->depth;
}