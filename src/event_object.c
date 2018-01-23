/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:35:48 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:35:49 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_hook_object(int keycode, t_env *e)
{
	if (keycode == 69 && e->s1 == 2)
	{
		if (e->c_o < e->n_obj - 1)
			e->c_o++;
		mlx_clear_window(e->mlx, e->win->win_opt);
		object_menu_setup(e);
	}
	if (keycode == 78 && e->s1 == 2)
	{
		if (e->c_o > 0)
			e->c_o--;
		mlx_clear_window(e->mlx, e->win->win_opt);
		object_menu_setup(e);
	}
	if (keycode == 83 && e->s1 == 2)
	{
		e->s2 = 1;
		mlx_clear_window(e->mlx, e->win->win_opt);
		terminal_menu_setup(e);
		return (1);
	}
	return (key_hook_object_bis(keycode, e));
}

int		key_hook_object_bis(int keycode, t_env *e)
{
	if (keycode == 84 && e->s1 == 2)
	{
		e->s2 = 2;
		mlx_clear_window(e->mlx, e->win->win_opt);
		terminal_menu_setup(e);
		return (1);
	}
	key_hook_object_ori(e);
	key_hook_object_rot(e);
	return (0);
}

void	key_hook_object_ori(t_env *e)
{
	t_list	*list;
	t_obj	*obj;
	int		i;

	if (e->s1 == 2 && e->s2 == 1)
	{
		i = 0;
		list = e->list;
		while (list && i < e->c_o)
		{
			i++;
			list = list->next;
		}
		obj = (t_obj *)list->content;
		obj->c->ori->x = change_value("obj->ori->x", e);
		obj->c->ori->y = change_value("obj->ori->y", e);
		obj->c->ori->z = change_value("obj->ori->z", e);
		e->s2 = 0;
		mlx_clear_window(e->mlx, e->win->win_opt);
		object_menu_setup(e);
	}
}

void	key_hook_object_rot(t_env *e)
{
	t_list	*list;
	t_obj	*obj;
	int		i;

	if (e->s1 == 2 && e->s2 == 2)
	{
		i = 0;
		list = e->list;
		while (list && i++ < e->c_o)
			list = list->next;
		obj = (t_obj *)list->content;
		if (ft_strcmp(obj->name, "Sphere"))
		{
			obj->c->rot_x = (change_value("obj->rot->x", e) * M_PI) / 180;
			obj->c->rot_y = (change_value("obj->rot->y", e) * M_PI) / 180;
			obj->c->rot_z = (change_value("obj->rot->z", e) * M_PI) / 180;
		}
		else
			ft_printf("A sphere can't be rotated\n");
		e->s2 = 0;
		mlx_clear_window(e->mlx, e->win->win_opt);
		object_menu_setup(e);
	}
}
