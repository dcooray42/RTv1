/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:48:02 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:40:22 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	draw_cylinder(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
{
	minus_vect(obj->origintoobj, ori, obj->c->ori);
	obj->abc->x = dot_product(dir, dir)
		- pow(dot_product(dir, obj->o_axis), 2.0);
	obj->abc->y = (dot_product(dir, obj->origintoobj)
		- (dot_product(dir, obj->o_axis)
				* dot_product(obj->origintoobj, obj->o_axis)));
	obj->abc->z = dot_product(obj->origintoobj, obj->origintoobj)
		- pow(dot_product(obj->origintoobj, obj->o_axis), 2.0)
		- obj->rayon * obj->rayon;
	e->tmp->det = (obj->abc->y * obj->abc->y) - obj->abc->x * obj->abc->z;
	if (e->tmp->det >= 0)
	{
		e->tmp->t1 = (-obj->abc->y - sqrt(e->tmp->det)) / obj->abc->x;
		e->tmp->t2 = (-obj->abc->y + sqrt(e->tmp->det)) / obj->abc->x;
		if (e->tmp->t2 > 0 && (e->tmp->t1 > e->tmp->t2 || (e->tmp->t1 < 0 &&
						e->tmp->t1 < e->tmp->t2)))
		{
			e->tmp->tmp = e->tmp->t1;
			e->tmp->t1 = e->tmp->t2;
			e->tmp->t2 = e->tmp->tmp;
		}
		return (draw_cc(dir, obj, e));
	}
	return (0);
}

int	draw_cc(t_vect *dir, t_obj *obj, t_env *e)
{
	e->tmp->m1 = dot_product(dir, obj->o_axis) * e->tmp->t1
		+ dot_product(obj->origintoobj, obj->o_axis);
	if (e->tmp->t1 > 0)
	{
		obj->t = e->tmp->t1;
		return (1);
	}
	return (0);
}
