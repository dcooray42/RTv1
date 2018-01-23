/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:43:47 by dcooray           #+#    #+#             */
/*   Updated: 2017/06/26 21:27:13 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		draw_sphere(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
{
	minus_vect(obj->origintoobj, ori, obj->c->ori);
	obj->abc->y = dot_product(dir, obj->origintoobj);
	obj->abc->z = dot_product(obj->origintoobj, obj->origintoobj)
		- (obj->rayon * obj->rayon);
	e->tmp->det = (obj->abc->y * obj->abc->y) - obj->abc->z;
	if (e->tmp->det >= 0)
	{
		e->tmp->t1 = -obj->abc->y - sqrt(e->tmp->det);
		e->tmp->t2 = -obj->abc->y + sqrt(e->tmp->det);
		if (e->tmp->t2 > 0 && (e->tmp->t1 > e->tmp->t2 || (e->tmp->t1 < 0 &&
						e->tmp->t1 < e->tmp->t2)))
		{
			e->tmp->tmp = e->tmp->t1;
			e->tmp->t1 = e->tmp->t2;
			e->tmp->t2 = e->tmp->tmp;
		}
		obj->t = e->tmp->t1;
		if (obj->t > 0)
			return (1);
	}
	return (0);
}

void	inter_sphere(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
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
		minus_vect(inter->norm, inter->point, obj->c->ori);
		normalize(inter->norm);
		if (e->tmp->t2 < 0)
			neg_vect(inter->norm);
	}
	ft_memdel((void **)&tmp);
}
