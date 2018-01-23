/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:33:16 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:18:06 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	camera_origin_coordinates(char *line, int i, t_env **e)
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
	camera_origin_coordinates_bis(line, i, j, e);
}

void	camera_origin_coordinates_bis(char *line, int i, int j, t_env **e)
{
	if (i == 1)
	{
		(*e)->cam->ori->x = ft_atoif(line);
		line += j;
		camera_origin_coordinates(line, 2, e);
		return ;
	}
	if (i == 2)
	{
		(*e)->cam->ori->y = ft_atoif(line);
		line += j;
		camera_origin_coordinates(line, 3, e);
		return ;
	}
	if (i == 3)
	{
		(*e)->cam->ori->z = ft_atoif(line);
		line += j;
	}
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line != '}')
		syntax_error(e);
}

void	camera_rotation(char *line, int i, t_env **e)
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
	camera_rotation_bis(line, i, j, e);
}

void	camera_rotation_bis(char *line, int i, int j, t_env **e)
{
	if (i == 1)
	{
		(*e)->cam->rot_x = ((double)ft_atoi(line) * M_PI) / 180;
		line += j;
		camera_rotation(line, 2, e);
		return ;
	}
	if (i == 2)
	{
		(*e)->cam->rot_y = ((double)ft_atoi(line) * M_PI) / 180;
		line += j;
		camera_rotation(line, 3, e);
		return ;
	}
	if (i == 3)
	{
		(*e)->cam->rot_z = ((double)ft_atoi(line) * M_PI) / 180;
		line += j;
	}
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line != '}')
		syntax_error(e);
}
