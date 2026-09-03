/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 21:30:58 by tseche            #+#    #+#             */
/*   Updated: 2026/09/02 19:08:18 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <climits>
#include "PmergeMe.hpp"
#include <immintrin.h>

PmergeMe::PmergeMe(): cont(){
	std::cout << "|PmergeMe| default constructor called\n" << std::flush;
}

PmergeMe::PmergeMe(bool type): cont(type){
	std::cout << "|PmergeMe| type constructor called\n" << std::flush;
}

PmergeMe::PmergeMe(const PmergeMe &p){
	std::cout << "|PmergeMe| copy constructor called\n" << std::flush;
	if (this != &p)
		*this = p;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &p)
{
	std::cout << "|PmergeMe| copy constructor called\n" << std::flush;
	if (this != &p)
		this->cont = p.cont;
	return (*this);
}

PmergeMe::~PmergeMe(){
	std::cout << "|PmergeMe| destructor called\n" << std::flush;
}

Cont &PmergeMe::get_cont(){return this->cont;}

bool PmergeMe::parse(const std::string &s){
	std::stringstream ss(s);
	std::string tok;
	long num;
	while (getline(ss, tok, ' ')){
		std::istringstream iss(tok);
		iss >> num;
		if (iss.fail() || !iss.eof()){
			std::cout << "ERROR: Fail to convert[" << tok << "] to integer\n" << std::flush;
			return (false);
		}
		if (num < 0){
			std::cout << "ERROR: " << num << " is negative\n" << std::flush;
			return (false);
		} else if (num > INT_MAX){
			std::cout << "ERROR: " << num << " overflow an integer\n" << std::flush;
			return (false);
		} else{
			if (this->cont.type)
				this->cont.deq.push_back(num);
			else
				this->cont.vect.push_back(num);
		}
	}
	return (true);
}

inline std::vector<size_t> gen_jacobsthal(int len){
	std::vector<size_t> vec;
	if (len == 0)
		vec.push_back(0);
	else if (len == 1)
		vec.push_back(0);
	if (len < 2)
		return vec;
	size_t j0 = 0;
	size_t j1 = 1;
	for (int i = 2; i < len; i++){
		size_t jn = j1 + 2 * j0;
		j0 = j1;
		j1 = jn;
		vec.push_back(jn);
	}
	return (vec);
}

void PmergeMe::sort(){
	if (this->cont.type)
		return sortdeq();
	else 
		return sortvect();
}

void swap(std::vector<size_t> &vec, size_t group_size, size_t size)
{
	for (size_t i = group_size - 1; i < size; i += (group_size / 2)){
		if (vec[i] < vec[i -(group_size / 2)]){
			size_t i = 0;
			for (; i < group_size / 2 && i + 4 < group_size / 2; i += 4){
				__m256i vector = _mm256_loadu_si256(reinterpret_cast<__m256i*>(&vec[i]));
				__m256i swapped = _mm256_shuffle_epi32(vector, 0xB1);
				_mm256_storeu_si256(reinterpret_cast<__m256i*>(&vec[i]), swapped);
			}
			for (; i + 1 < size; i+=2){
				size_t temp = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = temp;
			}
		}
	}
}

void swap(std::deque<size_t> &vec, size_t group_size, size_t size)
{
	for (size_t i = group_size - 1; i < size; i += (group_size / 2)){
		if (vec[i] < vec[i - (group_size / 2)]){
			// for (; i < group_size / 2 && i + 4 < group_size / 2; i += 4){
			// 	__m256i vector = _mm256_loadu_si256(reinterpret_cast<__m256i*>(&vec[i]));
			// 	__m256i swapped = _mm256_shuffle_epi32(vector, 0xB1);
			// 	_mm256_storeu_si256(reinterpret_cast<__m256i*>(&vec[i]), swapped);
			// }
			for (size_t i = 0; i + 1 < size; i++){
				size_t temp = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = temp;
			}
		}
	}
}

std::vector<size_t>::iterator PmergeMe::lowerbound(std::vector<size_t>::iterator first, std::vector<size_t>::iterator last, size_t val, size_t step){
	std::iterator_traits<std::vector<size_t>::iterator>::difference_type distance = std::distance(first, last);
	std::vector<size_t>::iterator cpy;
	
	while (distance > 0){
		cpy = first;
		//it += (distance / 2) * (step * 2 - 1);
		// couldn't do it cause not sure if std::Container<T>::Allocator is continuous in memory
		std::advance(cpy, (distance / 2) * (step * 2 - 1));
		if (*cpy < val){
			distance -= (distance / 2) + 1;// skip half
			first = ++cpy;
		}
		else
			distance = (distance / 2);
	}
	return (first);
}

std::deque<size_t>::iterator PmergeMe::lowerbound(std::deque<size_t>::iterator first, std::deque<size_t>::iterator last, size_t val, size_t step){
	std::iterator_traits<std::deque<size_t>::iterator>::difference_type distance = std::distance(first, last);
	std::deque<size_t>::iterator cpy;
	
	while (distance > 0){
		cpy = first;
		//it += (distance / 2) * (step * 2 - 1);
		// couldn't do it cause not sure if std::Container<T>::Allocator is continuous in memory
		std::advance(cpy, (distance / 2) * (step * 2 - 1));
		if (*cpy < val){
			distance -= (distance / 2) + 1;// skip half
			first = ++cpy;
		}
		else
			distance = (distance / 2);
	}
	return (first);
}

void PmergeMe::sortvect(){
	static std::vector<size_t> vec = this->cont.vect;
	static const std::vector<size_t> jacob = gen_jacobsthal(vec.size());
	static size_t group_size = 2;
	
	if (group_size * 2 > vec.size())
		return ;
	swap(vec, group_size, vec.size());
	
	group_size <<= 1;// * 2
	sortvect();// increment just so that the recursive call produce bigger groups
	group_size >>= 1;// / 2
	if (vec.size() / (group_size / 2) < 3)
		return ;
	std::vector<size_t> newvec;
	newvec.resize(vec.size());
	// add first pair
	newvec.insert(newvec.begin(), group_size);
	vec.erase(vec.begin(), vec.begin() + group_size);
	int i = 1;
	std::vector<size_t>::iterator begin_new = newvec.begin();
	for (std::vector<size_t>::iterator it = vec.begin() + group_size; group_size * i <= vec.size(); it += group_size, i++){// append the winner
		newvec.insert(newvec.end(), it, it + group_size);
		vec.erase(it, it + group_size);
	};
	i = 0;
	std::vector<size_t>::const_iterator begin = jacob.begin() + 2;
	std::vector<size_t>::const_iterator end = jacob.begin() + 2;
	for (size_t pos = 1; pos * group_size <= vec.size();){
		size_t range = (group_size / 2) * (pos + 1 + i);
		newvec.insert(
			lowerbound(begin_new, vec.begin() + range,
				*(begin_new + pos * (group_size / 2) - 1), group_size / 2),
			begin_new + (group_size / 2 * pos - group_size / 2),
			begin_new + (group_size * pos)
		);
		i++;
		pos--;
		if (pos <= *end){
			pos = *begin;
			end = begin;
			begin++;
		}
		while (pos * (group_size / 2) > vec.size() && pos >= *end && pos--);
		if (pos <= *end)
			break;
	}
	vec.erase(vec.begin(), vec.begin() + (i * group_size / 2));
	for (size_t i = 0; i < vec.size(); i++){
		newvec.push_back(vec[i]);
	}
	this->cont.vect = newvec;
}

void PmergeMe::sortdeq(){
	static std::deque<size_t> deq = this->cont.deq;
	static const std::vector<size_t> jacob = gen_jacobsthal(deq.size());
	static size_t group_size = 2;
	
	if (group_size * 2 > deq.size())
		return ;
	swap(deq, group_size, deq.size());
	
	group_size <<= 1;// * 2
	sortdeq();// increment just so that the recursive call produce bigger groups
	group_size >>= 1;// / 2
	
	std::deque<size_t> newdeq;
	for (size_t i = 0; i < group_size; i++)// add first pair
		newdeq[i] = deq[i];
	deq.erase(deq.begin(), deq.begin() + group_size);
	int i = 1;
	std::deque<size_t>::iterator begin_new = newdeq.begin();
	for (std::deque<size_t>::iterator it = deq.begin() + group_size; group_size * i <= deq.size(); it += group_size, i++){// append the winner
		newdeq.insert(newdeq.end(), it, it + group_size);
		deq.erase(it, it + group_size);
	};
	i = 0;
	std::vector<size_t>::const_iterator begin = jacob.begin() + 2;
	std::vector<size_t>::const_iterator end = jacob.begin() + 2;
	for (size_t pos = 1; pos * group_size <= deq.size();){
		size_t range = (group_size / 2) * (pos + 1 + i);
		newdeq.insert(lowerbound(begin_new, deq.begin() + range, *(begin_new + pos * (group_size / 2) - 1), static_cast<size_t>(group_size / 2)), begin_new + (group_size / 2 * pos - group_size / 2), begin_new + (group_size * pos));//yeepi profite bien de cette super ligne
		i++;
		pos--;
		if (pos <= *end){
			pos = *begin;
			end = begin;
			begin++;
			
		}
		while (pos * (group_size / 2) > deq.size() && pos >= *end && pos--);
		if (pos <= *end)
			break;
	}
	deq.erase(deq.begin(), deq.begin() + (i * group_size / 2));
	for (size_t i = 0; i < deq.size(); i++){
		newdeq.push_back(deq[i]);
	}
	this->cont.deq = newdeq;
}