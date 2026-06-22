/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:12:44 by tseche            #+#    #+#             */
/*   Updated: 2026/06/22 14:47:06 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

struct s_table{
	bool	i;
	bool	f;
	bool	d;
	bool	c;
};

struct repr_table
{
	std::string	*i;
	std::string	*f;
	std::string	*d;
	std::string	*c;
};


enum state{
	bpoint,
	apoint,
	point,
	other,
};

struct data{
	int point;
	std::string::iterator repr;
	i_table	table;
	bool	f;
	f_table	*state_table;
	repr_table repr;
	std::string end;
};

typedef void (* func)(data *);

struct f_table{
	state	id;
	func callback; 
};

using i_table = s_table;

// --------------[LOGIC]------------------ \\

data	*init_data(int point,
	std::string::iterator repr,
	i_table	table,
	bool	f,
	f_table	*state_table,
	std::string &s)
{
	data	*d = new data;
	d->f = f;
	d->point = point;
	d->repr = repr;
	d->state_table = state_table;
	d->table = table;
	d->end = s;
	return (d);
}


void	fbpoint(data *d)
{
	
}

void fapoint(data *d)
{
	
}

void	fpoint(data *d)
{
	d->table.i = false;
	d->table.c = false;
}

void fother(data *d)
{
	
}


struct closure{
	func operator()(int i){
		if (i == 0)
			return fbpoint;
		else if (i == 1)
			return fapoint;
		else if (i == 2)
			return fpoint;
		else
			return fother;
	};
};

void	ass_state_table(data *d)
{
	closure c;
	for (int i = 0; i < 4; i++)
	{
		d->state_table[i] = {
			.id = (state)i,
			.callback = c(i),
		};
	}
}

func change_state(data *d)
{
	if (std::isdigit(*d->repr) && d->point)
		return fapoint;
	else if (std::isdigit(*d->repr))
		return (fbpoint);
	else if ((*d->repr) == '.')
		return (fpoint);
	else
		return (fother);
}

void	print(data *d)
{
	
}

void ScalarConverter::convert(std::string &s)
{
	static	int		point =  0;
	static	auto	repr = s.end();
	static	i_table table = {.i = true, .f = true, .d = true, .c = true};
	static	bool	f = true;
	static	f_table	*state_table = new f_table[4];
	data	*d;

	if (repr == s.end())
	{
		d = init_data(point, repr, table, f, state_table, s);
		ass_state_table(d);
	}
	else if (repr == s.begin())
	{
		print(d);
		return ;
	}
	(change_state(d))(d);
	std::string nstr = std::string(d->end.begin(), d->repr);
	convert(nstr);
}