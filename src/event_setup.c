/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:37:03 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:39:38 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	main_menu_setup(t_env *e)
{
	void	*opt;

	opt = e->win->win_opt;
	mlx_string_put(e->mlx, opt, 0, 0, 0xFFFFFF, "1 - Camera");
	mlx_string_put(e->mlx, opt, 0, 480 / 4, 0xFFFFFF, "2 - Object");
	mlx_string_put(e->mlx, opt, 0, 480 * 2 / 4, 0xFFFFFF, "3 - Light");
	mlx_string_put(e->mlx, opt, 0, 480 * 3 / 4, 0xFFFFFF, "Enter - Render");
	mlx_string_put(e->mlx, opt, 0, 480, 0xFFFFFF, "Esc key - Exit");
}

void	camera_menu_setup(t_env *e)
{
	void	*opt;

	opt = e->win->win_opt;
	mlx_string_put(e->mlx, opt, 225, 0, 0xFFFFFF, "Camera");
	mlx_string_put(e->mlx, opt, 0, 480 / 5, 0xFFFFFF, "1 - Origin");
	mlx_string_put(e->mlx, opt, 0, 480, 0xFFFFFF, "Esc key - Return");
}

void	object_menu_setup(t_env *e)
{
	void	*opt;
	char	*str;
	t_list	*list;
	t_obj	*obj;
	int		i;

	i = 0;
	list = e->list;
	while (list && i < e->c_o)
	{
		i++;
		list = list->next;
	}
	opt = e->win->win_opt;
	obj = (t_obj *)list->content;
	if (obj)
		str = ft_strjoin("Type object : ", obj->name);
	else
		str = ft_strjoin("Type object : ", "None");
	ol_menu_setup(&str, e->c_o, e->n_obj, "Object");
	object_menu_setup_bis(str, opt, e);
	ft_strdel(&str);
}

void	light_menu_setup(t_env *e)
{
	void	*opt;
	char	*str;
	t_list	*list;
	int		i;

	i = 0;
	list = e->light;
	while (list && i < e->c_l)
	{
		i++;
		list = list->next;
	}
	opt = e->win->win_opt;
	str = ft_strdup("");
	ol_menu_setup(&str, e->c_l, e->n_light, "Light");
	light_menu_setup_bis(str, opt, e);
	ft_strdel(&str);
}

void	terminal_menu_setup(t_env *e)
{
	void	*opt;
	char	*str;

	opt = e->win->win_opt;
	str = ft_strdup("Go to the terminal and change the values");
	mlx_string_put(e->mlx, opt, 0, 190, 0xFFFFFF, str);
	ft_strdel(&str);
	str = ft_strdup("Press Esc key before switching to the");
	mlx_string_put(e->mlx, opt, 0, 230, 0xFFFFFF, str);
	ft_strdel(&str);
	str = ft_strdup("terminal to cancel");
	mlx_string_put(e->mlx, opt, 0, 250, 0xFFFFFF, str);
	ft_strdel(&str);
}
