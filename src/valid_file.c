/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:37:24 by dcooray           #+#    #+#             */
/*   Updated: 2017/06/13 04:48:47 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	valid_file(t_env **e)
{
	t_list	*list;
	t_obj	*obj;

	if (!(*e))
		syntax_error(NULL);
	else
	{
		valid_file_bis(e);
		list = (*e)->list;
		while (list)
		{
			obj = (t_obj *)list->content;
			valid_object_param(obj, e);
			list = list->next;
		}
	}
}

void	valid_file_bis(t_env **e)
{
	if (!(*e)->name)
		syntax_error(e);
	if (!(*e)->win)
		syntax_error(e);
	if ((*e)->win->width <= 0 || (*e)->win->height <= 0)
		syntax_error(e);
	if (!(*e)->cam)
		syntax_error(e);
	if ((*e)->cam->fov <= 0 || (!(*e)->cam->ori->x && !(*e)->cam->ori->y
		&& !(*e)->cam->ori->z))
		syntax_error(e);
}

void	valid_object_param(t_obj *obj, t_env **e)
{
	if (!obj->name || !obj->c)
		syntax_error(e);
	if (!(ft_strcmp(obj->name, "Sphere")))
		if (obj->rayon <= 0)
			syntax_error(e);
	if (!(ft_strcmp(obj->name, "Plane")))
		if (!obj->o_axis)
			syntax_error(e);
	if (!(ft_strcmp(obj->name, "Cylinder")))
		if (obj->rayon <= 0 || !obj->o_axis)
			syntax_error(e);
	if (!(ft_strcmp(obj->name, "Cone")))
		if (obj->k <= 0 || obj->k >= tan(((180.0 * M_PI) / 180) / 2) ||
			!obj->o_axis)
			syntax_error(e);
}
