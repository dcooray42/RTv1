/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:35:43 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/19 17:47:06 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_first_inter(t_inter *inter, t_vect *ori, t_vect *dir, t_env *e)
{
	t_obj	*obj;
	t_list	*list;

	list = e->list;
	while (list)
	{
		obj = (t_obj *)list->content;
		if (!ft_strcmp(obj->name, "Sphere"))
		{
			if (draw_sphere(ori, dir, obj, e))
				inter_sphere(ori, dir, obj, e);
		}
		else if (!ft_strcmp(obj->name, "Plane"))
		{
			if (draw_plane(ori, dir, obj))
				inter_plane(ori, dir, obj, e);
		}
		get_first_inter_bis(ori, dir, obj, e);
		list = list->next;
	}
	if (inter->t)
		return (1);
	else
		return (0);
}

void	get_first_inter_bis(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
{
	if (!ft_strcmp(obj->name, "Cylinder"))
	{
		if (draw_cylinder(ori, dir, obj, e))
			inter_cylinder(ori, dir, obj, e);
	}
	else if (!ft_strcmp(obj->name, "Cone"))
	{
		if (draw_cone(ori, dir, obj, e))
			inter_cone(ori, dir, obj, e);
	}
}

int		intersection(t_vect *ori, t_vect *dir, t_env *e)
{
	t_obj	*obj;
	t_list	*list;
	int		i;

	list = e->list;
	i = 0;
	while (list)
	{
		obj = (t_obj *)list->content;
		if (!i)
			i = intersection_bis(ori, dir, obj, e);
		list = list->next;
	}
	return (i);
}

int		intersection_bis(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
{
	if (!ft_strcmp(obj->name, "Sphere"))
	{
		if (draw_sphere(ori, dir, obj, e))
		{
			mult_vect_real(e->tmp->tmp_vect_bis, dir, obj->t);
			if (vect_length(e->tmp->tmp_vect_bis) <= e->tmp->length)
				return (1);
		}
	}
	else if (!ft_strcmp(obj->name, "Plane"))
	{
		if (draw_plane(ori, dir, obj))
		{
			mult_vect_real(e->tmp->tmp_vect_bis, dir, obj->t);
			if (vect_length(e->tmp->tmp_vect_bis) <= e->tmp->length)
				return (1);
		}
	}
	return (intersection_ter(ori, dir, obj, e));
}

int		intersection_ter(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e)
{
	if (!ft_strcmp(obj->name, "Cylinder"))
	{
		if (draw_cylinder(ori, dir, obj, e))
		{
			mult_vect_real(e->tmp->tmp_vect_bis, dir, obj->t);
			if (vect_length(e->tmp->tmp_vect_bis) <= e->tmp->length)
				return (1);
		}
	}
	else if (!ft_strcmp(obj->name, "Cone"))
	{
		if (draw_cone(ori, dir, obj, e))
		{
			mult_vect_real(e->tmp->tmp_vect_bis, dir, obj->t);
			if (vect_length(e->tmp->tmp_vect_bis) <= e->tmp->length)
				return (1);
		}
	}
	return (0);
}
