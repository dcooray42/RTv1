/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:34:34 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:34:39 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	key_hook_camera(int keycode, t_env *e)
{
	if (keycode == 83 && e->s1 == 1)
	{
		e->s2 = 1;
		mlx_clear_window(e->mlx, e->win->win_opt);
		terminal_menu_setup(e);
		return (1);
	}
	if (e->s1 == 1 && e->s2 == 1)
	{
		init_vect(e->cam->ori, 0.0, 0.0, 0.0);
		while (!e->cam->ori->x && !e->cam->ori->y && !e->cam->ori->z)
		{
			e->cam->ori->x = change_value("cam->x", e);
			e->cam->ori->y = change_value("cam->y", e);
			e->cam->ori->z = change_value("cam->z", e);
			if (!e->cam->ori->x && !e->cam->ori->y && !e->cam->ori->z)
				ft_printf("Camera coordinates can't be (0, 0, 0)\n");
		}
		e->s2 = 0;
		mlx_clear_window(e->mlx, e->win->win_opt);
		camera_menu_setup(e);
	}
	return (0);
}
