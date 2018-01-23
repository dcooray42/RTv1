/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:53:34 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:40:09 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	draw_cone(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
{
	minus_vect(obj->origintoobj, ori, obj->c->ori);
	obj->abc->x = dot_product(dir, dir)
		- (1 + pow(obj->k, 2))
		* pow(dot_product(dir, obj->o_axis), 2.0);
	obj->abc->y = dot_product(dir, obj->origintoobj)
		- (1 + pow(obj->k, 2)) * (dot_product(dir, obj->o_axis)
				* dot_product(obj->origintoobj, obj->o_axis));
	obj->abc->z = dot_product(obj->origintoobj, obj->origintoobj)
		- (1 + pow(obj->k, 2))
		* pow(dot_product(obj->origintoobj, obj->o_axis), 2.0);
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
