/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 21:30:58 by tseche            #+#    #+#             */
/*   Updated: 2026/09/16 18:25:13 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <climits>
#include "PmergeMe.hpp"
#include <immintrin.h>

PmergeMe::PmergeMe(): cont(){
}

PmergeMe::PmergeMe(bool type): cont(type){
}

PmergeMe::PmergeMe(const PmergeMe &p){
	if (this != &p)
		*this = p;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &p)
{
	if (this != &p)
		this->cont = p.cont;
	return (*this);
}

PmergeMe::~PmergeMe(){
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

std::vector<size_t> PmergeMe::gen_jacobsthal(std::vector<size_t> &nvec, size_t len){
	std::vector<size_t> vec;
	if (len <= 0)
		return vec;
	vec.push_back(0);
	vec.push_back(0);
	size_t j0 = 0;
	size_t j1 = 1;
	while (true){
		size_t jn = j1 + (2 * j0);
		if (jn < len)
			break;
		j0 = j1;
		j1 = jn;
		if (jn != vec.back())
			vec.push_back(jn);
	}
	size_t prev = 1;
	for (size_t i = 1; i < vec.size(); ++i){
		int current = vec[i];
		for (size_t b = current; b > prev; --b)
			nvec.push_back(b - 1);
		prev = current;
	}
	for (size_t b = len; b > prev; --b)
		nvec.push_back(b - 1);
	return (nvec);
}

void PmergeMe::sortchoice(){
	
	std::vector<size_t> jacob;
	this->gen_jacobsthal(jacob, this->cont.type ? this->cont.deq.size() : this->cont.vect.size());
	if (this->cont.type){
		if (this->cont.deq.size() == 1)
			return ;
		sort(1, this->cont.deq, jacob);	
	}
	else
	{
		if (this->cont.vect.size() == 1)
			return ;
		sort(1, this->cont.vect,jacob);
	}
}	

template <typename T>
void swap(size_t lvl, T &main){
	size_t n = main.size();
	for (size_t i = 0; i < n / (lvl * 2); i++){
		size_t lstart = lvl * 2 * i;
		size_t rstart = (i * 2 + 1) * lvl;
		size_t lend = rstart - 1;
		size_t rend = (2 * i + 2) * lvl - 1;
		if (main[lend] > main[rend])
			std::swap_ranges(main.begin() + lstart, main.begin() + rstart, main.begin() + rstart);
	}
}

template <typename T>
void split(size_t lvl, T &main,T &winner, T &loser, T &left){
	size_t n = main.size();
	for (size_t i = 0; i < n / (lvl * 2); i++){
		size_t lstart = lvl * 2 * i;
		size_t rstart = (i * 2 + 1) * lvl;
		size_t rend = (2 * i + 2) * lvl;
		loser.insert(loser.end(), main.begin() + lstart, main.begin() + rstart);
		winner.insert(winner.end(), main.begin() + rstart, main.begin() + rend);
	}
	if ((main.size() % (lvl * 2)) != 0){
		size_t leftover = (n / (lvl * 2)) * 2 * lvl;
		left.assign(main.begin() + leftover, main.end());
	}
}

template <typename T>
size_t bs(T main, int lvl, size_t loser, size_t high){
	size_t low = 0;
	while (low < high){
		size_t mid = low + (high - low) / 2;
		size_t target = main[(mid + 1) * lvl - 1];
		if (target < loser)
			low = mid + 1;
		else
			high = mid;
	}
	return (low);
}

template <typename T> // std::deque / std::vect
void PmergeMe::sort(size_t lvl, T &main, std::vector<size_t> jacob){
	
	if (lvl > main.size() / 2)
		return ;
	swap(lvl,
		main);
	this->sort(lvl * 2, 
		main, 
		jacob);
	 
	T loser;
	T winner;
	T left;
	split(lvl, main, winner, loser, left);// fill loser, winner, leftover

	winner.insert(winner.begin(), loser.begin(), loser.begin() + lvl);

	for (size_t i = 0; i < jacob.size(); i++){
		size_t index = jacob[i];
		if (index >= (loser.size() / lvl))// index > num_pair_loserr
			continue;
		size_t los = loser[(index + 1) * lvl - 1];
		size_t pos = bs(winner,
			lvl,
			los,
			(index + 1) * lvl - 1);
		typename T::iterator end = loser.begin() + index * (lvl * 2);
		if ((index * (lvl * 2)) >= loser.size())
			end = loser.end();
		winner.insert(winner.begin() + pos * lvl, loser.begin() + index * lvl,end);
	}
	for (size_t i = 0; i < left.size() / lvl; i++){
		size_t los = left[(i + 1) * lvl - 1];
		size_t pos = bs(winner, lvl, los, winner.size() / lvl);
		winner.insert(winner.begin() + pos * lvl, left.begin() + i * lvl, left.begin() + (i + 1) * lvl);
	}
	main = winner;
}
