/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:32:36 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:17:05 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_pos	*init_pos(t_env **e)
{
	t_pos	*cam;

	if ((cam = (t_pos *)ft_memalloc(sizeof(t_pos))) == NULL)
		malloc_error(e);
	cam->ori = create_vect(*e);
	cam->ori->x = 0.0;
	cam->ori->y = 0.0;
	cam->ori->z = 0.0;
	cam->rot_x = 0.0;
	cam->rot_y = 0.0;
	cam->rot_z = 0.0;
	cam->fov = M_PI_2;
	return (cam);
}

void	camera_settings(char *line, t_env **e)
{
	if ((*e)->status == 1)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (*line == '{')
		{
			line++;
			if (!(*e)->cam)
				(*e)->cam = init_pos(e);
			else
				syntax_error(e);
			(*e)->status = 2;
		}
		else
			syntax_error(e);
	}
	if ((*e)->status == 2)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (camera_option(line, e))
			return ;
		else
			syntax_error(e);
	}
}

int		camera_option(char *line, t_env **e)
{
	if (!ft_memcmp(line, "Origin", 6))
	{
		line += 6;
		camera_origin_coordinates(line, 1, e);
		return (1);
	}
	else if (!ft_memcmp(line, "Rotation_xyz", 12))
	{
		line += 12;
		camera_rotation(line, 1, e);
		return (1);
	}
	else if (!ft_memcmp(line, "Fov", 3))
	{
		line += 3;
		camera_fov(line, e);
		return (1);
	}
	return (camera_option_bis(line, e));
}

int		camera_option_bis(char *line, t_env **e)
{
	if (*line == '}')
	{
		(*e)->status = 1;
		return (1);
	}
	else if (*line == '\0')
		return (1);
	else
		return (0);
}

void	camera_fov(char *line, t_env **e)
{
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{')
		line++;
	else
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	(*e)->cam->fov = ft_atoif(line);
	while (!ft_isspace(*line) && *line != '}' && *line != '\0')
		line++;
	object_ori_rot_final(line, e);
}
