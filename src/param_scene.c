/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:35:24 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:15:36 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_win	*init_screen(t_env **e)
{
	t_win	*win;

	if ((win = (t_win *)ft_memalloc(sizeof(t_win))) == NULL)
		malloc_error(e);
	win->win = NULL;
	win->win_opt = NULL;
	win->img = NULL;
	win->data = NULL;
	win->width = 0;
	win->height = 0;
	win->tmp = 0;
	return (win);
}

void	name_prog(char *line, t_env **e)
{
	char	*str;
	int		i;

	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{' && !(*e)->name)
		line++;
	else
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	str = line;
	i = 0;
	while (!ft_isspace(*str) && *str != '}' && *str != '\0')
	{
		i++;
		str++;
	}
	if (!((*e)->name = ft_strsub(line, 0, i)))
		malloc_error(e);
	line += i;
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line != '}')
		syntax_error(e);
}

void	screen_size(char *line, t_env **e)
{
	char	*str;
	int		i;

	if (!(*e)->win)
		(*e)->win = init_screen(e);
	else if (!(*e)->win->width)
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{')
		line++;
	else if (!(*e)->win->width)
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	str = line;
	i = 0;
	while (!ft_isspace(*str) && *str != '\0')
	{
		i++;
		str++;
	}
	screen_size_bis(line, i, e);
}

void	screen_size_bis(char *line, int i, t_env **e)
{
	if (!(*e)->win->width)
	{
		(*e)->win->width = ft_atoi(line);
		line += i;
		screen_size(line, e);
		if (!(*e)->win->height)
			syntax_error(e);
		return ;
	}
	else
	{
		(*e)->win->height = ft_atoi(line);
		line += i;
	}
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line != '}')
		syntax_error(e);
}
