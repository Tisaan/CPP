/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AdjGraph.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:42:42 by tseche            #+#    #+#             */
/*   Updated: 2026/07/21 17:08:55 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

struct Node{
	Node *parent;
	Node *right;
	Node *left;
	size_t value;

	Node(size_t n) noexcept;
	Node();

	inline size_t getValue() const noexcept;
	inline Node *getRight() const noexcept;
	inline Node *getLeft() const noexcept;
	inline bool haschild() const noexcept;
	inline bool hasParent() const noexcept;
};

struct Btree{
	Node *root;
	size_t depth;
	
	Btree(const std::vector<size_t> &vect);
	~Btree();

	inline Node *getNode(int depth) const noexcept;
	inline int getDepth() const noexcept;
};

class AdjGraph{
	AdjGraph *right;
	AdjGraph *left;
	Btree *inner;
	bool combine;
	
	public:
		AdjGraph();
		AdjGraph(const AdjGraph &a);
		~AdjGraph();
		
		AdjGraph &operator=(const AdjGraph &a);
		bool operator<=(const AdjGraph *a);
		
		inline AdjGraph *getAdjRight() const noexcept;
		inline AdjGraph *getAdjLeft() const noexcept;
		inline Btree *getInnerTree() const noexcept;

		inline void setAdjLeft(AdjGraph *a) noexcept;
		inline void setAdjRight(AdjGraph *a) noexcept;
		
		void swapGraph(AdjGraph &a) noexcept;
		void combineGraph(AdjGraph &a) noexcept;
		AdjGraph &combineRight(AdjGraph &a);
		AdjGraph &combineLeft(AdjGraph &a);
};

bool InsertLeftoverGraph(const std::vector<AdjGraph *> &vect);

std::vector<size_t> &RecombineOutput(const std::vector<AdjGraph *> &vect);
