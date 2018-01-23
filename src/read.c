/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:35:42 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/26 21:49:53 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_env	*init_env(void)
{
	t_env	*e;

	if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		malloc_error(NULL);
	e->name = NULL;
	e->status = 0;
	e->status_tmp = 0;
	e->mlx = NULL;
	e->win = NULL;
	e->cam = NULL;
	e->x = 0;
	e->y = 0;
	e->s1 = 0;
	e->s2 = 0;
	e->c_o = 0;
	e->c_l = 0;
	e->n_obj = 0;
	e->n_light = 0;
	e->list = NULL;
	e->light = NULL;
	e->inter = NULL;
	e->scene = NULL;
	e->tmp = init_tmp(e);
	return (e);
}

void	read_line(t_env **e, char *line)
{
	if (*line == '#' || *line == '\0')
		return ;
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (!ft_memcmp(line, "Scene", 5))
	{
		line += 5;
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (!(*e) && *line == '{')
		{
			*e = init_env();
			(*e)->status = 1;
			(*e)->status_tmp = 1;
			line++;
		}
		else
			syntax_error(e);
	}
	if (!(*e))
		syntax_error(e);
	read_line_bis(e, line);
}

void	read_line_bis(t_env **e, char *line)
{
	if ((*e)->status)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (check_param(line, e))
			return ;
		else
			syntax_error(e);
	}
	if ((*e)->status_tmp && !(*e)->status)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (*line == '\0')
			return ;
		else
			syntax_error(e);
	}
}

int		check_param(char *line, t_env **e)
{
	if (!ft_memcmp(line, "Name", 4) && (*e)->status == 1)
	{
		line += 4;
		name_prog(line, e);
		return (1);
	}
	if (!ft_memcmp(line, "Render", 6) && (*e)->status == 1)
	{
		line += 6;
		screen_size(line, e);
		return (1);
	}
	if (!ft_memcmp(line, "Camera", 6) || (*e)->status == 2)
	{
		if ((*e)->status != 2)
			line += 6;
		camera_settings(line, e);
		return (1);
	}
	return (check_param_bis(line, e));
}

void	read_file(char *argv, t_env **e)
{
	int		ret;
	int		fd;
	char	*line;

	line = NULL;
	ret = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		basic_error(argv, e);
	while (get_next_line(fd, &line) > 0)
	{
		ret = 1;
		read_line(e, line);
		ft_strdel(&line);
	}
	if (close(fd) == -1 || errno == EISDIR)
		basic_error(argv, e);
	if (!ret)
		empty_file(e);
	if (*e)
		if ((*e)->status)
			syntax_error(e);
	valid_file(e);
}
