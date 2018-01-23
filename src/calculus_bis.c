/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:33:48 by dcooray           #+#    #+#             */
/*   Updated: 2017/05/30 03:33:29 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	mult_vect_real(t_vect *rslt, t_vect *i, double n)
{
	rslt->x = i->x * n;
	rslt->y = i->y * n;
	rslt->z = i->z * n;
}

void	div_vect_real(t_vect *rslt, t_vect *i, double n)
{
	if (n)
	{
		if (i->x)
			rslt->x = i->x / n;
		if (i->y)
			rslt->y = i->y / n;
		if (i->z)
			rslt->z = i->z / n;
	}
}

double	dot_product(t_vect *i, t_vect *j)
{
	double	n;

	n = i->x * j->x + i->y * j->y + i->z * j->z;
	return (n);
}

void	normalize(t_vect *i)
{
	double	norm;

	norm = sqrt(i->x * i->x + i->y * i->y + i->z * i->z);
	if (i->x)
		i->x /= norm;
	if (i->y)
		i->y /= norm;
	if (i->z)
		i->z /= norm;
}

void	neg_vect(t_vect *i)
{
	i->x *= -1;
	i->y *= -1;
	i->z *= -1;
}
