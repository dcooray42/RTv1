/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:33:40 by dcooray           #+#    #+#             */
/*   Updated: 2017/05/25 09:33:43 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*create_vect(t_env *e)
{
	t_vect	*ret;

	if ((ret = (t_vect *)ft_memalloc(sizeof(t_vect))) == NULL)
		syntax_error(&e);
	ret->x = 0.0;
	ret->y = 0.0;
	ret->z = 0.0;
	return (ret);
}

void	init_vect(t_vect *vect, double x, double y, double z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

void	add_vect(t_vect *rslt, t_vect *i, t_vect *j)
{
	rslt->x = i->x + j->x;
	rslt->y = i->y + j->y;
	rslt->z = i->z + j->z;
}

void	minus_vect(t_vect *rslt, t_vect *i, t_vect *j)
{
	rslt->x = i->x - j->x;
	rslt->y = i->y - j->y;
	rslt->z = i->z - j->z;
}

void	cross_product(t_vect *rslt, t_vect *i, t_vect *j)
{
	rslt->x = (i->y * j->z) - (i->z * j->y);
	rslt->y = (i->z * j->x) - (i->x * j->z);
	rslt->z = (i->x * j->y) - (i->y * j->x);
}
