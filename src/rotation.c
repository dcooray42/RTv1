/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:37:38 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:38:33 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotation(t_env *e)
{
	t_list	*list;
	t_obj	*obj;
	double	x;
	double	y;
	double	z;

	list = e->list;
	while (list)
	{
		obj = (t_obj *)list->content;
		if (ft_strcmp(obj->name, "Sphere"))
		{
			x = obj->c->rot_x;
			y = obj->c->rot_y;
			z = obj->c->rot_z;
			rotation_bis(x, y, z, obj);
			normalize(obj->o_axis);
		}
		list = list->next;
	}
}

void	rotation_bis(double x, double y, double z, t_obj *obj)
{
	double	xp;
	double	yp;
	double	zp;
	double	tmp1;
	double	tmp2;

	tmp1 = ((90 - 10e-4) * M_PI) / 180;
	tmp2 = ((90 + 10e-4) * M_PI) / 180;
	xp = rotation_ter(x, tmp1, tmp2);
	yp = rotation_ter(y, tmp1, tmp2);
	zp = rotation_ter(z, tmp1, tmp2);
	obj->o_axis->x = -sin(z) * xp + zp * sin(y) * sin(x);
	obj->o_axis->y = zp * xp + sin(z) * sin(y) * sin(x);
	obj->o_axis->z = yp * sin(x);
}

double	rotation_ter(double e, double tmp1, double tmp2)
{
	double	r;
	double	tmp3;
	double	tmp4;

	tmp3 = ((-90 - 10e-4) * M_PI) / 180;
	tmp4 = ((-90 + 10e-4) * M_PI) / 180;
	if ((e > tmp1 && e < tmp2) || (e > tmp3 && e < tmp4))
		r = 0;
	else
		r = cos(e);
	return (r);
}
