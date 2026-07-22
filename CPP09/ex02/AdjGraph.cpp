/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AdjGraph.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:12:03 by tseche            #+#    #+#             */
/*   Updated: 2026/07/21 20:02:54 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AdjGraph.hpp"

AdjGraph::AdjGraph(){
	this->right = NULL;
	this->left = NULL;
	this->inner = NULL;
	this->combine = false;
}

AdjGraph::AdjGraph(const AdjGraph &a)
{
	if (this == &a)
		return ;
	this->right = a.right;
	this->left = a.left;
	this->inner = a.inner;
	this->combine = false;
}

AdjGraph::~AdjGraph(){
	if (!this->combine)
		delete this->inner;
}

AdjGraph &AdjGraph::operator=(const AdjGraph &a){
	if (this == &a)
		return ;
	this->right = a.right;
	this->left = a.left;
	this->inner = a.inner;
	return (*this);
}

bool AdjGraph::operator<=(const AdjGraph *a){
	if (this->getInnerTree()->root->getValue() <= a->getInnerTree()->root->getValue())
		return (true);
	return (false);
}

inline AdjGraph *AdjGraph::getAdjLeft() const noexcept{
	return this->left;
}

inline AdjGraph *AdjGraph::getAdjRight() const noexcept{
	return this->right;
}

inline Btree *AdjGraph::getInnerTree() const noexcept{
	return this->inner;
}


void AdjGraph::setAdjLeft(AdjGraph *a) noexcept{
	this->left = a;
}

void AdjGraph::setAdjRight(AdjGraph *a) noexcept{
	this->right = a;
}

void AdjGraph::swapGraph(AdjGraph &a){
	AdjGraph *aleft = a.getAdjLeft();
	AdjGraph *aright = a.getAdjRight();

	a.setAdjLeft(this->getAdjLeft());
	a.setAdjRight(this->getAdjRight());
	
	this->getAdjLeft()->setAdjRight(&a);
	this->getAdjRight()->setAdjLeft(&a);

	a.getAdjLeft()->setAdjRight(this);
	a.getAdjRight()->setAdjLeft(this);

	this->left = aleft;
	this->right = aright;
}

void AdjGraph::combineGraph(AdjGraph &a) noexcept{

	int depth = this->inner->getDepth();
	Node *node = this->getInnerTree()->getNode(depth);
	if (this <= &a)
	{
		a.combine = true;
		node->left = a.getInnerTree()->root;
		this->getInnerTree()->depth += a.getInnerTree()->getDepth();
		a.getAdjLeft()->setAdjRight(this);
		a.getAdjRight()->setAdjLeft(this);
		delete &a;
	}
	else
	{
		this->combine
	}
}