/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 00:05:06 by dcooray           #+#    #+#             */
/*   Updated: 2017/06/13 04:33:12 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	inter_cylinder(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
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
		mult_vect_real(tmp, obj->o_axis, e->tmp->m1);
		minus_vect(inter->norm, inter->norm, tmp);
		normalize(inter->norm);
		if (e->tmp->t2 < 0)
			neg_vect(inter->norm);
	}
	ft_memdel((void **)&tmp);
}

void	inter_cone(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
{
	t_inter	*inter;
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
		mult_vect_real(tmp, obj->o_axis, (1 + pow(obj->k, 2)) * e->tmp->m1);
		minus_vect(inter->norm, inter->norm, tmp);
		normalize(inter->norm);
		if (e->tmp->t2 < 0)
			neg_vect(inter->norm);
	}
	ft_memdel((void **)&tmp);
}
