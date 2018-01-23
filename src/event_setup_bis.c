/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_setup_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:36:06 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:36:09 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ol_menu_setup(char **str, int i, int j, char *type)
{
	char	*tmp;

	if (!ft_strcmp("Object", type))
	{
		tmp = ft_strdup(" | ");
		*str = ft_strdeljoin(*str, tmp);
	}
	tmp = ft_strdup(type);
	*str = ft_strdeljoin(*str, tmp);
	tmp = ft_strdup(" #");
	*str = ft_strdeljoin(*str, tmp);
	tmp = ft_itoa(i + 1);
	*str = ft_strdeljoin(*str, tmp);
	tmp = ft_strdup(" / ");
	*str = ft_strdeljoin(*str, tmp);
	tmp = ft_itoa(j);
	*str = ft_strdeljoin(*str, tmp);
}

void	object_menu_setup_bis(char *str, void *opt, t_env *e)
{
	mlx_string_put(e->mlx, opt, 220, 0, 0xFFFFFF, "Object");
	mlx_string_put(e->mlx, opt, 0, 480 / 6, 0xFFFFFF, str);
	mlx_string_put(e->mlx, opt, 0, 480 * 2 / 6, 0xFFFFFF, "+ - Change object");
	mlx_string_put(e->mlx, opt, 0, 480 * 3 / 6, 0xFFFFFF, "- - Change object");
	mlx_string_put(e->mlx, opt, 0, 480 * 4 / 6, 0xFFFFFF, "1 - Origin");
	mlx_string_put(e->mlx, opt, 0, 480 * 5 / 6, 0xFFFFFF, "2 - Rotation");
	mlx_string_put(e->mlx, opt, 0, 480, 0xFFFFFF, "Esc key - Return");
}

void	light_menu_setup_bis(char *str, void *opt, t_env *e)
{
	mlx_string_put(e->mlx, opt, 225, 0, 0xFFFFFF, "Light");
	mlx_string_put(e->mlx, opt, 0, 480 / 5, 0xFFFFFF, str);
	mlx_string_put(e->mlx, opt, 0, 480 * 2 / 5, 0xFFFFFF, "+ - Change object");
	mlx_string_put(e->mlx, opt, 0, 480 * 3 / 5, 0xFFFFFF, "- - Change object");
	mlx_string_put(e->mlx, opt, 0, 480 * 4 / 5, 0xFFFFFF, "1 - Origin");
	mlx_string_put(e->mlx, opt, 0, 480, 0xFFFFFF, "Esc key - Exit");
}
