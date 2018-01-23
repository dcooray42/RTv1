/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:32:53 by dcooray           #+#    #+#             */
/*   Updated: 2017/06/15 05:16:12 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	key_hook_rt(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		delete_env(&e);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	red_cross(t_env *e)
{
	delete_env(&e);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook_setup(int keycode, t_env *e)
{
	if (keycode == 53 && !e->s1)
	{
		delete_env(&e);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 53 && e->s1)
	{
		e->s1 = 0;
		e->s2 = 0;
		mlx_clear_window(e->mlx, e->win->win_opt);
		main_menu_setup(e);
	}
	if (keycode == 83 && !e->s1)
	{
		e->s1 = 1;
		mlx_clear_window(e->mlx, e->win->win_opt);
		camera_menu_setup(e);
		return (0);
	}
	return (key_hook_setup_bis(keycode, e));
}

int	key_hook_setup_bis(int keycode, t_env *e)
{
	if (keycode == 84 && !e->s1 && e->n_obj)
	{
		e->s1 = 2;
		mlx_clear_window(e->mlx, e->win->win_opt);
		object_menu_setup(e);
		return (0);
	}
	if (keycode == 85 && !e->s1 && e->n_light)
	{
		e->s1 = 3;
		mlx_clear_window(e->mlx, e->win->win_opt);
		light_menu_setup(e);
		return (0);
	}
	if ((keycode == 36 || keycode == 76) && !e->s1)
	{
		mlx_clear_window(e->mlx, e->win->win);
		mlx_clear_window(e->mlx, e->win->win_opt);
		e->c_o = 0;
		e->c_l = 0;
		rt(e);
	}
	return (key_hook_setup_ter(keycode, e));
}

int	key_hook_setup_ter(int keycode, t_env *e)
{
	if (key_hook_camera(keycode, e))
		return (0);
	if (key_hook_object(keycode, e))
		return (0);
	if (key_hook_light(keycode, e))
		return (0);
	return (0);
}
