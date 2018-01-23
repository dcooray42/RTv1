/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:45:29 by dcooray           #+#    #+#             */
/*   Updated: 2017/06/26 21:18:42 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		draw_plane(t_vect *ori, t_vect *dir, t_obj *obj)
{
	double	tmp;

	minus_vect(obj->origintoobj, ori, obj->c->ori);
	tmp = dot_product(dir, obj->o_axis);
	if (tmp > 0)
	{
		neg_vect(obj->o_axis);
		tmp = dot_product(dir, obj->o_axis);
	}
	if (tmp)
	{
		obj->t = -dot_product(obj->origintoobj, obj->o_axis) / tmp;
		if (obj->t > 0)
			return (1);
	}
	return (0);
}

void	inter_plane(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
{
	t_inter *inter;
	t_vect	*tmp;

	inter = (t_inter *)e->inter->content;
	tmp = create_vect(e);
	if (!inter->t || inter->t > obj->t)
	{
		inter->t = obj->t;
		inter->clr->r = obj->clr->r;
		inter->clr->g = obj->clr->g;
		inter->clr->b = obj->clr->b;
		mult_vect_real(tmp, dir, obj->t);
		add_vect(inter->point, ori, tmp);
		init_vect(inter->norm, obj->o_axis->x, obj->o_axis->y, obj->o_axis->z);
	}
	ft_memdel((void **)&tmp);
}
