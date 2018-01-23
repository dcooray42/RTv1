/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:56:27 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:26:52 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_light(t_env **e)
{
	t_light	*light;
	t_list	*tmp;

	if ((light = (t_light *)ft_memalloc(sizeof(t_light))) == NULL)
		malloc_error(e);
	light->clr = create_color(*e);
	light->ori = create_vect(*e);
	light->dir = create_vect(*e);
	light->clr->r = 255;
	light->clr->g = 255;
	light->clr->b = 255;
	if ((tmp = ft_lstnew(light, sizeof(t_light))) == NULL)
		malloc_error(e);
	ft_lstadd(&(*e)->light, tmp);
	ft_memdel((void **)&light);
}

void	light_settings(char *line, t_env **e)
{
	if ((*e)->status == 1)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (*line == '{')
		{
			line++;
			(*e)->status = 4;
		}
		else
			syntax_error(e);
	}
	if ((*e)->status == 4)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (light_option(line, e))
			return ;
		else
			syntax_error(e);
	}
}

int		light_option(char *line, t_env **e)
{
	if (!ft_memcmp(line, "Origin", 6))
	{
		line += 6;
		light_origin_coordinates(line, 1, e);
		return (1);
	}
	else if (!ft_memcmp(line, "Color", 5))
	{
		line += 5;
		light_color(line, 1, e);
		return (1);
	}
	else if (*line == '}')
	{
		(*e)->status = 1;
		return (1);
	}
	else if (*line != '\0')
		return (1);
	else
		return (0);
}

void	light_origin_coordinates(char *line, int i, t_env **e)
{
	char	*str;
	int		j;

	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{')
		line++;
	else if (i == 1)
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	str = line;
	j = 0;
	while (!ft_isspace(*str) && *str != '}' && *str != '\0')
	{
		j++;
		str++;
	}
	light_origin_coordinates_bis(line, i, j, e);
}

void	light_origin_coordinates_bis(char *line, int i, int j, t_env **e)
{
	t_light	*light;

	light = (t_light *)(*e)->light->content;
	if (i == 1)
	{
		light->ori->x = ft_atoif(line);
		line += j;
		light_origin_coordinates(line, 2, e);
		return ;
	}
	if (i == 2)
	{
		light->ori->y = ft_atoif(line);
		line += j;
		light_origin_coordinates(line, 3, e);
		return ;
	}
	if (i == 3)
	{
		light->ori->z = ft_atoif(line);
		line += j;
	}
	object_ori_rot_final(line, e);
}
