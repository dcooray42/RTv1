/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:35:04 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:36:38 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_hook_light(int keycode, t_env *e)
{
	if (keycode == 69 && e->s1 == 3)
	{
		if (e->c_l < e->n_light - 1)
			e->c_l++;
		mlx_clear_window(e->mlx, e->win->win_opt);
		light_menu_setup(e);
	}
	if (keycode == 78 && e->s1 == 3)
	{
		if (e->c_l > 0)
			e->c_l--;
		mlx_clear_window(e->mlx, e->win->win_opt);
		light_menu_setup(e);
	}
	if (keycode == 83 && e->s1 == 3)
	{
		e->s2 = 1;
		mlx_clear_window(e->mlx, e->win->win_opt);
		terminal_menu_setup(e);
		return (1);
	}
	key_hook_light_ori(e);
	return (0);
}

void	key_hook_light_ori(t_env *e)
{
	t_list	*list;
	t_light	*light;
	int		i;

	if (e->s1 == 3 && e->s2 == 1)
	{
		i = 0;
		list = e->light;
		while (list && i < e->c_l)
		{
			i++;
			list = list->next;
		}
		light = (t_light *)list->content;
		light->ori->x = change_value("light->ori->x", e);
		light->ori->y = change_value("light->ori->y", e);
		light->ori->z = change_value("light->ori->z", e);
		e->s2 = 0;
		mlx_clear_window(e->mlx, e->win->win_opt);
		light_menu_setup(e);
	}
}
